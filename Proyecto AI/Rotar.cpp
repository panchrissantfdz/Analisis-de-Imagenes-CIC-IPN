//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include <math.h>
#include "histograma.h"
#include "ensancharH.h"
#include "operacionesAL.h"
#include "binariza.h"
#include "normalizar.h"
#include "letras.h"
#include "generamascara.h"
#include "morfologia.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormaPrincipal *FormaPrincipal;
String Nombre;

//---------------------------------------------------------------------------


				//***************************************************************
				//****************  IMPLEMENTACIONDE LA CLASE MASCARA ***********
				//***************************************************************

		//****************  CONSTRUCTORES DE LA CLASE MASCARA ****************

mascara::mascara( int x=3 , int y=3 , ... )
{
 va_list p ;
 sx = x ;
 sy = y ;
 Gx = new int *[ x ] ;        	//Reserva memoria para la mascara
 for( int k = 0 ; k < x ; k++ )
  Gx[ k ] = new int [ y ] ;     //***
 va_start( p , y ) ;
 for( int j = 0 ; j < y ; j++ )
  for( int i = 0 ; i < x ; i++ )
	{
	 int ps = va_arg( p , int ) ;
	 Gx[i][j] =  ps ;
	}
 va_end( p ) ;
}


// Recibe 2 enteros de la posición del pixel a filtrar
// y NO SE DEFINIO la  máscara por el usuario
// Utiliza la máscara default
int mascara::filtra ( int x , int y, int SegundaDerivada=0 ) //sirve para filtros del tipo  (1/n)*Smt
{ int i , j , w = 0 , cuantos = 0 , colorHex=0;

 for ( i = 0 ; i < sx ; i++ )    //itera en el tamaño size x de la mascara
  for ( j = 0 ; j < sy ; j++ )   //itera en el tamaño size y de la mascara
	if( Gx[i][j] != 999 )
	 {   //Extracción de nivel de gris
           colorHex=FormaPrincipal->imgbmp[x + j - 1 ][y + i - 1]; //******** verif xy ó yx
           w += Gx[i][j] * colorHex;
	  cuantos ++ ;  //Cuenta cuántos pixeles tiene la máscara en operación
	 }
  //Armado del número hexadecimal RGB, con R=G=B para obtener el tono de gris deseado
     //if(!SegundaDerivada)  //si no es de segunda derivada, se divide
         w = (int)(w /cuantos ) /*+ 0.5 */ ;
      //sino solo se devuelve la suma

  return w;

}

mascara& mascara::operator =(const mascara &Masc)
{int i,j;
  sx = Masc.sx ;
  sy = Masc.sy ;

  Gx = new int *[ sy ] ;
  for( j = 0 ; j < sy ; j++ )
	Gx[j] = new int [ sx ] ;
  for ( j = 0 ; j < sy ; j++ )
	for ( i = 0 ; i < sx ; i++ )
	  Gx[i][j] =Masc.Gx[i][j] ;

   return *this;
}

extern mascara Mp( 3 , 3 ,
						 -1 , -2 , -1 ,
						  0 ,  0 ,  0 ,
						  1 ,  2 ,  1 ) ;
//****************  CREACION de 4 Vaiables FILTROS de mascara   (Mid, Mprom, Malta y Mbaja) **************************
//que utilizan el constructor   mascara( int SX=3 , int SY=3 , ... )
//recibe 2 enteros x e y para el tamaño de la máscara y la propia máscara como listade parámetros
// en este caso son máscaras de 3x3

mascara Mprom ( 3 , 3 ,
					 1 , 1 , 1 ,
					 1 , 1 , 1 ,
					 1 , 1 , 1 ) ;
mascara Malta ( 3 , 3 ,
					 -1 ,    -1 ,    -1 ,
					 -1 , FAC_AMPL , -1 ,
					 -1 ,    -1 ,    -1 ) ;
mascara HBoot ( 3 , 3 ,
					 -1 ,    -1 ,    -1 ,
					 -1 , (1.7+8) , -1 ,
					 -1 ,    -1 ,    -1 ) ;

mascara Mbaja ( 3 , 3 ,
					 1 ,    1 ,     1 ,
					 1 , FAC_AMPL , 1 ,
					 1 ,    1 ,     1 ) ;

mascara MLaplaciano ( 3 , 3 ,
					 0 , 1  , 0 ,
					 1 , -4 , 1 ,
					 0 , 1  , 0 ) ;

mascara  MGauss		( 3 , 3 ,
						 1 , 2 , 1 ,
						 3 , 3 , 3 ,
						 1 , 2 , 1 ) ;

mascara  MPrewitX		( 3 , 3 ,
						 -1 , -1 , -1 ,
						  0 ,  0 ,  0 ,
						  1 ,  1 ,  1 ) ;

mascara  MPrewitY		( 3 , 3 ,
						 -1 , 0 , 1 ,
						 -1 , 0 , 1 ,
						 -1 , 0 , 1 ) ;

mascara  MSobelX		( 3 , 3 ,
						 -1 , -2 , -1 ,
						  0 ,  0 ,  0 ,
						  1 ,  2 ,  1 ) ;

mascara  MSobelY		( 3 , 3 ,
						 -1 , 0 , 1 ,
						 -2 , 0 , 2 ,
						 -1 , 0 , 1 ) ;

mascara  MRobertsX		( 3 , 3 ,
                          0 , 0,   0 ,
                          0 , 1 ,  0 ,
						  0 , 0 , -1 );

mascara  MRobertsY		( 3 , 3 ,
						  0 , 0,  0 ,
						  0 , 0 , 1 ,
						  0 ,-1 , 0 );




//---------------------------------------------------------------------------

__fastcall TFormaPrincipal::TFormaPrincipal(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::CreateMDIChild(String Name)
{
	TMDIChild *Child;
	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = Name;
  Nombre =Name;
 //Objeto Global IMAGEN
   IMGBMP  = new TPicture();
   IMGBMP->Bitmap->PixelFormat=pf24bit;
   IMGBMP->Graphic->LoadFromFile(Name);

   Child->ClientWidth  = IMGBMP->Width;
 	 Child->ClientHeight = IMGBMP->Height;
   Child->Img1->Width  = IMGBMP->Width;
   Child->Img1->Height = IMGBMP->Height;
   Child->Img1->Picture=IMGBMP;

   TipoImagen();
}

void __fastcall TFormaPrincipal::AjustaChild(TMDIChild *Child)
{
   Child->ClientWidth  = IMGBMP->Width;
	 Child->ClientHeight = IMGBMP->Height;
   Child->Img1->Width  = IMGBMP->Width;
   Child->Img1->Height = IMGBMP->Height;
}//Ajuste

void __fastcall TFormaPrincipal::TipoImagen()
{
  esColor=false;
  esBinary=true;
  esGrayscale=false;
  int i,j;

  byte **R=getR(IMGBMP);
  byte **G=getG(IMGBMP);
  byte **B=getB(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  i=0;
  while ((i<h) && !esColor && !esGrayscale) {
    j=0;
    while (j<w && !esColor && !esGrayscale ) {
      if ( (R[j][i]!=G[j][i]) || (G[j][i] != B[j][i]) ||
           (B[j][i]!=R[j][i]) ) {
        esColor=true;
        esGrayscale=false;
        esBinary=false; //modificado
      }

      else if ( (R[j][i] != (unsigned char)0) &&
                (R[j][i] != (unsigned char)255) ){
        esGrayscale=true;
        esColor=false;
        esBinary=false; //modificado
      }
      j++;
    }
    i++;
  }
}



void TFormaPrincipal::MostrarImagen(byte **R,byte **G,byte **B,int w,int h,String Name)
{
 TMDIChild *Child;
 Child = new TMDIChild(Application);
 Child->ClientWidth  =w;
 Child->ClientHeight =h;
 Child->Img1->Width  =w;
 Child->Img1->Height =h;
 Child->Caption=Name;

 IMGBMP->Bitmap->Width=w;
 IMGBMP->Bitmap->Height=h;
 pinta(R,G,B,w,h);

 Child->Img1->Canvas->Draw(0,0,IMGBMP->Graphic);

}

uchar TFormaPrincipal::ConvertirValor(byte valor,int bit)
{
 float v;
 int i,j;
 byte tmp;
 switch(bit)
    {
     case 1:
            tmp=valor&0x80;
            break;
     case 2:
            tmp=valor&0xc0;
            break;
     case 3:
            tmp=valor&0xe0;
            break;
     case 4:
            tmp=valor&0xf0;
            break;
     case 5:
            tmp=valor&0xf8;
            break;
     case 6:
            tmp=valor&0xfc;
            break;
     case 7:
            tmp=valor&0xfe;
            break;
      default:
            break;
    }

 j=pow(2,8)-pow(2,8-bit);
 v=255 * tmp/j;
 i=(int)v;
 return (byte)i;

}
//---------------------------------------------------------------------------

void TFormaPrincipal::ResolucionBits(int bits)
{
 int w = IMGBMP->Bitmap->Width;
 int h = IMGBMP->Bitmap->Height;
 byte **R = getR(IMGBMP);
 byte **R2 = new byte*[w];


 for(int i=0; i< w ; i++)
     R2[i] = new byte[h];

 for(int j=0;j<h;j++)
     for(int i=0;i<w;i++)
        R2[i][j]=ConvertirValor(R[i][j],bits);

 MostrarImagen(R2,R2,R2,w,h,IntToStr(bits)+" bit");
}

void __fastcall TFormaPrincipal::FileNew1Execute(TObject *Sender)
{
	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::FileOpen1Execute(TObject *Sender)
{
	if (OpenDialog->Execute())
		CreateMDIChild(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void TFormaPrincipal::AbrirImagen2()
{
	if (OpenDialog->Execute())
  {
   	TMDIChild *Child;

	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = OpenDialog->FileName;
  Nombre =OpenDialog->FileName;

   IMGBMPRS  = new TPicture();
   IMGBMPRS->Bitmap->PixelFormat=pf24bit;
   IMGBMPRS->Graphic->LoadFromFile(Nombre);

   Child->ClientWidth  = IMGBMPRS->Width;
	 Child->ClientHeight = IMGBMPRS->Height;
   Child->Img1->Width  = IMGBMPRS->Width;
   Child->Img1->Height = IMGBMPRS->Height;
   Child->Img1->Picture=IMGBMPRS;
  }
}







void __fastcall TFormaPrincipal::N1bit1Click(TObject *Sender)
{
ResolucionBits(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N2bits1Click(TObject *Sender)
{
ResolucionBits(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N3bits1Click(TObject *Sender)
{
ResolucionBits(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N4bits1Click(TObject *Sender)
{
ResolucionBits(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N5bits1Click(TObject *Sender)
{
ResolucionBits(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N6bits1Click(TObject *Sender)
{
ResolucionBits(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N7bits1Click(TObject *Sender)
{
ResolucionBits(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N121Click(TObject *Sender)
{
Neiboor(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N141Click(TObject *Sender)
{
Neiboor(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N181Click(TObject *Sender)
{
Neiboor(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N211Click(TObject *Sender)
{
Neiboor(0.5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N411Click(TObject *Sender)
{
Neiboor(0.25);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N811Click(TObject *Sender)
{
Neiboor(0.125);
}
//---------------------------------------------------------------------------



void __fastcall TFormaPrincipal::Histograma1Click(TObject *Sender)
{
  FormaHistograma->GroupBox2->Enabled=false;
  FormaHistograma->RadioR->Enabled=false;
  FormaHistograma->RadioG->Enabled=false;
  FormaHistograma->RadioB->Enabled=false;
  FormaHistograma->RadioL->Enabled=false;
  FormaHistograma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Ensancharhistograma1Click(TObject *Sender)
{
FormEnsancharH->Show();
}
//---------------------------------------------------------------------------


void TFormaPrincipal::Neiboor(double zoom)
{
 int w = IMGBMP->Bitmap->Width;
 int h = IMGBMP->Bitmap->Height;
 int nw = w * zoom;
 int nh = h * zoom;
 byte **R = getR(IMGBMP);
 byte **R2 = new byte*[nw];
 byte **G = getG(IMGBMP);
 byte **G2 = new byte*[nw];
 byte **B = getB(IMGBMP);
 byte **B2 = new byte*[nw];


 int x0=0, y0=0;

 for(int i=0; i< nw ; i++)
    {
     R2[i] = new byte[nh];
     G2[i] = new byte[nh];
     B2[i] = new byte[nh];
    }
 for(int j=0;j<nh;j++)
     for(int i=0;i<nw;i++)
        {
         int x= INT((i+(zoom-1)*x0)/zoom);
         int y= INT((j+(zoom-1)*y0)/zoom);
         R2[i][j]=R[x][y];
         G2[i][j]=G[x][y];
         B2[i][j]=B[x][y];
        }

 TMDIChild *Child;
 Child = new TMDIChild(Application);
 Child->ClientWidth  =nw;
 Child->ClientHeight =nh;
 Child->Img1->Width  =nw;
 Child->Img1->Height =nh;
 if(zoom < 1 )
 Child->Caption="Disminuye " + FloatToStr(pow(zoom,-1)) + " veces(neiboor)";
 else
 Child->Caption="Aumenta " + FloatToStr(zoom) + " veces(neiboor)";
 IMGBMP->Bitmap->Width=nw;
 IMGBMP->Bitmap->Height=nh;
 pinta(R2,G2,B2,nw,nh);

 Child->Img1->Canvas->Draw(0,0,IMGBMP->Graphic);

}


void TFormaPrincipal::InterpolacionBilineal(double zoom)
{
 int w = IMGBMP->Width;
 int h = IMGBMP->Height;
 int nw = w * zoom;
 int nh = h * zoom;
 byte **R = getR(IMGBMP);
 byte **R2 = new byte*[nw];

 byte **G = getG(IMGBMP);
 byte **G2 = new byte*[nw];

 byte **B = getB(IMGBMP);
 byte **B2 = new byte*[nw];

 for(int i=0; i< nw ; i++)
    {
     R2[i] = new byte[nh];
     G2[i] = new byte[nh];
     B2[i] = new byte[nh];
    }
 double scaleX = (double)w / nw;
 double scaleY = (double)h / nh;

 for (int j = 0; j < nh; j++)
     {
      double srcY = scaleY * j;
      for (int i = 0; i < nw; i++)
         {
          double srcX = scaleX * i;
          R2[i][j] = interpola(srcX, srcY,R);
          G2[i][j] = interpola(srcX, srcY,G);
          B2[i][j] = interpola(srcX, srcY,B);
         }
     }

 TMDIChild *Child;
 Child = new TMDIChild(Application);
 Child->ClientWidth  = IMGBMP->Width*zoom;
 Child->ClientHeight = IMGBMP->Height*zoom;
 Child->Img1->Width  = IMGBMP->Width*zoom;
 Child->Img1->Height = IMGBMP->Height*zoom;
 if(zoom<1)
 Child->Caption="Disminuye " + FloatToStr(pow(zoom,-1)) + " veces(bilineal)";
 else
 Child->Caption="Aumenta " + FloatToStr(zoom) + " veces(bilineal)";
 IMGBMP->Bitmap->Width=nw;
 IMGBMP->Bitmap->Height=nh;
 pinta(R2,G2,B2,nw,nh);

 Child->Img1->Canvas->Draw(0,0,IMGBMP->Graphic);

}

int TFormaPrincipal::Bilineal(float i, float j)
{
        int x1, y1, x2, y2;
        float Gray;

        x1 = (int)floor(i);
        x2 = x1+1;
        y1 = (int)floor(j);
        y2 = y1+1;
        Gray = (y2-j)*(x2-i)*imgbmp[x1][y1] + (y2-j)*(i-x1)*imgbmp[x2][y1]
             + (j-y1)*(x2-i)*imgbmp[x1][y2] + (j-y1)*(i-x1)*imgbmp[x2][y2];
                 return INT(Gray);
}

void __fastcall TFormaPrincipal::Correlacion1Click(TObject *Sender)
{
FormaLetras->Metodo=1;
FormaLetras->Show();
}
//---------------------------------------------------------------------------


byte** TFormaPrincipal::getR(TPicture  *BMP){
        //obtiene el tamaño de la imagen
        int imageWidth = BMP->Width;
      	int imageHeight = BMP->Height;
        byte **r = new byte*[imageWidth];

        for(int i=0; i<imageWidth ; i++){
                r[i] = new byte[imageHeight];
        }

        RGBTRIPLE *buffer;
        for(int j=0; j<imageHeight;j++){
             buffer=(RGBTRIPLE*)BMP->Bitmap->ScanLine[j];
            for(int i =0;i<imageWidth;i++){
                        r[i][j] = (byte) buffer[i].rgbtRed;
             }
        }

        return r;
}

byte** TFormaPrincipal::getG(TPicture  *BMP){
        //obtiene el tamaño de la imagen
        int imageWidth = BMP->Width;
	int imageHeight = BMP->Height;
        byte **g = new byte*[imageWidth];

        for(int i=0; i<imageWidth ; i++){
                g[i] = new byte[imageHeight];
        }
        RGBTRIPLE *buffer;
        for(int j=0; j<imageHeight;j++){
             buffer=(RGBTRIPLE*)BMP->Bitmap->ScanLine[j];
            for(int i =0;i<imageWidth;i++){
                        g[i][j] = (byte) buffer[i].rgbtGreen;
             }
        }
        return g;
}

byte** TFormaPrincipal::getB(TPicture  *BMP){
        //obtiene el tamaño de la imagen
        int imageWidth = BMP->Width;
      	int imageHeight = BMP->Height;
        byte **b = new byte*[imageWidth];

        for(int i=0; i<imageWidth ; i++){
                b[i] = new byte[imageHeight];
        }
        RGBTRIPLE *buffer;
        for(int j=0; j<imageHeight;j++){
             buffer=(RGBTRIPLE*)BMP->Bitmap->ScanLine[j];
            for(int i =0;i<imageWidth;i++){
                        b[i][j] = (byte) buffer[i].rgbtBlue;
             }
        }
  return b;
}

void TFormaPrincipal::pinta(byte **R,byte **G,byte **B,int w,int h){
	int r,g,b;
	//recorre cada arreglo y lo pone en cada localidad del arreglo en el formato dado
  RGBTRIPLE *buffer;
  for(int j=0;j<h;j++){
    buffer=(RGBTRIPLE*)IMGBMP->Bitmap->ScanLine[j];
   	for(int i=0;i<w;i++){    //
          buffer[i].rgbtBlue= B[i][j];
          buffer[i].rgbtRed= R[i][j];
          buffer[i].rgbtGreen= G[i][j];
		}
	}
}

byte TFormaPrincipal::interpola(double x, double y, byte **R){
        // x and y represent the intersection of 2 rows and columns
      // in the source array. we need the fractional parts of each
      // value for use in interpolation as the values u and v
        int w = IMGBMP->Width;
        int h = IMGBMP->Height;

      int px = (int)x;
      int py = (int)y;

      double u = x - px;
      double v = y - py;

      // ignore all values outside the image bounds
      if (px < 0 || px >= w || py < 0 || py >= h)
         return 0;

      // grab the values for the four pixels starting with p00
      // in the top left corner (which is guaranteed to be in
      // bounds). if any of the others is out of bounds then
      // give it the same value as p00
      //int index = py * width + px;
      int p00 = R[px][py];
      int p01 = (px < w - 1) ? R[px + 1][py] : p00;
      int p10 = (py < h - 1) ? R[px][py+1] : p00;
      int p11 = (py < h - 1 && px < w - 1) ? R[px+1][py+1] : p00;

      // now follow the recipe
      double interp = (1-v) * ((1 - u) * p00 + u * p01) +
                        v * ((1-u) * p10 + u * p11);

      return (byte)interp;
}

void __fastcall TFormaPrincipal::N122Click(TObject *Sender)
{
InterpolacionBilineal(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N142Click(TObject *Sender)
{
InterpolacionBilineal(4);
}
//---------------------------------------------------------------------------


double TFormaPrincipal::C0(double t)
{
  return -a * t * t * t + a * t * t;
}

double TFormaPrincipal::C1(double t)
{
  return -(a + 2.0f) * t * t * t + (2.0f * a + 3.0f) * t * t - a * t;
}

double TFormaPrincipal::C2(double t)
{
  return (a + 2.0f) * t * t * t - (a + 3.0f) * t * t + 1.0f;
}

double TFormaPrincipal::C3(double t)
{
  return a * t * t * t - 2.0f * a * t * t + a * t;
}


void TFormaPrincipal::Bicubica(double zoom)
{
TMDIChild *Child;
  Child = new TMDIChild(Application);
  IMGBMPRS  = new TPicture();

int in_width = IMGBMP->Width;
int in_height = IMGBMP->Height;
        int out_width = in_width * zoom;
        int out_height = in_height * zoom;

        byte **f = getR(IMGBMP);
        byte **g = new byte*[out_width ];
        for(int i=0; i< out_width ; i++){
                g[i] = new byte[out_height];
        }


 int larger_out_dimension;
 int n=zoom, d=1, j, k, l, m, index;
 int L[XDIM];
// byte f[XDIM][XDIM];
// byte g[XDIM][XDIM];
 double x;
 double c[4][XDIM];
 double h[XDIM];
       
 larger_out_dimension = (out_width > out_height) ? out_width
                                                  : out_height;

  for (k = 0; k < larger_out_dimension; k++)
    L[k] = (k * d) / n;

  for (k = 0; k < n; k++) {
    x = (double)((k * d) % n) / (double)n;
    c[0][k] = C0(x);
    c[1][k] = C1(x);
    c[2][k] = C2(x);
    c[3][k] = C3(x);
  }
  for (k = n; k < larger_out_dimension; k++)
    for (l = 0; l < 4; l++)
      c[l][k] = c[l][k % n];

  for (k = 0; k < out_height; k++) {
    for (j = 0; j < in_width; j++) {
      h[j] = 0.0;
      for (l = 0; l < 4; l++) {
        index = L[k] + l - 1;
        if ((index >= 0) && (index < in_height))
          h[j] += f[index][j] * c[3 - l][k];
      }
    }
    for (m = 0; m < out_width; m++) {
      x = 0.5;
      for (l = 0; l < 4; l++) {
        index = L[m] + l - 1;
        if ((index >= 0) && (index < in_width))
          x += h[index] * c[3 - l][m];
      }
      if (x <= 0.0)
        g[k][m] = 0;
      else if (x >= 255)
        g[k][m] = (byte)255;
      else
        g[k][m] = (byte)x;
    }
  }

 Child->ClientWidth  = IMGBMP->Width*zoom;
 Child->ClientHeight = IMGBMP->Height*zoom;
 Child->Img1->Width  = IMGBMP->Width*zoom;
 Child->Img1->Height = IMGBMP->Height*zoom;
 if(zoom <1)
 Child->Caption="Disminuye " + FloatToStr(pow(zoom,-1)) + " veces(bicubica)";
 else
 Child->Caption="Aumenta " + FloatToStr(zoom) + " veces(bicubica)";
 IMGBMPRS->Bitmap->Width=IMGBMP->Width*zoom;
 IMGBMPRS->Bitmap->Height=IMGBMP->Height*zoom;

  IMGBMP->Bitmap->Width=out_width ;
           IMGBMP->Bitmap->Height=out_height ;
        pinta(g,g,g,out_width ,out_height );

 Child->Img1->Canvas->Draw(0,0,IMGBMP->Graphic);



}

void __fastcall TFormaPrincipal::N123Click(TObject *Sender)
{
Bicubica(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N143Click(TObject *Sender)
{
Bicubica(4);
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrincipal::CorrelacionMedia1Click(TObject *Sender)
{
FormaLetras->Metodo=2;
FormaLetras->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Comparacion1Click(TObject *Sender)
{
FormaLetras->Metodo=3;
FormaLetras->Show();
}
//---------------------------------------------------------------------------



void __fastcall TFormaPrincipal::N182Click(TObject *Sender)
{
InterpolacionBilineal(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N183Click(TObject *Sender)
{
Bicubica(8);
}
//---------------------------------------------------------------------------

void TFormaPrincipal::ConvertirColorGris()
{
  int w = IMGBMP->Width;
	int h = IMGBMP->Height;

  byte **R = getR(IMGBMP);
	byte **G = getG(IMGBMP);
	byte **B = getB(IMGBMP);

	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			R[i][j] = (byte)(R[i][j]*0.299 + G[i][j]*0.587 + B[i][j]*0.114);
			G[i][j] = R[i][j];
			B[i][j] = R[i][j];
		}
	}
MostrarImagen(R,G,B,w,h,"Imagen en niveles de gris");
}

void TFormaPrincipal::DescomponerRGB()
{
 int w = IMGBMP->Width;
 int h = IMGBMP->Height;
  byte **G = getG(IMGBMP);
  byte **B = getB(IMGBMP);
  byte **R = getR(IMGBMP);
  MostrarImagen(R,R,R,w,h,"Plan R");
  MostrarImagen(G,G,G,w,h,"Plan G");
  MostrarImagen(B,B,B,w,h,"Plan B");

}
void __fastcall TFormaPrincipal::Convertiranivelesdegris1Click(
      TObject *Sender)
{
ConvertirColorGris();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Manual1Click(TObject *Sender)
{
FormaBinariza->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Automatica1Click(TObject *Sender)
{
 FormaBinariza->CalculaUmbral();
 FormaBinariza->Binariza();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Ensanchar1Click(TObject *Sender)
{
FormEnsancharH->EnsancharHist();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Equalizacion1Click(TObject *Sender)
{
FormaHistograma->EqualizaHist();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Adicion1Click(TObject *Sender)
{
//AbrirImagen2();
FormaOpLogArit->operacion=opAd;
FormaOpLogArit->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Substraccion1Click(TObject *Sender)
{
FormaOpLogArit->operacion=opSub;
FormaOpLogArit->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::And1Click(TObject *Sender)
{
FormaOpLogArit->operacion=opAnd;
FormaOpLogArit->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Or1Click(TObject *Sender)
{
FormaOpLogArit->operacion=opOr;
FormaOpLogArit->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Xor1Click(TObject *Sender)
{
FormaOpLogArit->operacion=opXor;
FormaOpLogArit->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::FormCreate(TObject *Sender)
{
	Screen->OnActiveFormChange = UpdateMenuItems;
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::UpdateMenuItems(TObject *Sender)
{
	FileCloseItem->Enabled = MDIChildCount > 0;
 	FileSaveItem->Enabled = MDIChildCount > 0;
	Reconocimientodecaracteres1->Enabled=MDIChildCount > 0;
	WindowCascadeItem->Enabled = MDIChildCount > 0;
	WindowTileItem->Enabled = MDIChildCount > 0;
	WindowArrangeItem->Enabled = MDIChildCount > 0;
	WindowMinimizeItem->Enabled = MDIChildCount > 0;
  Herramientas1->Enabled = MDIChildCount > 0;
  Mejoramiento1->Enabled = MDIChildCount > 0;
}

void __fastcall TFormaPrincipal::FileSave1Execute(TObject *Sender)
{
SaveDialog1->FileName=OpenDialog->FileName;
if(SaveDialog1->Execute())
{
    AnsiString as;

      as =SaveDialog1->FileName;
      IMGBMP->SaveToFile(as+".bmp");


}

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::DescomponerentresplanosRGB1Click(
      TObject *Sender)
{
DescomponerRGB();
}
//---------------------------------------------------------------------------


void __fastcall TFormaPrincipal::N212Click(TObject *Sender)
{
 InterpolacionBilineal(0.5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N412Click(TObject *Sender)
{
InterpolacionBilineal(0.25);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N812Click(TObject *Sender)
{
InterpolacionBilineal(0.125);  
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N21Click(TObject *Sender)
{
Bicubica(0.5);  
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N413Click(TObject *Sender)
{
Bicubica(0.25);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::N813Click(TObject *Sender)
{
Bicubica(0.125);
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Not1Click(TObject *Sender)
{
FormaOpLogArit->Not();
}
//---------------------------------------------------------------------------


				//*****************************************************************
				//****************  IMPLEMENTACIONDE LA CLASE IMAGEN **************
				//*****************************************************************

//***********Filtra una imágen con  la mascara con la que se va a filtrar
void __fastcall TFormaPrincipal::_filtra (mascara *pG )
{   //*****VARIABLES
  //********* realiza la llamada a la funcionalidad "filtra" de la clase MASCARA para cada pixel de la imagen

  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;
  imgbmp=getR(IMGBMP);
  for( int i = 1 ; i < w-1 ;  i++ )
    for( int j = 1 ; j < h-1 ;  j++ )
    	 R[i][j]=pG->filtra( i , j, 0 ) ;     		//si no son de la orilla, si se filtran, *PG contiene la dirección de la máscarac con la cual se va a filtrar

    byte **G=getG(IMGBMP);
  imgbmp=getG(IMGBMP);
  for( int i = 1 ; i < w-1 ;  i++ )
    for( int j = 1 ; j < h-1 ;  j++ )
    	 G[i][j]=pG->filtra( i , j, 0 ) ;     		//si no son de la orilla, si se filtran, *PG contiene la dirección de la máscarac con la cual se va a filtrar


  byte **B=getB(IMGBMP);
  imgbmp=getB(IMGBMP);
  for( int i = 1 ; i < w-1 ;  i++ )
    for( int j = 1 ; j < h-1 ;  j++ )
    	 B[i][j]=pG->filtra( i , j, 0 ) ;     		//si no son de la orilla, si se filtran, *PG contiene la dirección de la máscarac con la cual se va a filtrar

  //  MostrarImagen(R,G,B,w,h,"PRO");
  pinta(R,G,B,w,h);

}// _filtra
//---------------------------------------------------------------------------


//FILTROS DIFERENCIALES
//Filtra una imágen con un par de mascaras || (ROBERTS, PREWIT Y SOBEL
void __fastcall TFormaPrincipal::_filtra (mascara *pX, mascara *pY)
{   //*****VARIABLES

  //********* realiza la llamada a la funcionalidad "filtra" de la clase MASCARA para cada pixel de la imagen
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;
  imgbmp=getR(IMGBMP);

  for( int i = 1 ; i < w-1 ;  i++ )
    for( int j = 1 ; j < h-1 ;  j++ )
	{
		 int tempX, tempY;
		       tempX = pX->filtra( i , j , 1) ;     		//si no son de la orilla, si se filtran, *PG contiene la dirección de la máscara con la cual se va a filtrar
           tempY = pY->filtra( i , j , 1) ;       //el tercer parámetro  "1" indica que es de segunda derivada
		   R[i][j]=tempX + tempY ;
	}//for
    pinta(R,R,R,w,h);

}// _filtra (,)



void __fastcall TFormaPrincipal::Media1Click(TObject *Sender)
{
  _filtra(&Mprom);
  byte **R=getR(IMGBMP);
  byte **G=getG(IMGBMP);
  byte **B=getB(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,G,B,w,h,"PROMEDIO");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::PasaBajas1Click(TObject *Sender)
{
 _filtra(&Mbaja);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"PASA BAJAS");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Gausiano1Click(TObject *Sender)
{
 _filtra(&MGauss);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"GAUSSIANO");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::LaPlaciano1Click(TObject *Sender)
{
 _filtra(&MLaplaciano);
  byte **R=getR(IMGBMP);
  byte **G=getG(IMGBMP);
  byte **B=getB(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,G,B,w,h,"LAPLACIANO");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::LaplacianodelGausiano1Click(
      TObject *Sender)
{
 _filtra(&MGauss,&MLaplaciano);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"LoG");
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::PasaAltas1Click(TObject *Sender)
{
 _filtra(&Malta);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"PASA ALTAS");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::HighBoots1Click(TObject *Sender)
{
 _filtra(&HBoot);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"HIGH BOOTS");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::OperadorRobers1Click(TObject *Sender)
{
 _filtra(&MRobertsX,&MRobertsY);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"FILTRO ROBERTS");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::OperadorSobel1Click(TObject *Sender)
{
 _filtra(&MSobelX,&MSobelY);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"FILTRO SOBEL");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::OperadorPrewitt1Click(TObject *Sender)
{
 _filtra(&MPrewitX,&MPrewitY);
  byte **R=getR(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,R,R,w,h,"FILTRO PREWITT");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Conteodeobjetos1Click(TObject *Sender)
{
//int Nobj;
for(int i=0;i<NValues;i++)
    {
     Etiquetas[i][0]=0;
     Etiquetas[i][1]=0;
    }

EtiquetarImagen(IMGBMP->Width,IMGBMP->Height);
EliminarFalsosObjetos(IMGBMP->Width,IMGBMP->Height,Pmin);
//for(int i=0;Etiquetas[i][0]!=0;i++)
//    Nobj=Etiquetas[i][0];
ShowMessage(" La imagen tiene " + IntToStr(Rfin)+" objetos");

}
//---------------------------------------------------------------------------

int __fastcall TFormaPrincipal::EtiquetarImagen(int ancho, int alto)
{
 
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;
  imgbmp=getR(IMGBMP);

  int i,j,label=1,Labels[NValues*2][2];
  int dirn[2][2]={{0,-1},
                  {-1,0}};
  int acum=0;

  for (i=0;i<w;i++)
   for (j=0;j<h;j++)
   {
     if (imgbmp[j][i]==255)
     {
       int vecino[2]={0,0},k,n=0,cont;
       // analizar los vecinos de p
       for (k=0;k<2;k++)
       {
         int x=i+dirn[0][k],y=j+dirn[1][k];
         if (x>=0 && x<h && y>=0 && y<w && imgbmp[y][x]!=0)
          vecino[n++]=imgbmp[y][x];
       }
       // analizar vecinos encontrados
       if (n==1)
        imgbmp[j][i]=(unsigned char)vecino[0];
        else
         if (n==2 && vecino[0]==vecino[1])
          imgbmp[j][i]=(unsigned char)vecino[0];
          else
           if (n==2 && vecino[0]!=vecino[1])
           {
             // ordenar las etiquetas
             if (vecino[0]>vecino[1])
             {
               int temp=vecino[0];
               vecino[0]=vecino[1];
               vecino[1]=temp;
             } // fin de (mayor)
             // buscar indice para vecino[1] en Labels
             for (cont=0;cont<acum;cont++)
              if (Labels[cont][0]==vecino[1])
               break;
             // actualizar puntos i,j con su nuevo valor
             int a,b,indice=Labels[cont][1];
             for (a=indice;a<=i;a++)
              for (b=0;b<ancho;b++)
               if (imgbmp[b][a]==vecino[1])
                imgbmp[b][a]=(unsigned char)vecino[0];

             // eliminar etiqueta de Labels[][]
             Labels[cont][0]=0; Labels[cont][1]=0;
             imgbmp[j][i]=(unsigned char)vecino[0];

             // actualizar valor de label, buscando el valor mayor
             int s,t=Labels[0][0];
             for (s=1;s<acum;s++)
              if (Labels[s][0]>t)
               t=Labels[s][0];
             label=t+1;

             // actualizar valor de acum
             if (Labels[acum-1][0]==0)
              acum--;
           } // fin de if (k==2...)
           else
           {
             // verificar que el valor de etiqueta sea válido
             if (label>=NValues)
              return 6;
             // nueva etiqueta
             imgbmp[j][i]=(unsigned char)label;
             Labels[acum][0]=label++;
             Labels[acum++][1]=i;
           } // fin de else
     } // fin de if (255)
   } // fin de for (j)

   // establecer valores de etiqueta y regiones finales
   Rfin=0;
   for (i=0;i<acum;i++)
    if (Labels[i][0]!=0)
    { Etiquetas[Rfin][0]=Labels[i][0]; Etiquetas[Rfin++][1]=Labels[i][1]; }

  return 0; // no hubo error
} // fin de función

/////////////////////////////////////////////////////////////////////
void __fastcall TFormaPrincipal::EliminarFalsosObjetos(int ancho, int alto, int pmin)
{
   int i,j,k,Ri,Labels[NValues][2];
   Ri=Rfin;

  int w = IMGBMP->Width;
  int h = IMGBMP->Height;


   for (i=0;i<Ri;i++)
    for (j=0;j<2;j++)
    {
      Labels[i][j]=Etiquetas[i][j];
      Etiquetas[i][j]=0;
    } // fin de for (j)

   // buscar regiones con área en pixeles <= pmin
   for (k=0;k<Ri;k++)
   {
     int brk,cont=0;
     for (i=Labels[k][1];i<h;i++)
     {
       brk=0;
       for (j=0;j<w;j++)
        if (imgbmp[j][i]==Labels[k][0])
        {
          cont++;
          brk=1;
        } // fin de if (objeto)
       if (!brk)
        break;
     } // fin de for (i)
     // verificar condicion()
     if (cont<=pmin)
     {
       for (i=Labels[k][1];i<h;i++)
       {
         brk=0;
         for (j=0;j<w;j++)
          if (imgbmp[j][i]==Labels[k][0])
          {
            imgbmp[j][i]=0; // eliminar región
            brk=1;
          } // fin de if (objeto)
         if (!brk)
          break;
       } // fin de for (i)
       // eliminar etiqueta
       Labels[k][0]=0; Labels[k][1]=0;
     } // fin de if (cont<=pmin)
   } // fin de for (k)

  // establecer etiquetas finales
  Rfin=0;
  for (i=0;i<Ri;i++)
   if (Labels[i][0]!=0)
   {
     Etiquetas[Rfin][0]=Labels[i][0];
     Etiquetas[Rfin++][1]=Labels[i][1];
   } // fin de if ()
  
} // fin de función

/////////////////////////////////////////////////////////////////////

void __fastcall TFormaPrincipal::Histogramaimagenesencolor1Click(
      TObject *Sender)
{
  FormaHistograma->GroupBox2->Enabled=true;
  FormaHistograma->RadioR->Enabled=true;
  FormaHistograma->RadioG->Enabled=true;
  FormaHistograma->RadioB->Enabled=true;
  FormaHistograma->RadioL->Enabled=true;
  FormaHistograma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Normalizar1Click(TObject *Sender)
{

 FormaNormalizar->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::DefinirMascara1Click(TObject *Sender)
{
FormaGeneraMascara->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AplicarMascara1Click(TObject *Sender)
{
  _filtra(&Mp);
  byte **R=getR(IMGBMP);
  byte **G=getG(IMGBMP);
  byte **B=getB(IMGBMP);
  int w = IMGBMP->Width;
  int h = IMGBMP->Height;

  MostrarImagen(R,G,B,w,h,"PROMEDIO");

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::SeleccionarNIteraciones(void)
{
  try {
    n = (InputBox("AFS", "Número de iteraciones", "3")).ToInt();
	 //ShowMessage("El valor elejido es: " + AnsiString(n));
  }
  catch (...) {
    n = 3;
	 ShowMessage("NOOOooooooooo!!!, Tienes que escribir un VALOR ENTERO. -- He cogido por defecto 3 --");
  }
}

void __fastcall TFormaPrincipal::Dilatacion1Click(TObject *Sender)
{

int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         DilationBinary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     DilationBinary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Dilatación");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         DilationGrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     DilationGrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Dilatación");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         DilationColor1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     DilationColor1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"Dilatación");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Invertir1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   InvertirBinary();
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Negación");
  }
if(esGrayscale)
  {
   InvertirBinary();
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Negación");
  }

if(esColor)
  {
   InvertirColor();
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"Negación");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Erosion1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ErosionBinary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ErosionBinary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Erosión");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ErosionGrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ErosionGrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Erosión");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ErosionColor1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ErosionColor1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"Erosión");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Apertura1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         OpeningBinary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     OpeningBinary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Apertura");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         OpeningGrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     OpeningGrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Apertura");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         OpeningColor1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     OpeningColor1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"Apertura");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::Cierre1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ClosingBinary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ClosingBinary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Cierre");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ClosingGrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ClosingGrayScale(FormaGeneraMascara->Mask);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"Cierre");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         ClosingColor1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     ClosingColor1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"Cierre");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AF11Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF1Binary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF1Binary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF1GrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF1GrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF1Color1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF1Color1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C");
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AF21Click(TObject *Sender)
{
 int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF2Binary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF2Binary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF2GrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF2GrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF2Color1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
      AF2Color1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AF31Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF3Binary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
    AF3Binary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF3GrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
      AF3GrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF3Color1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
      AF3Color1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C-A");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AF41Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF4Binary(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF4Binary(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }
if(esGrayscale)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF4GrayScale(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF4GrayScale(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }

if(esColor)
  {
   if(FormaGeneraMascara->rotar)
   {
     int x,y,n;
     double angulo;
     x=FormaGeneraMascara->cx;
     y=FormaGeneraMascara->cy;
     n=FormaGeneraMascara->nr;
     angulo=360/n;

     for(int i=0;i<n;i++)
        {
         AF4Color1(FormaGeneraMascara->Mask);
         FormaGeneraMascara->rotarMascara(x,y,angulo);
        }
   }
   else
     AF4Color1(FormaGeneraMascara->Mask);

   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A-C");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF11Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF1Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }
if(esGrayscale)
  {
   ASF1GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }

if(esColor)
  {
   ASF1Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF21Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF2Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }
if(esGrayscale)
  {
   ASF2GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }

if(esColor)
  {
   ASF2Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF31Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF3Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }
if(esGrayscale)
  {
   ASF3GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }

if(esColor)
  {
   ASF3Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C-A");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF41Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF4Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }
if(esGrayscale)
  {
   ASF4GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }

if(esColor)
  {
   ASF4Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A-C");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF51Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF5Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-C-A");
  }
if(esGrayscale)
  {
   ASF5GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-C-A");
  }

if(esColor)
  {
   ASF5Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C-C-A");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF61Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF6Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-A-C");
  }
if(esGrayscale)
  {
   ASF6GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-A-C");
  }

if(esColor)
  {
   ASF6Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A-A-C");
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF71Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF7Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-C-A-A");
  }
if(esGrayscale)
  {
   ASF7GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-C-A-A");
  }

if(esColor)
  {
   ASF7Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C-C-A-A");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ASF81Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

SeleccionarNIteraciones();
TipoImagen();
if(esBinary)
  {
   ASF8Binary(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-A-C-C");
  }
if(esGrayscale)
  {
   ASF8GrayScale(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-A-C-C");
  }

if(esColor)
  {
   ASF8Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A-A-C-C");
  }

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TFormaPrincipal::RotarImagen1Click(TObject *Sender)
{
int x,y, n;
double centerX, centerY, angle;

byte **R=getR(IMGBMP);
byte **G=getG(IMGBMP);
byte **B=getB(IMGBMP);

byte **R2=getR(IMGBMP);
byte **G2=getG(IMGBMP);
byte **B2=getB(IMGBMP);
int w=IMGBMP->Width;
int h=IMGBMP->Height;

centerX=(double)w/2.0;
centerY=(double)h/2.0;


try {
    n = (InputBox("Angulo", "Introduzca el angulo", "90")).ToInt();
	 //ShowMessage("El valor elejido es: " + AnsiString(n));
  }
  catch (...) {
    n = 90;
	 ShowMessage("NOOOooooooooo!!!, Tienes que escribir un VALOR ENTERO. -- He cogido por defecto 3 --");
  }

angle= n*3.14156265/180;

for(int i=0; i<w; i++)
    for(int j=0; j<h; j++)
        {
         x = (int)floor(((i-centerX+0.5)*cos(angle) - (j-centerX+0.5)*sin(angle))+centerX);
	 y = (int)floor(((i-centerY+0.5)*sin(angle) + (j-centerY+0.5)*cos(angle))+centerY);

        if(x>=0&&x<w-1&&y>=0&&y<h-1) {
           R2[i][j]=R[x][y];
           G2[i][j]=G[x][y];
           B2[i][j]=B[x][y];
           }
        }

 MostrarImagen(R2,G2,B2,w,h,"Imágen rotada");

}
//---------------------------------------------------------------------------
/*
void __fastcall TFormaPrincipal::Dilatacion4Click(TObject *Sender)
{
 int x,y,n;
 double angulo;
 x=FormaGeneraMascara->cx;
 y=FormaGeneraMascara->cy;
 n=FormaGeneraMascara->nr;
 angulo=360/n;

 for(int i=0;i<n;i++)
    {
     DilationColor1(FormaGeneraMascara->Mask);
     FormaGeneraMascara->rotarMascara(x,y,angulo);
    }

 byte **R=getR(IMGBMP);
 byte **G=getG(IMGBMP);
 byte **B=getB(IMGBMP);
 int w = IMGBMP->Width;
 int h = IMGBMP->Height;
 MostrarImagen(R,G,B,w,h,"Dilatación");

}
//---------------------------------------------------------------------------

  */
void __fastcall TFormaPrincipal::Cierre2Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF1Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF1GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF1Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A");
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::C11Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF2Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF2GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF2Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::AC1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF3Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF3GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF3Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::CA1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF4Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF4GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF4Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::ACA1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF5Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF5GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"A-C-A");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF5Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"A-C-A");
  }


}
//---------------------------------------------------------------------------

void __fastcall TFormaPrincipal::CAC1Click(TObject *Sender)
{
int w = IMGBMP->Width;
int h = IMGBMP->Height;

TipoImagen();
if(esBinary)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF6Binary(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }

if(esGrayscale)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF6GrayScale(FormaGeneraMascara->Mask,n);

   byte **R=getR(IMGBMP);
   MostrarImagen(R,R,R,w,h,"C-A-C");
  }


if(esColor)
  {
   int n;
   n=FormaGeneraMascara->nr;
   ICF6Color1(FormaGeneraMascara->Mask,n);
   byte **R=getR(IMGBMP);
   byte **G=getG(IMGBMP);
   byte **B=getB(IMGBMP);
   MostrarImagen(R,G,B,w,h,"C-A-C");
  }


}
//---------------------------------------------------------------------------


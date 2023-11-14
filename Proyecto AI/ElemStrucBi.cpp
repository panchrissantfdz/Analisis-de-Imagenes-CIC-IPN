//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <Filectrl.hpp>
#pragma hdrstop

#include "ElemStrucBi.h"
#include "StrucEE.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFSEB *FSEB;

//---------------------------------------------------------------------------
/******************************************************************************
CONSTRUCTOR: TFSEB
OBJETIVO: inicializar variables y crear algunos objetos
PARAMETROS: TComponent
******************************************************************************/

__fastcall TFSEB::TFSEB(TComponent* Owner)//inicio variable en el contructor.
        : TForm(Owner)
{
      EE= new Graphics::TBitmap();
      EEC= new Graphics::TBitmap();
      AUXEE= new Graphics::TBitmap();
      PixEEP= new Graphics::TBitmap();
      PixEE= new Graphics::TBitmap();
      PixEEC= new Graphics::TBitmap();
      ImageB->Tag=0;
      Morpho = new TMorpho(); // crea el objeto morpho
      cc=0;
      tamLevel = 0;
      tamXX= tamYY= tamXY= 0;
      stX= stY= endX= endY= 0;
      sX= sY= eX= eY= XX= YY= 0;
      vx= vy= 0;
      f= true;

      int d=0 ;
      for (int i=0 ; i< 16 ; i++){
        for (int j=0 ; j<16 ; j++)
        {
          panels[i][j] = new TPanel(Owner);
          panels[i][j]->Parent =this ;
                             //Left, Width,Top, Height //separación entre panels=16 // tamaño de panels 15
          panels[i][j]->SetBounds(11+415+15+j*16,8+i*16, 15, 15) ;

          panels[i][j]->Color=TColor(RGB(d+j,d+j,d+j));
          panels[i][j]->Tag = d+j+1 ;
          panels[i][j]->OnClick = FormClickAction;
          panels[i][j]->Visible =true ;
          panels[i][j]->Show();
       }
       d+=16 ;
     }
     currentColor= clBlack;
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: GetElem
OBJETIVO: Obtener el elemento de estructura actual
PARAMETROS: salida un bitmat, entrada vacio
******************************************************************************/

Graphics::TBitmap * TFSEB::GetElem()
{
 return EE;
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: GetOri
OBJETIVO: Obtener el centro del elemento de estructura actual
PARAMETROS: salida vacio, entrada int x, int y
******************************************************************************/

void TFSEB::GetOri(int *_x, int *_y){
 *_x = ox;
 *_y = oy;
}
//---------------------------------------------------------------------------


/*void TFSEB::Angles(int t)
{
 midX =  Image1->Width/2;//width
  midY = Image1->Height/2;//height

  sX = cos((StartA / 180.0) * PI);
  sY = sin((StartA / 180.0) * PI);
  eX = cos((EndA / 180.0) * PI);
  eY = sin((EndA / 180.0) * PI);

  stX = floor(sX * 100); //rounded down
  stY = floor(sY * 100);
  endX = ceil(eX * 100); //rounded up
  endY = ceil(eY * 100);

  EE->Canvas->Pen->Color = clBlack;
  EE->Canvas->Brush->Color = clBlack;
  EE->Canvas->Pie(0,0, EE->Width,EE->Height, //width, height
              midX + stX, midY - stY,
              midX + endX, midY - endY);
}*/


/******************************************************************************
METODO: CuadroClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::CuadroClick(TObject *Sender)
{

    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
    Label8->Visible=false;
    SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: PoligonoClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::RomboClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;
    EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: CruzClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::CruzClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownX->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible=true;
    EditG->Visible= true;
    UpDownG->Visible= true;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;
    EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: CirculoClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::CirculoClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;
    EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: AnilloClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::AnilloClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= true;
    EditG->Visible= true;
    UpDownG->Visible= true;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;

    EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: ElipseClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::ElipseClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblSizeEE->Visible= false;
    Tamval->Visible= false;
    UpDownT->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblAncho->Visible= true;
    EditW->Visible= true;
    UpDownW->Visible= true;
    lblAlto->Visible= true;
    EditH->Visible= true;
    UpDownH->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;
    EditR->Visible=true;
    EditR->Text=0;
    UpDownR->Visible=true;
    LblRote->Visible=true;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: RectanguloClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::RectanguloClick(TObject *Sender)
{
    lblSizeEE->Visible= false;
    Tamval->Visible= false;
    UpDownT->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
   lblAncho->Visible= true;
    EditW->Visible= true;
    UpDownW->Visible= true;
    lblAlto->Visible= true;
    EditH->Visible= true;
    UpDownH->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=false;

    EditR->Visible=true;
    UpDownR->Visible=true;
    LblRote->Visible=true;
    EditR->Text=0;
    SBCreateClick(Sender);

}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: IrregularesClick
OBJETIVO: Quitar (false) y poner (true) los componentes necesarios para
          cada operación.
PARAMETROS: salida vacia, entrada TObject *Sender
******************************************************************************/

void __fastcall TFSEB::IrregularesClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
 /*lblx->Visible= false;
    EditX->Visible= false;
    UpDownX->Visible= false;
    lbly->Visible= false;
    EditY->Visible= false;
    UpDownY->Visible= false;*/
    ImgLevel->Visible= false;
    ImgNLevel->Visible= false;
    cmdCleanL->Visible= false;
    Label8->Visible=false;
    EditR->Text=0;
    EditR->Visible=true;
    UpDownR->Visible=true;
    LblRote->Visible=true;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: ImageBMouseMove
OBJETIVO: Obtener la posición de las celdas del editor de EE
PARAMETROS: salida vacia, entrada *Sender, Shift, x y y;
******************************************************************************/

void __fastcall TFSEB::ImageBMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
lblcx->Caption= X/ctam; // el valor se divide por el tamaño de la celda,
lblcy->Caption= Y/ctam; // según la proporción de la celda

}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: ImageBMouseUp
OBJETIVO: Pinta las celdas de blanco y negro, para EE binarios
///////OJOTE///FALTA QUE TOME LOS NIVELES DE GRIS TAMBIEN
PARAMETROS: salida vacia, entrada Sender, MouseButton, Shift, x e y.
******************************************************************************/
void __fastcall TFSEB::ImageBMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 //se usa en especial para los EE irregulares
   x= X/ctam; // coordenadas de las celdas del editor de ee
   y= Y/ctam;


   if(RadioGroupCustomize->ItemIndex==0 && CheckBoxCompositeSE->Checked==true)
   {
      if (Button==mbLeft){
        if(RadioButtonForeground->Checked==true){
                if(CheckBoxComplement->Checked==false){
                PixEEC->Canvas->Pixels[x][y] = clBlack;}
                else if(CheckBoxComplement->Checked==true){
                PixEEC->Canvas->Pixels[x][y] = clAqua;}
        }
        else if(RadioButtonBackground->Checked==true){
                if(CheckBoxComplement->Checked==false){
                PixEEC->Canvas->Pixels[x][y] = clAqua;}
                else if(CheckBoxComplement->Checked==true){
                PixEEC->Canvas->Pixels[x][y] = clBlack;}
        }
      }
      else if(Button==mbRight){PixEEC->Canvas->Pixels[x][y] = clWhite;}
   }
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: FormCreate
OBJETIVO: Al momento que se crea la forma, tiene un tamaño de 351 de ancho
          se inicializa el editor en uno, pAra evitar el error de divición por cero
PARAMETROS: salida vacia, entrada TObject
******************************************************************************/

void __fastcall TFSEB::FormCreate(TObject *Sender)
{
 tam=3;    // crea un EE cuadrado de 3x3 con centro en 1,1.
 ox=1;
 oy=1;
 EditR->Visible=false;
 UpDownR->Visible=false;
 LblRote->Visible=false;
 //CuadroClick(Sender);
 SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: LoadClick
OBJETIVO: es cargar EE ya almacenados para un uso posterior.
PARAMETROS: salida vacia, entrada TObject
******************************************************************************/
// A ESTE METODO LE FALTA, NECESITO GUARDAR EL ALTO Y ANCHO DE LA IMAGEN CUANDO
// SE PRESENTE EN EL EDITOR, ASÍ COMO EL TAMAÑO DE LAS CELDAS. PARA CADA QUE
// CARGE UN EE SE VEA DE LA MISMA FORMA QUE SE GUARDO
void __fastcall TFSEB::SBLoadClick(TObject *Sender)
{
 Abre->InitialDir=GetCurrentDir()+"\\Structure Elements\\";
// si vamos a abrir un EE es verdadero
   if (Abre->Execute())
   {
      AnsiString path=Abre->FileName;
      StrEE.carga(path.c_str());
   }

    ox= StrEE.x;
    oy= StrEE.y;
    HY= StrEE.yren;
    WX= StrEE.xcol;
    EE->Height= HY;
    EE->Width= WX;

   for (int r=0; r < EE->Height; r++) //y ren
     for (int c=0; c< EE->Width; c++)//x col
     {
      int color = StrEE.bmp[r][c];
      EE->Canvas->Pixels[r][c]= (TColor)RGB(color, color, color);
     }
   CargarEE();
}
//---------------------------------------------------------------------------
void TFSEB::CargarEE(void)
{

  tam = (int)max2(HY,WX);
  ctam = ImageB->Width / tam;
  vx= ((100-tam)/2)+1;
  vy= ((100-tam)/2)+1;

  for(int i=0; i<= Imagec->Height; i++)
   for(int j=0; j<= Imagec->Width; j++)
   Imagec->Canvas->Pixels[i][j]= clWhite;

  for(int i=0; i< HY; i++)
     for(int j=0; j< WX; j++)
       Imagec->Canvas->Pixels[i+vy][j+vx]= EE->Canvas->Pixels[i][j];


  ImageB->Canvas->Brush->Color=clWhite;
  ImageB->Canvas->Pen->Color=clBlack;
  ImageB->Canvas->Rectangle(0,0,ImageB->Width,ImageB->Height);

  for(int i= 0; i < tam; i++){//h, y
    for(int j= 0; j < tam; j++){//w, x
      ImageB->Canvas->Pen->Color=clBlack;
      ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
    }
  }

  DrawGrayDi(HY,WX);
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: SaveClick
OBJETIVO: Es almacenar los EE en una carpete llamada Structure Elements en raíz
          y si no existe la carpeta crearla
PARAMETROS: Salida vacia, entrada TObject.
******************************************************************************/
//AQUI FALTA GUARDAR TODO LOS DATOS QUE MENCIONO EN EL METODO LOADCLICK
void __fastcall TFSEB::SBSaveClick(TObject *Sender)
{
 GuardaEE->InitialDir=GetCurrentDir()+"\\Structure Elements";
/* //si no existe ,crea el directorio Struture Elements en raíz
 //si no lo crea manda error
  if (!DirectoryExists("c:\\Structure Elements"))
  {
    if (!CreateDir("C:\\Structure Elements"))
      throw Exception("Cannot create c:\\Structure Elements.");
  }*/

//guarda la imagen actual, en el directrio Struture Elements

//   Prueba.tipo= RadioButton->Name;
   StrEE.x= ox; //origen
   StrEE.y= oy;
   StrEE.yren=EE->Height;  //alto y ancho
   StrEE.xcol=EE->Width;

     StrEE.bmp = new int*[StrEE.yren];
   for (int j= 0; j < StrEE.yren; j++)
          StrEE.bmp[j] = new int[StrEE.xcol];


   for (int r=0; r < EE->Height; r++) //y ren
     for (int c=0; c< EE->Width; c++)//x col
     {
         int rr =GetRValue(EE->Canvas->Pixels[r][c]); // obtiene el rgb de la coordenada
         int gg =GetGValue(EE->Canvas->Pixels[r][c]);
         int bb =GetBValue(EE->Canvas->Pixels[r][c]);

       StrEE.bmp[r][c]= (rr+gg+bb)/3;
     }

   if (GuardaEE->Execute())
   {
      AnsiString path=GuardaEE->FileName;
      StrEE.guarda(path.c_str());
   }

}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: DrawBiCompositeSE
OBJETIVO: Pinta los EE binarios de EE a ImageB
PARAMETROS: salir vacio, entrar vacio
******************************************************************************/
void TFSEB::DrawBiCompositeSE(void)//APLICACION
{
  for( i= 0; i < tam; i++){//height, y , renglon
     for(j= 0; j < tam; j++){//width, x , columna

          if((oy == i) && (ox == j))
            {
            ImageB->Canvas->Pen->Color=clRed;
            ImageB->Canvas->FrameRect(TRect(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1));
            }
         else
          {
             ImageB->Canvas->Pen->Color=clBlack;
             ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }

          if(EE->Canvas->Pixels[j][i]== clAqua)
          {
          ImageB->Canvas->Brush->Color=clAqua;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
          else if(EE->Canvas->Pixels[j][i]== clBlack)
          {
          ImageB->Canvas->Brush->Color=clBlack;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
          else
          {
          ImageB->Canvas->Brush->Color=clWhite;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
     }
  }
}
/******************************************************************************
METODO: DrawBi
OBJETIVO: Pinta los EE binarios de EE a ImageB
PARAMETROS: salir vacio, entrar vacio
******************************************************************************/
void TFSEB::DrawBi(void)//APLICACION
{
  for( i= 0; i < tam; i++){//height, y , renglon
     for(j= 0; j < tam; j++){//width, x , columna

          if((oy == i) && (ox == j))
            {
            ImageB->Canvas->Pen->Color=clRed;
            ImageB->Canvas->FrameRect(TRect(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1));
            }
         else
          {
             ImageB->Canvas->Pen->Color=clBlack;
             ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }

          if(EE->Canvas->Pixels[j][i]!= clWhite)
          {
          ImageB->Canvas->Brush->Color=clBlack;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
          else
          {
          ImageB->Canvas->Brush->Color=clWhite;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
     }
  }
}

//---------------------------------------------------------------------------
/******************************************************************************
METODO: DrawBiDi
OBJETIVO: Pinta los EE binarios de Rectangulo y Elipse de Imagec a ImageB
PARAMETROS: salir vacio, entrar vacio
******************************************************************************/
void TFSEB::DrawBiDi(void)
{
  for( i= 0; i < YY; i++){//h, y
     for(j= 0; j < XX; j++){//w, x

          if((oy == i) && (ox == j))
            {
            ImageB->Canvas->Pen->Color=clRed;
            ImageB->Canvas->FrameRect(TRect(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1));
           //ImageB->Canvas->FillRect(TRect(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1));
            }
          else
          {
             ImageB->Canvas->Pen->Color=clBlack;
             ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }

          if(EE->Canvas->Pixels[j][i]==clBlack)
          {
          ImageB->Canvas->Brush->Color=clBlack;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
          else
          {
          ImageB->Canvas->Brush->Color=clWhite;
          ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
     }
  }
} 

/******************************************************************************
METODO: cmdCleanLClick
OBJETIVO: Limpia la linea de niveles
PARAMETROS: salida vacio, entrada TObject
******************************************************************************/


//---------------------------------------------------------------------------
/******************************************************************************
METODO: DrawGray
OBJETIVO: Pinta los niveles de gris, de Imagec a ImageB para los EE
PARAMETROS: salida vacio, entrada TObject
******************************************************************************/
void TFSEB::DrawGray(void)
{

        for(int i= 0; i < tam; i++){//h, y
            for(int j= 0; j < tam; j++){//w, x

                 ImageB->Canvas->Pen->Color=clBlack;
                 ImageB->Canvas->Brush->Color=clWhite;
                 ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
            }
        }

        for( int i= 0; i < tam; i++){//h, y
           for(int j= 0; j < tam; j++){//w, x

               if((oy == i) && (ox == j))
                 ImageB->Canvas->Pen->Color = clRed;
               else
                {
                ImageB->Canvas->Pen->Color=clBlack;
                ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
                }

                ImageB->Canvas->Brush->Color=(EE->Canvas->Pixels[j][i]);
                ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
        }
}

//---------------------------------------------------------------------------
/******************************************************************************
METODO: DrawGray
OBJETIVO: Pinta los niveles de gris, de Imagec a ImageB para los EE
PARAMETROS: salida vacio, entrada TObject
******************************************************************************/
void TFSEB::DrawGrayDi(int YY, int XX)
{

        for(int i= 0; i < tam; i++){//h, y
            for(int j= 0; j < tam; j++){//w, x

                 ImageB->Canvas->Pen->Color=clBlack;
                 ImageB->Canvas->Brush->Color=clWhite;
                 ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
            }
        }

        for( int i= 0; i < YY; i++){//h, y
           for(int j= 0; j < XX; j++){//w, x

               if((oy == i) && (ox == j))
                 ImageB->Canvas->Pen->Color = clRed;
               else
                {
                ImageB->Canvas->Pen->Color=clBlack;
                ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
                }

                ImageB->Canvas->Brush->Color=(EE->Canvas->Pixels[j][i]);
                ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
          }
        }
}

//---------------------------------------------------------------------------
/******************************************************************************
METODO: InvGray
OBJETIVO: Del arreglo de niveles de gris en orden, pasa lo niveles en orden
          invertido a otro arreglo
PARAMETROS: salida vacio, entrada int loop = el numero de niveles en gris
                          que se llenaran en el EE.
******************************************************************************/
void TFSEB::InvGray(int loop)
{
  int x=0;
  for(int inv= loop-1; inv >= 0; inv--)
  {
   vcc[x]= vc[inv];
   x++;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EquisClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
     Label8->Visible=false;
     EditR->Visible=false;
    UpDownR->Visible=false;
    LblRote->Visible=false;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFSEB::ArcoClick(TObject *Sender)
{
    LblStart->Visible= true;
    EditS->Visible= true;
    UpDownS->Visible= true;
    LblEnd->Visible= true;
    EditE->Visible= true;
    UpDownE->Visible= true;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= true;
    EditG->Visible= true;
    UpDownG->Visible= true;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=true;
    EditR->Visible=true;
    EditR->Text=0;
    UpDownR->Visible=true;
    LblRote->Visible=true;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::SectorClick(TObject *Sender)
{
    LblStart->Visible= true;
    EditS->Visible= true;
    UpDownS->Visible= true;
    LblEnd->Visible= true;
    EditE->Visible= true;
    UpDownE->Visible= true;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    Label8->Visible=true;
    EditR->Text=0;
    EditR->Visible=true;
    UpDownR->Visible=true;
    LblRote->Visible=true;
     SBCreateClick(Sender);
        
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TFSEB::PoligonoClick(TObject *Sender)
{
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= true;
    ImgNLevel->Visible= true;
    cmdCleanL->Visible= true;
    lblvertice->Visible= true;
    EditVert->Visible= true;
    UpDownV->Visible= true;
     Label8->Visible=false;
     EditR->Visible=true;
     EditR->Text=0;
    UpDownR->Visible=true;
    LblRote->Visible=true;
     SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
void TFSEB::Muestra()
{
  vx= ((100-W)/2)+1;
  vy= ((100-H)/2)+1;

  for(int i=0; i<= Imagec->Height; i++)
    for(int j=0; j<= Imagec->Width; j++)
       Imagec->Canvas->Pixels[i][j]= clWhite;

   for(int i=0; i< H; i++)
     for(int j=0; j< W; j++)
       Imagec->Canvas->Pixels[i+vx][j+vy]= EE->Canvas->Pixels[i][j];

   DrawGrayDi(H,W);
}


void __fastcall TFSEB::UpDownTClick(TObject *Sender, TUDBtnType Button)
{
 TamvalChange(this);
}
//---------------------------------------------------------------------------


void __fastcall TFSEB::TamvalChange(TObject *Sender)
{
    // si se selecciona anillo, el maximo grosor del anillo nunca sea mayor
    // del tamaño de anillo


 //obtiene el tamaño del EE
   tam= StrToInt(Tamval->Text);

  if(tam/2==0.5)
  tamLevel=1; // si el valor de Tamval es 0.5
  //subirlo a 1, para solo llenar una celda para los niveles de gris en el EE
  else
  tamLevel= tam/2; // sino que se divida entre dos para que el
   // numero de niveles de gris no exceda el tamaño del EE

/*    if (Equis->Checked==true){
     if(Tamval->Value%2==0)
       tamLevel = Tamval->Value/2;
     else
       tamLevel= (Tamval->Value/2)+1;
  }*/


}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditXChange(TObject *Sender)
{
// ox = StrToInt(EditX->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditYChange(TObject *Sender)
{
// oy = StrToInt(EditY->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownXClick(TObject *Sender, TUDBtnType Button)
{
 EditXChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownYClick(TObject *Sender, TUDBtnType Button)
{
 EditYChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditWChange(TObject *Sender)
{
 XX= StrToInt(EditW->Text);
 tamXX = (EditW->Text)/2; //tamXX dividido entre 2, da el número de niveles de gris
                         // en el vector de colores que se muestra al usuario
                         //correspondientes según el ancho del EE.

       if(Rectangulo->Checked==true) // si creamos un rectangulo como EE
        {                           // se procura tener valores enteros y no racionales
        if(XX % 2 ==0)              // para tener los niveles de gris exactos, para
        tamXX = StrToInt(EditW->Text)/2;//entero---  // la creación del mismo.
        else
        tamXX = (StrToInt(EditW->Text)/2)+1;//racional
        }

}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditHChange(TObject *Sender)
{
 YY= StrToInt(EditH->Text); // YY toma el valor que eliga el usuario
 tamYY = StrToInt(EditH->Text)/2;  //tamYY dividido entre 2, da el número de niveles de gris
                         // en el vector de colores que se muestra al usuario
                         //correspondientes según el ancho del EE.
                         // para esto puede ser tamXX o tamYY ya que se toma el minimo valor}
                         // para mantener los niveles de gris


        if(Rectangulo->Checked==true)    // si creamos un rectangulo como EE
        {                                // se procura tener valores enteros y no racionales
        if(YY % 2== 0)                   //para tener los nivels de gris exactos, para la creación del mismo.
          tamYY = (StrToInt(EditH->Text)/2);
        else
          tamYY = (StrToInt(EditH->Text)/2)+1;
        }

}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditGChange(TObject *Sender)
{
    UpDownG->Max;
    G= StrToInt (EditG->Text);

}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditVertChange(TObject *Sender)
{
 numver= StrToInt(EditVert->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditSChange(TObject *Sender)
{
 Start = StrToInt(EditS->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditEChange(TObject *Sender)
{
 End= StrToInt(EditE->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::EditRChange(TObject *Sender)
{
/*
if(RadioGroupCustomize->ItemIndex==0 && StrToInt(EditR->Text)==0 && CheckBoxCompositeSE->Checked==true){
RadioButtonForeground->Visible=true;
RadioButtonBackground->Visible=true;
LabelForeground->Visible=false;
LabelBackground->Visible=false;
}
else if(RadioGroupCustomize->ItemIndex==0 && StrToInt(EditR->Text)!=0 && CheckBoxCompositeSE->Checked==true){
RadioButtonForeground->Visible=false;
RadioButtonBackground->Visible=false;
LabelForeground->Visible=true;
LabelBackground->Visible=true;
}   */
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownWClick(TObject *Sender, TUDBtnType Button)
{
 EditWChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownHClick(TObject *Sender, TUDBtnType Button)
{
 EditHChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownVClick(TObject *Sender, TUDBtnType Button)
{
 EditVertChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownGClick(TObject *Sender, TUDBtnType Button)
{
 EditGChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownSClick(TObject *Sender, TUDBtnType Button)
{
 EditSChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownEClick(TObject *Sender, TUDBtnType Button)
{
 EditEChange(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::UpDownRClick(TObject *Sender, TUDBtnType Button)
{
// EditRChange(this);
RotationEE();
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::ImagecMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
/*Label3->Caption= X; // el valor se divide por el tamaño de la celda,
Label6->Caption= Y;

TColor tc;
tc= Imagec->Canvas->Pixels[X][Y];
Label7->Caption= AnsiString(GetRValue(tc));
Label8->Caption= AnsiString(GetGValue(tc));
Label9->Caption= AnsiString(GetBValue(tc));*/

}
//---------------------------------------------------------------------------

void __fastcall TFSEB::FormClickAction(TObject *Sender)
{
TRect TheRect;
 int value =Green( ( (TPanel *) Sender )->Color );
 lblevel->Caption=(AnsiString( value ) ) ;

 currentColor = ( (TPanel *) Sender )->Color ;

 // Si voy a crear algún EE que no sea irregular, anillo, elipse, rectangulo
   if(Rectangulo->Checked==false)
   {
       if(cc <= tamLevel-1)// tamLevel viene de TamvalChange
       {
         ImgLevel->Canvas->Brush->Color= (TColor)RGB(value,value,value);//le da el nivel del gris a la celda
         ImgLevel->Canvas->Rectangle(cc*16,0*15,(cc+1)*16-1,(0+1)*15-1);//de la linea de niveles
         vc[cc]= (TColor)RGB(value,value,value); // ese nivel se guarda en un arreglo
         //Pinta el numero de nivel de la linea de niveles
         TheRect = Rect(cc*16,0*15,(cc+1)*16-1,(0+1)*15-1);//crea el rectangulo
         ImgNLevel->Canvas->TextRect(TheRect, cc*16+1, 0*15+2, value);
         // pinta el rectangulo, (x,y), y el texto(x,y)
         cc++;
        }
        else
        {
          MessageBeep(0);
          //Application->MessageBox("                -----Element Full-----\n   For new values push **Clean Level**", "Alert!", MB_OK);
            Application->MessageBox("                *****The element is full*****\n   if you want to put new values put clean level", "Warning!", MB_OK);
         }

    }



     if(Rectangulo->Checked==true)
   {
      tamXY = min(tamXX,tamYY); // se toma el valor minimo ya que con este llenaremos la linea de niveles

       if(cc <= tamXY-1)
       {
         ImgLevel->Canvas->Brush->Color= (TColor)RGB(value,value,value);
         ImgLevel->Canvas->Rectangle(cc*16,0*15,(cc+1)*16-1,(0+1)*15-1);
         vc[cc]= (TColor)RGB(value,value,value);
         //Pinta el numero de nivel de la linea de niveles
         TheRect = Rect(cc*16,0*15,(cc+1)*16-1,(0+1)*15-1);
         ImgNLevel->Canvas->TextRect(TheRect, cc*16+1, 0*15+2, value);

         cc++;
       }
        else
        {
         MessageBeep(0);
         //Application->MessageBox("                -----Element Full-----\n   For new values push **Clean Level**", "Alert!", MB_OK);
           Application->MessageBox("                *****The element is full*****\n   if you want to put new values put clean level", "Warning!", MB_OK);
        }

    }


}
//---------------------------------------------------------------------------




void __fastcall TFSEB::FormClose(TObject *Sender, TCloseAction &Action)
{
/*        if (Irregulares->Checked==true)
        {
        EE->Width =tam;
        EE->Height=tam;
        EE->Assign(PixEE);
         PixEE->FreeImage();
         delete PixEE;
        }      */
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO:CrearClick
OBJETIVO: Crear un elemento de estrutura regular
PARAMETROS: salida vacio, entrada TObject *Sender
NOTAS: Imagec es la que tomamos como EE, e ImageB es copia de Imagec que se
        se la presentamos al usuario
******************************************************************************/

void __fastcall TFSEB::SBCreateClick(TObject *Sender)
{
//Limpio todo antes de crear un ee nuevo
 EE->Width = tam;
 EE->Height = tam;

  ImageB->Canvas->Brush->Color=clWhite;
  ImageB->Canvas->Pen->Color=clBlack;
  ImageB->Canvas->Rectangle(0,0,ImageB->Width,ImageB->Height);
  EE->Canvas->Brush->Color=clWhite;
  EE->Canvas->Rectangle(0,0,tam,tam);


        for(int i= 0; i < tam; i++)//h, y
            for(int j= 0; j < tam; j++)//w, x
                  EE->Canvas->Pixels[i][j]=clWhite;

        for(int i= 0; i < Imagec->Height; i++)
           for(int j= 0; j < Imagec->Width; j++)
                    Imagec->Canvas->Pixels[i][j]=clWhite;

tam=StrToInt(Tamval->Text);
ox=StrToInt(EditX->Text);
oy=StrToInt(EditY->Text);
//Limpio lo nuevo
 EE->Width = tam;
 EE->Height = tam;

  ImageB->Canvas->Brush->Color=clWhite;
  ImageB->Canvas->Pen->Color=clBlack;
  ImageB->Canvas->Rectangle(0,0,ImageB->Width,ImageB->Height);
  EE->Canvas->Brush->Color=clWhite;
  EE->Canvas->Rectangle(0,0,tam,tam);


        for(int i= 0; i < tam; i++)//h, y
            for(int j= 0; j < tam; j++)//w, x
                  EE->Canvas->Pixels[i][j]=clWhite;

        for(int i= 0; i < Imagec->Height; i++)
           for(int j= 0; j < Imagec->Width; j++)
                    Imagec->Canvas->Pixels[i][j]=clWhite;

//4-connected A
if(FSEB->RadioGroupSkeletons->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected A SK";


       // crea 4-connected A en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[0][2]=clBlack;
       EE->Canvas->Pixels[1][2]=clBlack;
       EE->Canvas->Pixels[2][2]=clBlack;
}
//4-connected B
if(FSEB->RadioGroupSkeletons->ItemIndex==1 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected B SK";


       // crea 4-connected B en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[0][1]=clBlack;
       EE->Canvas->Pixels[0][2]=clBlack;
       EE->Canvas->Pixels[1][2]=clBlack;
}
//8-connected A
if(FSEB->RadioGroupSkeletons->ItemIndex==2 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "8-connected A SK";


       // crea 8-connected A en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[0][0]=clAqua;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][0]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[0][2]=clBlack;
       EE->Canvas->Pixels[1][2]=clBlack;
       EE->Canvas->Pixels[2][2]=clBlack;
}
//8-connected B
if(FSEB->RadioGroupSkeletons->ItemIndex==3 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "8-connected B SK";


       // crea 8-connected B en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][0]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[0][1]=clBlack;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[1][2]=clBlack;
}
//4-connected Poda
if(FSEB->RadioGroupPruning->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected P";


       // crea 4-connected en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//8-connected A Poda
if(FSEB->RadioGroupPruning->ItemIndex==1 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "8-connected A P";


       // crea 8-connected A en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[0][0]=clAqua;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[0][2]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//8-connected B Poda
if(FSEB->RadioGroupPruning->ItemIndex==2 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "8-connected B P";


       // crea 8-connected B en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[0][0]=clAqua;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[0][2]=clAqua;
       EE->Canvas->Pixels[1][2]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//4-connected isolated
if(FSEB->RadioGroupInsolatedpoints->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected I";


       // crea 4-connected en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][2]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//8-connected isolated
if(FSEB->RadioGroupInsolatedpoints->ItemIndex==1 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "8-connected I";


       // crea 8-connected en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[0][0]=clAqua;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[0][2]=clAqua;
       EE->Canvas->Pixels[1][2]=clAqua;
       EE->Canvas->Pixels[2][2]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//4-connected A Endpoints
if(FSEB->RadioGroupEndpoints->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected A EP";


       // crea 4-connected A en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
}
//4-connected B Endpoints
if(FSEB->RadioGroupEndpoints->ItemIndex==1 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected B EP";


       // crea 4-connected B en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[1][2]=clAqua;
}
//4-connected C Endpoints
if(FSEB->RadioGroupEndpoints->ItemIndex==2 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected D EP";


       // crea 4-connected D en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[2][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[1][2]=clAqua;
}
//4-connected D Endpoints
if(FSEB->RadioGroupEndpoints->ItemIndex==3 && FSEB->CheckBoxCompositeSE->Checked==true){
        tam=3;
        oy=1;
        ox=1;
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "4-connected C EP";


       // crea 4-connected C en la imagen
       EE->Width = tam;
       EE->Height = tam;
       EE->Canvas->Pixels[1][0]=clAqua;
       EE->Canvas->Pixels[0][1]=clAqua;
       EE->Canvas->Pixels[1][1]=clBlack;
       EE->Canvas->Pixels[1][2]=clAqua;
}
//EEC Personalizado
if (RadioGroupCustomize->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true)
{
      PixEEC->Width= tam;
      PixEEC->Height=tam;
      EE->Width = tam;
      EE->Height = tam;

        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "Customize";
        EE->Assign(PixEEC);

      for(int i= 0; i < tam; i++){
            for(int j= 0; j < tam; j++){
                EE->Canvas->Pixels[i][j]=PixEEC->Canvas->Pixels[i][j];
                }
            }
}

//********************ELIJO EE CUADRO********************************
if (Cuadro->Checked==true && FSEB->CheckBoxCompositeSE->Checked==false)// crea el EE de forma cuadrada
{
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EE->Width = tam;
        EE->Height = tam;
        EEType= "Square";


         if (ChbLevel->Checked==true)// PARA EE CUADRADO GRIS
         {
              // crea el cuadrado en el editor
              EE->Canvas->Brush->Color= clWhite;
              EE->Canvas->Rectangle(0,0,tam,tam);
               if(tamLevel>15)
               tamLevel=15;
              InvGray(tamLevel);// invierte los niveles de gris del EE

             // Pinta cada celda del nivel de gris correspondiente
             // según el orden del arreglo de niveles de gris
             for(int a=0; a < tamLevel; a++) // va pintado celda por celda
             {
                 if (chkInv->Checked == true) // si chkInv es verdadero, tiene la misma forma el EE
                 {                            // pero invierte los niveles de gris.
                   EE->Canvas->Pen->Color = vcc[a]; // vcc[] es el arreglo que contiene
                   EE->Canvas->Brush->Color= vcc[a];// los niveles de gris invertidos
                 }
                 else // sino pone los niveles de gris en la forma en que lo pide el usuario
                 {
                  EE->Canvas->Pen->Color = vc[a]; // vc[] es el arreglo que contiene
                  EE->Canvas->Brush->Color= vc[a]; // los niveles de gris normales
                 }
             EE->Canvas->Rectangle(0+a, 0+a, tam-a,tam-a);// va pintando las celdas del EE
            }
         }else
            {   //PARA EE CUADRADO BINARIO

                EE->Canvas->Brush->Color= clBlack;   // color de la imagen
                EE->Canvas->Rectangle(0,0,tam,tam); //pinta un rectangulo
            }
}

//************************ELIGO EE CIRCULO**********************************
if (Circulo->Checked==true && FSEB->CheckBoxCompositeSE->Checked==false)
{
        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        EEType= "Circle";

    if (ChbLevel->Checked==true)// para EE circulo gris
    {
         if(tamLevel>15)
               tamLevel=15;
        // crea circulos en la imagen
        EE->Width = tam;
        EE->Height = tam;
        EE->Canvas->Brush->Color= clWhite;
        EE->Canvas->Ellipse(0, 0, tam, tam);

        InvGray(tamLevel);// invierte los niveles de gris del EE

        for(int a=0; a < tamLevel; a++)
        {
           if (chkInv->Checked == true)
           {
                EE->Canvas->Pen->Color = vcc[a];
                EE->Canvas->Brush->Color= vcc[a];
           }
           else
           {
               EE->Canvas->Pen->Color = vc[a];
               EE->Canvas->Brush->Color= vc[a];
           }
               EE->Canvas->Ellipse(0+a,0+a,tam-a,tam-a);
        }
     }
     else //para el circulo binario
     {
       // crea circulos en la imagen
        EE->Width = tam;
        EE->Height = tam;
        EE->Canvas->Brush->Color = clBlack;
        EE->Canvas->Ellipse(0, 0, tam, tam);
     }
}



//***********************ELIGO EE RECTANGULO**********************************

if (Rectangulo->Checked==true && FSEB->CheckBoxCompositeSE->Checked==false)
{
      //asigna a tam el maximo valor, esto se hizo con la intención de
      //que se pudiera presentar un rectangulo vertical u horizontal
        tam = (int)max2(XX,YY);

        ctam = ImageB->Width / tam;//tamaño de las celdas del editor de EE
        // crea el rectangulo en la imagen

        vx= ((100-XX)/2)+1;
        vy= ((100-YY)/2)+1;
        EEType= "Rectangle";

    if (ChbLevel->Checked==true)// para EE rectangulo gris
    {

        EE->Width = tam;//XX;
        EE->Height = tam;//YY;
        EE->Canvas->Brush->Color = clWhite;
        //EE->Canvas->Rectangle(0, 0, XX, YY); //XX,YY
        if(tamXY>15)
               tamXY=15;
        InvGray(tamXY);// invierte los niveles de gris del EE

        for(int a=0; a < tamXY; a++)
        {
             if (chkInv->Checked == true)
             {
                EE->Canvas->Pen->Color = vcc[a];
                EE->Canvas->Brush->Color= vcc[a];
             }
             else
             {
               EE->Canvas->Pen->Color = vc[a];
               EE->Canvas->Brush->Color= vc[a];
             }
           // EE->Canvas->Rectangle(0+a,0+a,XX-a,YY-a);
        if(XX>YY)
        EE->Canvas->Rectangle(0+a, 0+((tam/2)-YY/2)+a, XX-a, YY+((tam/2)-YY/2)-a);  //XX,YY
        if(YY>XX)
        EE->Canvas->Rectangle(0+((tam/2)-XX/2)+a, 0+a, XX+((tam/2)-XX/2)-a, YY-a);
        }
    }
    else
    {
        EE->Width = tam;
        EE->Height = tam;
        EE->Canvas->Brush->Color = clBlack;
        if(XX>YY)
        EE->Canvas->Rectangle(0, 0+((tam/2)-YY/2), XX, YY+((tam/2)-YY/2));  //XX,YY
        if(YY>XX)
        EE->Canvas->Rectangle(0+((tam/2)-XX/2), 0, XX+((tam/2)-XX/2), YY);
    }
   // tam=StrToInt(Tamval->Text);
}



ComplementodeEEenlasImagenes();
AUXEE->Assign(EE);
DibujaEEenlasImagenes();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFSEB::ComplementodeEEenlasImagenes(void)//APLICACION
{
       if(CheckBoxComplement->Checked==true && CheckBoxCompositeSE->Checked==false){
        for(int i=0;i<tam;i++){
                for(int j=0;j<tam;j++){
                        if(EE->Canvas->Pixels[i][j]==clWhite){EE->Canvas->Pixels[i][j]=clBlack;}
                        else if(EE->Canvas->Pixels[i][j]==clBlack){EE->Canvas->Pixels[i][j]=clWhite;}
                }
        }
       }
       else if(CheckBoxComplement->Checked==true &&CheckBoxCompositeSE->Checked==true){
        for(int i=0;i<tam;i++){
                for(int j=0;j<tam;j++){
                        if(EE->Canvas->Pixels[i][j]==clAqua){EE->Canvas->Pixels[i][j]=clBlack;}
                        else if(EE->Canvas->Pixels[i][j]==clBlack){EE->Canvas->Pixels[i][j]=clAqua;}
                }
        }

       }
}
//---------------------------------------------------------------------------
void TFSEB::DibujaEEenlasImagenes(void)//APLICACION
{
       Imagec->Canvas->Draw(vx,vy,EE);
       if(FSEB->CheckBoxCompositeSE->Checked==true){DrawBiCompositeSE();}
       else{
       if (ChbLevel->Checked==true){DrawGray();}
       else{DrawBi();}
       }
}
//---------------------------------------------------------------------------
/******************************************************************************
METODO: BCleanClick
OBJETIVO: Limpiar la Imagec e ImageB, y dejarla con las celdas actuales limpias
PARAMETROS: salir vaciar, entrada TObject
******************************************************************************/

void __fastcall TFSEB::SBCleanClick(TObject *Sender)
{
    EditR->Text=0;
    ctam = ImageB->Width / tam; //tamaño de la celda en el momento
    vx= ((100-tam)/2)+1;
    vy= ((100-tam)/2)+1;

   if (RadioGroupCustomize->ItemIndex==0 && FSEB->CheckBoxCompositeSE->Checked==true)
   {
      PixEEC= new Graphics::TBitmap();
      PixEEC->Width= tam;
      PixEEC->Height=tam;
   }


        EE->Width = tam;
        EE->Height = tam;

        ImageB->Canvas->Brush->Color=clWhite;
        ImageB->Canvas->Pen->Color=clBlack;
        ImageB->Canvas->Rectangle(0,0,ImageB->Width,ImageB->Height);

        for(int i= 0; i < tam; i++){//h, y
            for(int j= 0; j < tam; j++){//w, x

                 ImageB->Canvas->Pen->Color=clBlack;
                 ImageB->Canvas->Rectangle(j*ctam,i*ctam,(j+1)*ctam-1,(i+1)*ctam-1);
                 EE->Canvas->Pixels[j][i]=clWhite;
            }
        }

        for(int i= 0; i < Imagec->Width; i++)
           for(int j= 0; j < Imagec->Height; j++)

                     Imagec->Canvas->Pixels[j][i]=clWhite;

}
//---------------------------------------------------------------------------

void __fastcall TFSEB::SBFDGClick(TObject *Sender)
{
        ctam = ImageB->Width / tam;
        vx= ((100-tam)/2)+1;
        vy= ((100-tam)/2)+1;
        int valmin, valmax;

        Graphics::TBitmap *auxfd= new Graphics::TBitmap();
        auxfd->Width= tam;
        auxfd->Height= tam;

        auxfd->Assign(EE);

        AUXEE = Morpho->FunDist(auxfd);
        valmax = Morpho->Max(AUXEE);
        valmin = Morpho->Min(AUXEE);
        EE= Morpho->formula(valmin, valmax, AUXEE);

        Imagec->Canvas->Draw(vx,vy,EE);

        DrawGray();

        auxfd->FreeImage();
        delete auxfd;

}
//---------------------------------------------------------------------------
AnsiString TFSEB::datType()
{
  return EEType;
}
AnsiString TFSEB::datH()
{
  if(Rectangulo->Checked==true)
  return YY; // alto de la elipse o rectangulo

 return tam; // tamaño del elemento

}
AnsiString TFSEB::datW()
{
   if(Rectangulo->Checked==true)
   return XX;


 return tam;
}
//---------------------------------------------------------------------------
 int TFSEB::max2(int a,int b)
 {
 if(a>b)
 return a;
 else
 return b;
 }
 int TFSEB::min(int a,int b)
 {
 if(a<b)
 return a;
 else
 return b;
 }
 int TFSEB::getPlane()
 {
 if(CheckBox1->Checked==true&&CheckBox2->Checked==false&&CheckBox3->Checked==false)
 {
 return 1;
 }
 if(CheckBox1->Checked==false&&CheckBox2->Checked==true&&CheckBox3->Checked==false)
 {
 return 2;
 }
 if(CheckBox1->Checked==false&&CheckBox2->Checked==false&&CheckBox3->Checked==true)
 {
 return 3;
 }
if(CheckBox1->Checked==false&&CheckBox2->Checked==false&&CheckBox3->Checked==false)
 {
 return 2;
 }
 else{
 return 2;
 }
 }

 int TFSEB::getTam()
 {
 return tam;
 }
 int TFSEB::getWidth()
 {
 return XX;
 }
 int TFSEB::getHeight()
 {
 return YY;
 }
void __fastcall TFSEB::BitBtnOKClick(TObject *Sender)
{
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::CheckBoxCompositeSEClick(TObject *Sender)
{
if(FSEB->CheckBoxCompositeSE->Checked==false){
RadioButtonForeground->Visible=false;
RadioButtonBackground->Visible=false;
LabelBackground->Visible=false;
LabelForeground->Visible=false;
FSEB->RadioGroupSkeletons->Visible=false;
FSEB->RadioGroupPruning->Visible=false;
FSEB->RadioGroupInsolatedpoints->Visible=false;
FSEB->RadioGroupEndpoints->Visible=false;
FSEB->RadioGroupCustomize->Visible=false;
FSEB->GroupBox2->Visible=true;
FSEB->Cuadro->Visible=true;
FSEB->Rectangulo->Visible=true;
FSEB->Circulo->Visible=true;









if (Cuadro->Checked==true){CuadroClick(Sender);}
else if (Rectangulo->Checked==true){RectanguloClick(Sender);}
else if (Circulo->Checked==true){CirculoClick(Sender);}
ChbLevel->Visible=true;
if(ChbLevel->Checked==true){FSEB->Width = 712;}
else{FSEB->Width = 439;}
}
else{
if(RadioGroupCustomize->ItemIndex==0){
ActivaPropiedadesEEC();}
else{DesactivaPropiedadesEE();}
FSEB->Width = 439;
ChbLevel->Visible=false;
FSEB->GroupBox2->Visible=false;
FSEB->Cuadro->Visible=false;
FSEB->Rectangulo->Visible=false;

FSEB->RadioGroupSkeletons->Visible=true;
FSEB->RadioGroupPruning->Visible=true;
FSEB->RadioGroupInsolatedpoints->Visible=true;
FSEB->RadioGroupEndpoints->Visible=true;
FSEB->RadioGroupCustomize->Visible=true;
}
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::RadioGroupSkeletonsClick(TObject *Sender)
{
DesactivaPropiedadesEE();
FSEB->RadioGroupPruning->ItemIndex=-1;
FSEB->RadioGroupInsolatedpoints->ItemIndex=-1;
FSEB->RadioGroupEndpoints->ItemIndex=-1;
FSEB->RadioGroupCustomize->ItemIndex=-1;
EditR->Text=0;
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::RadioGroupPruningClick(TObject *Sender)
{
DesactivaPropiedadesEE();
FSEB->RadioGroupSkeletons->ItemIndex=-1;
FSEB->RadioGroupInsolatedpoints->ItemIndex=-1;
FSEB->RadioGroupEndpoints->ItemIndex=-1;
FSEB->RadioGroupCustomize->ItemIndex=-1;
EditR->Text=0;
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::RadioGroupInsolatedpointsClick(TObject *Sender)
{
DesactivaPropiedadesEE();
FSEB->RadioGroupSkeletons->ItemIndex=-1;
FSEB->RadioGroupPruning->ItemIndex=-1;
FSEB->RadioGroupEndpoints->ItemIndex=-1;
FSEB->RadioGroupCustomize->ItemIndex=-1;
EditR->Text=0;
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFSEB::RadioGroupCustomizeClick(TObject *Sender)
{
ActivaPropiedadesEEC();
FSEB->RadioGroupSkeletons->ItemIndex=-1;
FSEB->RadioGroupPruning->ItemIndex=-1;
FSEB->RadioGroupInsolatedpoints->ItemIndex=-1;
FSEB->RadioGroupEndpoints->ItemIndex=-1;
EditR->Text=0;
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------
void TFSEB::DesactivaPropiedadesEE(void)
{
    RadioButtonBackground->Visible=false;
    RadioButtonForeground->Visible=false;
    LabelForeground->Visible= true;
    LabelBackground->Visible= true;
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblSizeEE->Visible= false;
    Tamval->Visible= false;
    UpDownT->Visible= false;
    lblx->Visible= false;
    EditX->Visible= false;
    UpDownX->Visible= false;
    lbly->Visible= false;
    EditY->Visible= false;
    UpDownY->Visible= false;
    ImgLevel->Visible= false;
    ImgNLevel->Visible= false;
    cmdCleanL->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    EditR->Visible=true;
    UpDownR->Visible=true;
    LblRote->Visible=true;
    Label8->Visible=false;
}
//---------------------------------------------------------------------------
void TFSEB::ActivaPropiedadesEEC(void)
{
    if(RadioGroupCustomize->ItemIndex==0 && CheckBoxCompositeSE->Checked==true){
        RadioButtonForeground->Visible=true;
        RadioButtonBackground->Visible=true;
        LabelForeground->Visible= false;
        LabelBackground->Visible= false;
        }
    else{RadioButtonForeground->Visible=false;
        RadioButtonBackground->Visible=false;
        }
    LblStart->Visible= false;
    EditS->Visible= false;
    UpDownS->Visible= false;
    LblEnd->Visible= false;
    EditE->Visible= false;
    UpDownE->Visible= false;
    EditVert->Visible= false;
    UpDownV->Visible= false;
    lblvertice->Visible= false;
    lblSizeEE->Visible= true;
    Tamval->Visible= true;
    UpDownT->Visible= true;
    lblGrosor->Visible= false;
    EditG->Visible= false;
    UpDownG->Visible= false;
    lblAncho->Visible= false;
    EditW->Visible= false;
    UpDownW->Visible= false;
    lblAlto->Visible= false;
    EditH->Visible= false;
    UpDownH->Visible= false;
    lblx->Visible= true;
    EditX->Visible= true;
    UpDownX->Visible= true;
    lbly->Visible= true;
    EditY->Visible= true;
    UpDownY->Visible= true;
    ImgLevel->Visible= false;
    ImgNLevel->Visible= false;
    cmdCleanL->Visible= false;
    Label8->Visible=false;
    EditR->Visible=true;
    UpDownR->Visible=true;
    LblRote->Visible=true;
}

//---------------------------------------------------------------------------
void TFSEB::RotaEE(void)
{
 Grado = StrToInt(EditR->Text);

 W= EE->Width;
 H= EE->Height;

         switch(Grado)
         {
          case 0:{ for(int i=0; i< H; i++)
                    for(int j=0; j< W; j++)
                      EE->Canvas->Pixels[i][j]= AUXEE->Canvas->Pixels[i][j];
                      ImageB->Tag=Grado;
                      break;
                  }

          case 90:{  for(int i=0; i< H; i++)
                      for(int j=0; j< W; j++)
                      EE->Canvas->Pixels[j][W-i-1]=AUXEE->Canvas->Pixels[i][j];
                      ImageB->Tag=Grado;
                        break;
                   }
          case 180:{
                   for(int i=0; i< H; i++)
                      for(int j=0; j< W; j++)
                       EE->Canvas->Pixels[W-i-1][H-j-1]=AUXEE->Canvas->Pixels[i][j];
                       ImageB->Tag=Grado;
                        break;
                    }
          case 270:
                   { for(int i=0; i< H; i++)
                      for(int j=0; j< W; j++)
                       EE->Canvas->Pixels[H-j-1][i]=AUXEE->Canvas->Pixels[i][j];
                       ImageB->Tag=Grado;
                         break;
                    }
         }


       

       if(RadioGroupCustomize->ItemIndex==0 && CheckBoxCompositeSE->Checked==true){
                PixEEC->Assign(EE);
                if(CheckBoxComplement->Checked==true && CheckBoxCompositeSE->Checked==true){
                for(int i=0;i<tam;i++){
                for(int j=0;j<tam;j++){
                        if(PixEEC->Canvas->Pixels[i][j]==clAqua){PixEEC->Canvas->Pixels[i][j]=clBlack;}
                        else if(PixEEC->Canvas->Pixels[i][j]==clBlack){PixEEC->Canvas->Pixels[i][j]=clAqua;}
                }
                }
                }
       }
       AUXEE->Assign(EE);
       DibujaEEenlasImagenes();
}
//---------------------------------------------------------------------------

void TFSEB::RotationEE(void)
{
 Grado = StrToInt(EditR->Text);
 W= EE->Width;
 H= EE->Height;
 char giro=' ';
          switch(Grado)
         {
          case 0:{
                if((ImageB->Tag==270)){giro='D';}
                else if((ImageB->Tag==90)){giro='I';}
                ImageB->Tag=Grado;
                break;
           }
          case 90:{
                if((ImageB->Tag==0)){giro='D';}
                else if((ImageB->Tag==180)){giro='I';}
                ImageB->Tag=Grado;
                break;
          }
          case 180:{
                if((ImageB->Tag==90)){giro='D';}
                else if((ImageB->Tag==270)){giro='I';}
                ImageB->Tag=Grado;
                   break;
                   }
          case 270:{
                if((ImageB->Tag==180)){giro='D';}
                else if((ImageB->Tag==0)){giro='I';}
                ImageB->Tag=Grado;
                break;
         }
       }
       if(giro=='D'){
        for(int i=0; i< H; i++)
         for(int j=0; j< W; j++)
          EE->Canvas->Pixels[j][(W-1)-i]=AUXEE->Canvas->Pixels[i][j];}
       else if(giro=='I'){
        for(int i=0; i< H; i++)
         for(int j=0; j< W; j++)
          EE->Canvas->Pixels[(H-1)-j][i]=AUXEE->Canvas->Pixels[i][j];}

       if(giro=='D' || giro=='I'){


       if(RadioGroupCustomize->ItemIndex==0 && CheckBoxCompositeSE->Checked==true){
                PixEEC->Assign(EE);
                if(CheckBoxComplement->Checked==true && CheckBoxCompositeSE->Checked==true){
                for(int i=0;i<tam;i++){
                for(int j=0;j<tam;j++){
                        if(PixEEC->Canvas->Pixels[i][j]==clAqua){PixEEC->Canvas->Pixels[i][j]=clBlack;}
                        else if(PixEEC->Canvas->Pixels[i][j]==clBlack){PixEEC->Canvas->Pixels[i][j]=clAqua;}
                }
                }
                }
       }
       }

       AUXEE->Assign(EE);
       DibujaEEenlasImagenes();
}
//---------------------------------------------------------------------------
void __fastcall TFSEB::RadioGroupEndpointsClick(TObject *Sender)
{
DesactivaPropiedadesEE();
FSEB->RadioGroupSkeletons->ItemIndex=-1;
FSEB->RadioGroupPruning->ItemIndex=-1;
FSEB->RadioGroupInsolatedpoints->ItemIndex=-1;
FSEB->RadioGroupCustomize->ItemIndex=-1;
EditR->Text=0;
SBCreateClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TFSEB::CheckBoxAllplanesClick(TObject *Sender)
{
if(CheckBoxAllplanes->Checked==true){
CheckBox1->Checked=true;
CheckBox2->Checked=true;
CheckBox3->Checked=true;
CheckBox1->Enabled=false;
CheckBox2->Enabled=false;
CheckBox3->Enabled=false;
}
else if(CheckBoxAllplanes->Checked==false){
CheckBox1->Checked=false;
CheckBox2->Checked=true;
CheckBox3->Checked=false;
CheckBox1->Enabled=true;
CheckBox2->Enabled=true;
CheckBox3->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TFSEB::CheckBoxComplementClick(TObject *Sender)
{
SBCreateClick(Sender);        
}
//---------------------------------------------------------------------------





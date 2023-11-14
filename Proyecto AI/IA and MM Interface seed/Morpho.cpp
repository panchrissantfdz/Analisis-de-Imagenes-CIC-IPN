//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
//#include <algorithm.h>

#pragma hdrstop

#include "Morpho.h"
#include "ElemStrucBi.h"
#include <math.hpp>

/********************************************
Implementación de Clase Morfología Matemática
*********************************************/

//************MÉTODO DE EROSIÓN BINARIA******************************************************************************

Graphics::TBitmap * TMorpho::erodeB(Graphics::TBitmap *imgO,Graphics::TBitmap *EE, int ox, int oy )
{ //start erode

Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgO);
int **bmpIn,**se;

 bmpIn = new int*[imgO->Width];  //col
  for (int j= 0; j < imgO->Width; j++)
      bmpIn[j] = new int[imgO->Height]; //ren


 for (int x=0; x < imgO->Width; x++) //columnas
    for (int y=0; y< imgO->Height; y++)//filas
     {
         int rr =GetRValue(imgO->Canvas->Pixels[x][y]);
         int gg =GetGValue(imgO->Canvas->Pixels[x][y]);
         int bb =GetBValue(imgO->Canvas->Pixels[x][y]);
         int rgb = (rr+bb+gg)/3;

       bmpIn[x][y]= rgb;
     }

  se = new int*[EE->Width];  //ren
  for (int j= 0; j < EE->Width; j++)
      se[j] = new int[EE->Height]; //col


  for (int c=0; c< EE->Width; c++)//x col
     for (int r=0; r < EE->Height; r++) //y ren
     {
         int rr =GetRValue(EE->Canvas->Pixels[c][r]);
         int gg =GetGValue(EE->Canvas->Pixels[c][r]);
         int bb =GetBValue(EE->Canvas->Pixels[c][r]);
         int rgb = (rr+gg+bb)/3;

       se[c][r]= rgb;//(rr+gg+bb)/3;
     }

int y, x, xx, yy;
for(x = 0; x < imgO->Width; x++){  //columna
   for(y = 0; y < imgO->Height; y++){   //fila

     if(bmpIn[x][y]== 0){
             //fila         columna
        int col= x-ox, ren= y - oy;

           for(xx=0; xx < EE->Width; xx++){//columna
             for(yy=0; yy< EE->Height; yy++){   //fila
              if(se[xx][yy]== 0)
              imgD->Canvas->Pixels[col+xx][ren+yy] = clBlack;
           }//finfor4
          }//finfor3
     }//finif

   }//finfor2
 }//finfor1

delete bmpIn;
delete se;

return imgD;
}// finerode

//************MÉTODO DE DILATACION BINARIA*******************************************************************

Graphics::TBitmap * TMorpho::dilateB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy){

Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgO);

int **bmpIn,**se;

 bmpIn = new int*[imgO->Width];  //col
  for (int j= 0; j < imgO->Width; j++)
      bmpIn[j] = new int[imgO->Height]; //ren


 for (int x=0; x < imgO->Width; x++) //columnas
    for (int y=0; y< imgO->Height; y++)//filas
     {
         int rr =GetRValue(imgO->Canvas->Pixels[x][y]);
         int gg =GetGValue(imgO->Canvas->Pixels[x][y]);
         int bb =GetBValue(imgO->Canvas->Pixels[x][y]);
         int rgb = (rr+bb+gg)/3;

       bmpIn[x][y]= rgb;
     }

  se = new int*[EE->Width];  //ren
  for (int j= 0; j < EE->Width; j++)
      se[j] = new int[EE->Height]; //col


  for (int c=0; c< EE->Width; c++)//x col
     for (int r=0; r < EE->Height; r++) //y ren
     {
         int rr =GetRValue(EE->Canvas->Pixels[c][r]);
         int gg =GetGValue(EE->Canvas->Pixels[c][r]);
         int bb =GetBValue(EE->Canvas->Pixels[c][r]);
         int rgb = (rr+gg+bb)/3;

       se[c][r]= rgb;//(rr+gg+bb)/3;
     }

int y, x, xx, yy;
for(x = 0; x < imgO->Width; x++){  //columna
   for(y = 0; y < imgO->Height; y++){   //fila

     if(bmpIn[x][y]== 255){
             //fila         columna
        int col= x-ox, ren= y - oy;

           for(xx=0; xx < EE->Width; xx++){//columna
             for(yy=0; yy< EE->Height; yy++){   //fila
              if(se[xx][yy]== 0)
              imgD->Canvas->Pixels[col+xx][ren+yy] = clWhite;
           }//finfor4
          }//finfor3
     }//finif

   }//finfor2
 }//finfor1



 delete bmpIn;
 delete se;

 return imgD;
}

//************MÉTODO DE APERTURA BINARIA****************************************************************
Graphics::TBitmap * TMorpho::openingB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy){

Graphics::TBitmap *imgD1= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *imgD2= new Graphics::TBitmap();  // creo un bitmap destino2

imgD1->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD1->Width= imgO->Width ;
imgD2->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD2->Width= imgO->Width ;
//erosión y dilatación

imgD1= erodeB(imgO, EE, ox, oy);
imgD2= dilateB(imgD1, EE,ox, oy);

return imgD2;
}

//************MÉTODO DE CLAUSURA BINARIA********************************************************************
Graphics::TBitmap * TMorpho::closingB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy){

Graphics::TBitmap *imgD1= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *imgD2= new Graphics::TBitmap();  // creo un bitmap destino2

imgD1->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD1->Width= imgO->Width ;
imgD2->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD2->Width= imgO->Width ;
//dilatación y erosión

imgD1= dilateB(imgO, EE,ox, oy);
imgD2= erodeB(imgD1, EE, ox, oy);

return imgD2;
}
//************MÉTODO DE BORDE EXTERIOR BINARIO***************************************************************
Graphics::TBitmap * TMorpho::bextB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy){
// imagen dilatada- imagen original


}

//************MÉTODO DE BORDE INTERIOR BINARIO***********************************************************

Graphics::TBitmap * TMorpho::bintB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
//imagen original -  imagen erosionada


}

//************MÉTODO DE GRADIENTE BINARIO************************************************************************

Graphics::TBitmap * TMorpho::gradmB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy){
// borde exterior - borde interior

}
//************TOP HAT BINARIO********************************************************************
Graphics::TBitmap * TMorpho::topHatB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *imgA= new Graphics::TBitmap();  // creo un bitmap destino1
//imagen original - apertura de imagen original

imgD->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD->Width= imgO->Width ;

imgA->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgA->Width= imgO->Width ;

imgA = openingB(imgO, EE, ox, oy);

for(int y=0; y<= imgD->Height; y++){//renglon
  for(int x=0; x<=imgD->Width; x++){//columnas

 imgD->Canvas->Pixels[x][y]= (TColor) abs(imgO->Canvas->Pixels[x][y] - imgA->Canvas->Pixels[x][y]);

  }
}

return imgD;

}
//************BOT HAT BINARIO********************************************************************
Graphics::TBitmap * TMorpho::botHatB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *img= new Graphics::TBitmap();  // creo un bitmap destino1
// clasura de imagen original - imagen original

imgD->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
imgD->Width= imgO->Width ;

img->Height= imgO->Height ;// le doy la altura y anchura del bitmap origen
img->Width= imgO->Width ;

img = closingB(imgO, EE, ox, oy);

for(int y=0; y<= imgD->Height; y++){//renglon
  for(int x=0; x<=imgD->Width; x++){//columnas

 imgD->Canvas->Pixels[x][y]= (TColor) abs(img->Canvas->Pixels[x][y]- imgO->Canvas->Pixels[x][y]);

  }
}

return imgD;
}


//************MÉTODO DE WATERSHED BINARIO***************************************
// falta por implementar


//************MÉTODO DE FUNCION DISTANCIA EN BINARIOS***************************

Graphics::TBitmap * TMorpho::FunDist(Graphics::TBitmap *imgO)
{

}
//************MÉTODO PARA SACAR VALORES EN GRIS MAXIMOS***************************
int TMorpho::Max(Graphics::TBitmap *img)
{
  int Rmax = 0, Gris;

 for (int x=0; x< img->Width; x++)//x col
    for (int y=0; y < img->Height; y++) //y ren
      {
      int B = GetBValue(img->Canvas->Pixels[x][y]);
      int G = GetGValue(img->Canvas->Pixels[x][y]);
      int R = GetRValue(img->Canvas->Pixels[x][y]);
      Gris = (R+G+B)/3;

      if(Gris != 255)
           if(Gris > Rmax)
               Rmax = Gris;
     }

  return Rmax;
}

//************MÉTODO PARA SACAR VALORES EN GRIS MINIMOS***************************
int TMorpho::Min(Graphics::TBitmap *img)
{

 int Rmin = 255, Gris;
 for (int x=0; x< img->Width; x++)//x col
    for (int y=0; y < img->Height; y++) //y ren
      {
      int B = GetBValue(img->Canvas->Pixels[x][y]);
      int G = GetGValue(img->Canvas->Pixels[x][y]);
      int R = GetRValue(img->Canvas->Pixels[x][y]);
      Gris = (R+G+B)/3;

       if(Gris != 255)
          if(Gris < Rmin)
             Rmin = Gris;
     }


return Rmin;
}
//************MÉTODO PARA ESTIRAMIENTO DE CONTRASTE***************************
Graphics::TBitmap * TMorpho::formula(int valmin, int valmax, Graphics::TBitmap *Fxy)
{

}



//************MÉTODO AUXILIAR "MINIMO"******************************************************
int TMorpho::minimo(int a, int b, int c)
{
  int aux,aux2;
   aux = min(a,b);
   aux2= min(aux,c);

return aux2;
}
//************MÉTODO AUXILIAR "MAXIMO"******************************************************
int TMorpho::maximo(int a, int b, int c)
{
  int aux,aux2;
   aux = max1(a,b);
   aux2= max1(aux,c);

return aux2;
}

//******MÉTODO PARA SACAR VALORES EN GRIS MAXIMOS EN IMG DILATADAS O EROSIONADAS***************
int TMorpho::MaxiGray(int **bmp, int col, int ren)
{
  int Rmax = -10000;

    for(int i =0 ; i<  col ; i++)//columna
      for(int j =0 ; j< ren ; j++)//renglon
         if(bmp[i][j] > Rmax)
             Rmax = bmp[i][j];

 return Rmax;
}

//********MÉTODO PARA SACAR VALORES EN GRIS MINIMOS EN IMG DILATADAS O EROSIONADAS************
int TMorpho::MiniGray(int **bmp, int col, int ren)
{

 int Rmin = 10000;

    for(int i =0 ; i<  col ; i++) //columna
      for(int j =0 ; j< ren ; j++)//renglon
         if(bmp[i][j] < Rmin)
             Rmin = bmp[i][j];
 
return Rmin;
}
//************MÉTODO AUXILIAR***************************************************************
// Comprueba que un pixel queda dentro de la imagen
int TMorpho::rango(Graphics::TBitmap* img, int i, int j){
   if ( (i<0 || i>=img->Height) || (j<0 || j>=img->Width) )
       return 0;
   return 1;
}

//************MÉTODO DE EROSION NIVELES DE GRIS******************************************************************

Graphics::TBitmap * TMorpho::erodeG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgO);
BYTE *Lbmp, *LbmpD;
int nR,nG, nB;

int **bmp,**se, **bmpD;

 bmp = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      bmp[j] = new int[imgO->Width]; //col

  for(int i=0; i < imgO->Height; i++)
  {
    Lbmp =(BYTE *) imgO->ScanLine[i];

    for(int j=0; j < imgO->Width; j++)
    {
      nB =Lbmp[j*3]; // este es para el azul
      nG =Lbmp[j*3+1]; // este es para el verde
      nR =Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmp[i][j]= rgb;
    }
  }


  se = new int*[EE->Height];  //ren
  for (int j= 0; j < EE->Height; j++)
      se[j] = new int[EE->Width]; //col

  for(int i=0; i < EE->Height; i++)
  {
    for(int j=0; j < EE->Width; j++)
    {
     int g =GetGValue(EE->Canvas->Pixels[i][j]);
     int rgb= (g+g+g)/3;
     se[j][i]= rgb;
    }
  }

  bmpD = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      bmpD[j] = new int[imgO->Width]; //col

int k,n;

   for (int r=0; r< imgO->Height; r++)//y ren
   {
     for (int c=0; c < imgO->Width; c++) //x col
      {
         k=10000;

         for(int rr=0; rr< EE->Height; rr++)// y ren
         {
            for(int cc=0; cc< EE->Width; cc++)// x col
            {

               if(rango(imgO, r+rr-oy, c+cc-ox)!=0)
               {

                  if(se[rr][cc]!= 255)
                  {
                   n = (bmp[r+rr-oy][c+cc-ox])-(se[rr][cc]); //CHECAR
                     if (n<k)
                        k=n;
                  }
               }
            }
         }

        if (k > 255)  bmpD[r][c] = 255;
	 else
            if (k< 0)  bmpD[r][c]= 0;
            else  bmpD[r][c]= k;

      }
    }


  for(int i=0; i < imgD->Height; i++)
  {
    LbmpD =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpD[i][j];
      LbmpD[j*3]= date; // este es para el azul
      LbmpD[j*3+1]= date; // este es para el verde
      LbmpD[j*3+2]= date;// este es para el rojo

    }
  }
   for(int i = 0; i < imgO->Height; i++)
   {
       delete[] bmp[i];
       delete[] bmpD[i];
   }
   for(int i = 0; i < EE->Height; i++)
       delete[] se[i];
   delete[] bmp;
   delete[] se;
   delete[] bmpD;
   return imgD;
}
//************MÉTODO DE DILATACIÓN NIVELES DE GRIS******************************************************************
Graphics::TBitmap * TMorpho::dilateG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgO);
BYTE *Lbmp, *Lse, *LbmpD;
int nR,nG, nB;

int **bmp,**se, **bmpD;

 bmp = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      bmp[j] = new int[imgO->Width]; //col

  for(int i=0; i < imgO->Height; i++)
  {
    Lbmp =(BYTE *) imgO->ScanLine[i];

    for(int j=0; j < imgO->Width; j++)
    {
      nB =(int)Lbmp[j*3]; // este es para el azul
      nG =(int)Lbmp[j*3+1]; // este es para el verde
      nR =(int)Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmp[i][j]= rgb;
    }
  }


  se = new int*[EE->Height];  //ren
  for (int j= 0; j < EE->Height; j++)
      se[j] = new int[EE->Width]; //col

  for(int i=0; i < EE->Height; i++)
  {
    for(int j=0; j < EE->Width; j++)
    {
     int g = GetGValue(EE->Canvas->Pixels[i][j]);
     int rgb= (g+g+g)/3;
     se[EE->Height-j-1][EE->Width-i-1]= rgb;

    }
  }

  bmpD = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      bmpD[j] = new int[imgO->Width]; //col


int k,n;

   for (int r=0; r< imgO->Height; r++)//x ren
   {
     for (int c=0; c < imgO->Width; c++) //y col
      {
         k=-10000;


         for(int rr=0; rr< EE->Height; rr++)// x ren
         {
            for(int cc=0; cc< EE->Width; cc++)// y ren
            {

               if(rango(imgO, r+rr-oy,c+cc-ox)!=0)
               {
                  if(se[rr][cc]!=255)
                  {
                    n = (se[rr][cc] + bmp[r+rr-oy][c+cc-ox]); //CHECAR
                    if (n>k)
                       k=n;
                  }

               }
            }
         }

         if (k > 255)  bmpD[r][c] = 255;
	 else if (k<0)  bmpD[r][c]= 0;
            else  bmpD[r][c]= k;
          bmpD[r][c]= k;

      }
    }

  for(int i=0; i < imgD->Height; i++)
  {
    LbmpD =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpD[i][j];
      LbmpD[j*3]= date; // este es para el azul
      LbmpD[j*3+1]= date; // este es para el verde
      LbmpD[j*3+2]= date;// este es para el rojo

    }
  }

   for(int i = 0; i < imgO->Height; i++)
   {
       delete[] bmp[i];
       delete[] bmpD[i];
   }
   for(int i = 0; i < EE->Height; i++)
       delete[] se[i];
   delete[] bmp;
   delete[] se;
   delete[] bmpD;
   return imgD;
}


//************MÉTODO DE APERTURA EN NIVELES DE GRIS**************************************************
Graphics::TBitmap * TMorpho::openingG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD1= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *imgD2= new Graphics::TBitmap();  // creo un bitmap destino2

//erosión y dilatación
imgD1->Assign(erodeG(imgO, EE, ox, oy));
imgD2->Assign(dilateG(imgD1, EE,ox, oy));

imgD1->FreeImage();
delete imgD1;

return imgD2;
}

//************MÉTODO DE CLAUSURA EN NIVELES DE GRIS*********************************************************
Graphics::TBitmap * TMorpho::closingG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD1= new Graphics::TBitmap();  // creo un bitmap destino1
Graphics::TBitmap *imgD2= new Graphics::TBitmap();  // creo un bitmap destino2

//dilatación y erosión
imgD1->Assign(dilateG(imgO, EE,ox, oy));
imgD2->Assign(erodeG(imgD1, EE, ox, oy));

imgD1->FreeImage();
delete imgD1;


return imgD2;
}

//************MÉTODO DE BORDE EXTERIOR EN NIVELES DE GRIS*****************************************
Graphics::TBitmap * TMorpho::bextG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
// imagen dilatada- imagen original

}

//************MÉTODO DE BORDE INTERIOR EN NIVELES DE GRIS************************************

Graphics::TBitmap * TMorpho::bintG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
//imagen original -  imagen erosionada


}

//************MÉTODO DE GRADIENTE EN NIVELES DE GRIS***********************************************

Graphics::TBitmap * TMorpho::gradmG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
//Dilatación - erosión

}

//************TOP HAT*****************************************************************************
Graphics::TBitmap * TMorpho::topHat(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *bmpD= new Graphics::TBitmap();  // creo un bitmap destino1
bmpD->Assign(imgO);

Graphics::TBitmap *bmpA= new Graphics::TBitmap();  // bitmap guardo apertura


BYTE *Lbmp, *LbmpA;
int nB, nG, nR;
int  **img, **imgA, **imgS,k;

//copio la imagen original
 img = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      img[j] = new int[imgO->Width]; //col

  for(int i=0; i < imgO->Height; i++)
  {
    Lbmp =(BYTE *) imgO->ScanLine[i];

    for(int j=0; j < imgO->Width; j++)
    {
      nB =(int)Lbmp[j*3]; // este es para el azul
      nG =(int)Lbmp[j*3+1]; // este es para el verde
      nR =(int)Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     img[i][j]= rgb;
    }
  }

bmpA->Assign(openingG(imgO, EE, ox, oy)); // realizo la apertura

//copio la imagen con la apertura
  imgA = new int*[bmpA->Height];  //ren
  for (int j= 0; j < bmpA->Height; j++)
      imgA[j] = new int[bmpA->Width]; //col

  for(int i=0; i < bmpA->Height; i++)
  {
    LbmpA =(BYTE *) bmpA->ScanLine[i];

    for(int j=0; j < bmpA->Width; j++)
    {
      nB =(int)LbmpA[j*3]; // este es para el azul
      nG =(int)LbmpA[j*3+1]; // este es para el verde
      nR =(int)LbmpA[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     imgA[i][j]= rgb;
    }
  }


//creo la matriz donde estara el resultado
  imgS = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      imgS[j] = new int[imgO->Width]; //col

//imagen original - apertura de imagen original
  for (int x=0; x< imgO->Height; x++)//x col
     for (int y=0; y < imgO->Width; y++) //y ren
     {

	  k = (img[x][y] - imgA[x][y]);

           if (k<0)
	     k = 0;
	   else if (k > 255)
	     k = 255;

	  imgS[x][y] = k;
     }

//copio el resultado a la imagen de salida
  for(int i=0; i < bmpD->Height; i++)
  {
    Lbmp =(BYTE *) bmpD->ScanLine[i];

    for(int j=0; j < bmpD->Width; j++)
    {
      int date = imgS[i][j];
      Lbmp[j*3]= date; // este es para el azul
      Lbmp[j*3+1]= date; // este es para el verde
      Lbmp[j*3+2]= date;// este es para el rojo

    }
  }

delete img;
delete imgA;
delete imgS;
return bmpD;
}
//************BOT HAT*****************************************************************************
Graphics::TBitmap * TMorpho::botHat(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *bmpD= new Graphics::TBitmap();  // creo un bitmap destino1
bmpD->Assign(imgO);

Graphics::TBitmap *bmpC= new Graphics::TBitmap();  // bitmap guardo apertura


BYTE *Lbmp, *LbmpC;
int nB, nG, nR;
int  **img, **imgC, **imgS,k;

//copio la imagen original
 img = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      img[j] = new int[imgO->Width]; //col

  for(int i=0; i < imgO->Height; i++)
  {
    Lbmp =(BYTE *) imgO->ScanLine[i];

    for(int j=0; j < imgO->Width; j++)
    {
      nB =(int)Lbmp[j*3]; // este es para el azul
      nG =(int)Lbmp[j*3+1]; // este es para el verde
      nR =(int)Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     img[i][j]= rgb;
    }
  }


bmpC->Assign(closingG(imgO, EE, ox, oy));//realizo la clausura

//copio la imagen con la clausura
  imgC = new int*[bmpC->Height];  //ren
  for (int j= 0; j < bmpC->Height; j++)
      imgC[j] = new int[bmpC->Width]; //col

  for(int i=0; i < bmpC->Height; i++)
  {
    LbmpC =(BYTE *) bmpC->ScanLine[i];

    for(int j=0; j < bmpC->Width; j++)
    {
      nB =(int)LbmpC[j*3]; // este es para el azul
      nG =(int)LbmpC[j*3+1]; // este es para el verde
      nR =(int)LbmpC[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     imgC[i][j]= rgb;
    }
  }


//creo la matriz donde estara el resultado
  imgS = new int*[imgO->Height];  //ren
  for (int j= 0; j < imgO->Height; j++)
      imgS[j] = new int[imgO->Width]; //col

// imagen clausura - imagen original

  for (int x=0; x< imgO->Height; x++)//x col
     for (int y=0; y < imgO->Width; y++) //y ren
     {

	  k = (imgC[x][y] - img[x][y]);

           if (k<0)
	     k = 0;
	   else if (k > 255)
	     k = 255;  

	  imgS[x][y] = k;
     }

//copio el resultado a la imagen de salida
  for(int i=0; i < bmpD->Height; i++)
  {
    Lbmp =(BYTE *) bmpD->ScanLine[i];

    for(int j=0; j < bmpD->Width; j++)
    {
      int date = imgS[i][j];
      Lbmp[j*3]= date; // este es para el azul
      Lbmp[j*3+1]= date; // este es para el verde
      Lbmp[j*3+2]= date;// este es para el rojo

    }
  }

delete img;
delete imgC;
delete imgS;
return bmpD;
}

//************MÉTODOS MORFOLOGICOS GEODESICOS******************************************

//************MÉTODO DE EROSION GEODESICA******************************************************************
Graphics::TBitmap * TMorpho::eroGeo(Graphics::TBitmap *imgMsk, Graphics::TBitmap *imgMrk)
{                                   //^ img original          |^  img erosionada
Graphics::TBitmap *imgD= new Graphics::TBitmap();// creo un bitmap destino
imgD->Assign(imgMsk);

// imagen marcadora f e imagen mascara g
// la img. marcadora es erosionada, f<=g

BYTE *Lmsk, *Lmrk, *Ldes;
int nB, nG, nR;
int **bmpMsk,**bmpMrk, **bmpDest;

// *****IMAGEN MASCARA******************
 bmpMsk = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpMsk[j] = new int[imgMsk->Width]; //col

  for(int i=0; i < imgMsk->Height; i++)
  {
    Lmsk =(BYTE *) imgMsk->ScanLine[i];

    for(int j=0; j < imgMsk->Width; j++)
    {
      nB =(int)Lmsk[j*3]; // este es para el azul
      nG =(int)Lmsk[j*3+1]; // este es para el verde
      nR =(int)Lmsk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMsk[i][j]= rgb;
    }
  }
//******IMAGEN MARCADORA LA QUE FUE VARIADA*********************
  bmpMrk = new int*[imgMrk->Height];  //ren
  for (int j= 0; j < imgMrk->Height; j++)
      bmpMrk[j] = new int[imgMrk->Width]; //col

  for(int i=0; i < imgMrk->Height; i++)
  {
    Lmrk =(BYTE *) imgMrk->ScanLine[i];

    for(int j=0; j < imgMrk->Width; j++)
    {
      nB =(int)Lmrk[j*3]; // este es para el azul
      nG =(int)Lmrk[j*3+1]; // este es para el verde
      nR =(int)Lmrk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMrk[i][j]= rgb;
    }
  }

//******IMAGEN DESTINO*****************************
  bmpDest = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpDest[j] = new int[imgMsk->Width]; //col

// TOMO EL PIXEL CON EL MAXIMO VALOR
   for (int x=0; x < imgMsk->Height; x++) //filas
    for (int y=0; y< imgMsk->Width; y++)//columnas
     {
       bmpDest[x][y]= max1(bmpMsk[x][y],bmpMrk[x][y]);
     }
//PASO LOS DATOS A LA IMAGEN DESTINO
  for(int i=0; i < imgD->Height; i++)
  {
    Ldes =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpDest[i][j];
      Ldes[j*3]= date; // este es para el azul
      Ldes[j*3+1]= date; // este es para el verde
      Ldes[j*3+2]= date;// este es para el rojo

    }
  }

delete bmpMsk;
delete bmpMrk;
delete bmpDest;
return imgD;
}

//************MÉTODO DE DILATACION GEODESICA******************************************************************
Graphics::TBitmap * TMorpho::dilGeo(Graphics::TBitmap *imgMsk, Graphics::TBitmap *imgMrk)
{                                   //^ img original          |^  img dilatada
Graphics::TBitmap *imgD= new Graphics::TBitmap();// creo un bitmap destino
imgD->Assign(imgMsk);

// imagen marcadora f e imagen mascara g
// la img. marcadora es dilatada, f<=g

BYTE *Lmsk, *Lmrk, *Ldes;
int nB, nG, nR;
int **bmpMsk,**bmpMrk, **bmpDest;

// *****IMAGEN MASCARA******************
 bmpMsk = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpMsk[j] = new int[imgMsk->Width]; //col

  for(int i=0; i < imgMsk->Height; i++)
  {
    Lmsk =(BYTE *) imgMsk->ScanLine[i];

    for(int j=0; j < imgMsk->Width; j++)
    {
      nB =(int)Lmsk[j*3]; // este es para el azul
      nG =(int)Lmsk[j*3+1]; // este es para el verde
      nR =(int)Lmsk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMsk[i][j]= rgb;
    }
  }
//******IMAGEN MARCADORA LA QUE FUE DILATADA*********************
  bmpMrk = new int*[imgMrk->Height];  //ren
  for (int j= 0; j < imgMrk->Height; j++)
      bmpMrk[j] = new int[imgMrk->Width]; //col

  for(int i=0; i < imgMrk->Height; i++)
  {
    Lmrk =(BYTE *) imgMrk->ScanLine[i];

    for(int j=0; j < imgMrk->Width; j++)
    {
      nB =(int)Lmrk[j*3]; // este es para el azul
      nG =(int)Lmrk[j*3+1]; // este es para el verde
      nR =(int)Lmrk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMrk[i][j]= rgb;
    }
  }

//******IMAGEN DESTINO*****************************
  bmpDest = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpDest[j] = new int[imgMsk->Width]; //col

// TOMO EL PIXEL CON EL MINIMO VALOR
   for (int x=0; x < imgMsk->Height; x++) //columnas
    for (int y=0; y< imgMsk->Width; y++)//filas
     {
       bmpDest[x][y]= min(bmpMsk[x][y],bmpMrk[x][y]);
     }

//PASO LOS DATOS A LA IMAGEN DESTINO
  for(int i=0; i < imgD->Height; i++)
  {
    Ldes =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpDest[i][j];
      Ldes[j*3]= date; // este es para el azul
      Ldes[j*3+1]= date; // este es para el verde
      Ldes[j*3+2]= date;// este es para el rojo

    }
  }

delete bmpMsk;
delete bmpMrk;
delete bmpDest;
return imgD;
}
//**********************MÉTODOS DE RECONSTRUCCIÓN********************************************
//************MÉTODO DE RECONSTRUCCIÓN POR DILATACIÓN NIVELES DE GRIS*******************************************
Graphics::TBitmap * TMorpho::dilRec(Graphics::TBitmap *imgMrk,Graphics::TBitmap *imgMsk )
{                                     // |^ img. Dilatada f     |^ img. Original g
//(Df= Dg y f<= g)
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgMsk);

BYTE *Lmsk, *Lmrk;
int nB, nG, nR;
int **bmpMsk,**bmpMrk;

// *****IMAGEN MASCARA******************
 bmpMsk = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpMsk[j] = new int[imgMsk->Width]; //col

  for(int i=0; i < imgMsk->Height; i++)
  {
    Lmsk =(BYTE *) imgMsk->ScanLine[i];

    for(int j=0; j < imgMsk->Width; j++)
    {
      nB =(int)Lmsk[j*3]; // este es para el azul
      nG =(int)Lmsk[j*3+1]; // este es para el verde
      nR =(int)Lmsk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMsk[i][j]= rgb;
    }
  }
//******IMAGEN MARCADORA LA QUE FUE DILATADA*********************
  bmpMrk = new int*[imgMrk->Height];  //ren
  for (int j= 0; j < imgMrk->Height; j++)
      bmpMrk[j] = new int[imgMrk->Width]; //col

  for(int i=0; i < imgMrk->Height; i++)
  {
    Lmrk =(BYTE *) imgMrk->ScanLine[i];

    for(int j=0; j < imgMrk->Width; j++)
    {
      nB =(int)Lmrk[j*3]; // este es para el azul
      nG =(int)Lmrk[j*3+1]; // este es para el verde
      nR =(int)Lmrk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMrk[i][j]= rgb;
    }
  }
//----------------------------------------------------------------------------
  //bool noestabilidad=true;
  //while(noestabilidad)
  //{
        int vta,vti,vdd,vda;
       //Exploración hacia adelante
       for (int y=0; y < imgMrk->Height; y++) //y ren
          for (int x=0; x< imgMrk->Width; x++)//x col
          {
             int p= bmpMrk[y][x];               //--------------------
              if(y-1 < 0)                       //|y-1 |       |y-1, |
                vta= 0;                         //|x-1  |y-1,x |x+1  |
              else                              //|-----|------|-----|
                vta = bmpMrk[y-1][x];           //|y    |      | y,  |
                                                //| x-1 | y,x  | x+1 |
             if(x-1 < 0)                        //|-----|------|-----|
                vti= 0;                         //|y+1, |y+1,x |y+1, |
            else                                //|x-1  |      |x+1  |
               vti = bmpMrk[y][x-1];            //--------------------

             int valmax= maximo(p,vta,vti);
             int valmin= min(bmpMsk[y][x], valmax);
             bmpMrk[y][x]= valmin;
           }
        //Exploración hacia atras
        for (int y= imgMrk->Height-1; y>0; y--) //y ren
          for (int x= imgMrk->Width-1; x>0; x--)//x col
          {
             int p2= bmpMrk[y][x];

               if(y+1 > imgMrk->Height-1)
                 vda=0;
               else
                 vda = bmpMrk[y+1][x];

               if(x+1 > imgMrk->Width-1)
                 vdd=0;
               else
                 vdd = bmpMrk[y][x+1];


             int valmax2= maximo(p2,vdd,vda);
             int valmin2= min(bmpMsk[y][x], valmax2);
             bmpMrk[y][x]= valmin2;
           }

        /*Se hace la resta de las imágenes, debo guardar la imágen anterior
        y la actual para poder restarlas.
         Rest= Pdi->Resta(Previous, Actual); // cuando sea interno, tendre que programar un vector dinámico

        se comparan, //debo revisar las resta pues de esto depende todo.

        int value = Pdi->Scan(Rest)
        
        if(value != 0) //son diferentes
           noestabilidad= true;  //la no estabilidad sigue
        else
           noestabilidad = false; // se estabiliza

        si el resultado es diferente de cero las imagenes son diferentes por lo tanto
        noestabilidad= true
        si es igual a cero
        noestabilidad = false y llega a la estabilidad termina el while*/

 //     } //finishWhile
//--------------------------------------------------------------------------

//PASO LOS DATOS A LA IMAGEN DESTINO
  for(int i=0; i < imgD->Height; i++)
  {
    Lmrk =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpMrk[i][j];
      Lmrk[j*3]= date; // este es para el azul
      Lmrk[j*3+1]= date; // este es para el verde
      Lmrk[j*3+2]= date;// este es para el rojo

    }
  }

   for (int j= 0; j < imgMsk->Height; j++)
      delete[] bmpMsk[j];
   delete[] bmpMsk;
   for (int j= 0; j < imgMrk->Height; j++)
      delete[] bmpMrk[j];
   delete[] bmpMrk;
   return imgD;
}

//************MÉTODO DE RECONSTRUCCIÓN POR EROSION NIVELES DE GRIS*******************************************
Graphics::TBitmap * TMorpho::eroRec(Graphics::TBitmap *imgMrk,Graphics::TBitmap *imgMsk )
{                                     // |^ img. Erosionada f     |^ img. Original g
//(Df= Dg y f >= g)
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgMsk);

BYTE *Lmsk, *Lmrk;
int nB, nG, nR;
int **bmpMsk,**bmpMrk;

// *****IMAGEN MASCARA******************
 bmpMsk = new int*[imgMsk->Height];  //ren
  for (int j= 0; j < imgMsk->Height; j++)
      bmpMsk[j] = new int[imgMsk->Width]; //col

  for(int i=0; i < imgMsk->Height; i++)
  {
    Lmsk =(BYTE *) imgMsk->ScanLine[i];

    for(int j=0; j < imgMsk->Width; j++)
    {
      nB =(int)Lmsk[j*3]; // este es para el azul
      nG =(int)Lmsk[j*3+1]; // este es para el verde
      nR =(int)Lmsk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMsk[i][j]= rgb;
    }
  }
//******IMAGEN MARCADORA LA QUE FUE EROSIONADA*********************
  bmpMrk = new int*[imgMrk->Height];  //ren
  for (int j= 0; j < imgMrk->Height; j++)
      bmpMrk[j] = new int[imgMrk->Width]; //col

  for(int i=0; i < imgMrk->Height; i++)
  {
    Lmrk =(BYTE *) imgMrk->ScanLine[i];

    for(int j=0; j < imgMrk->Width; j++)
    {
      nB =(int)Lmrk[j*3]; // este es para el azul
      nG =(int)Lmrk[j*3+1]; // este es para el verde
      nR =(int)Lmrk[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpMrk[i][j]= rgb;
    }
  }
//---------------------------------------------------------------------
//  bool noestabilidad=true;
//  while(noestabilidad)
//    {
            int vta,vti,vdd,vda;

       //Exploración hacia adelante
        for (int y=0; y < imgMrk->Height; y++) //y ren
          for (int x=0; x< imgMrk->Width; x++)//x col
          {
            int p= bmpMrk[y][x];
            if(y-1 < 0)
                vta= 255;
             else
               vta = bmpMrk[y-1][x];

             if(x-1 < 0)
                vti= 255;
             else
                vti = bmpMrk[y][x-1];

             int valmin= minimo(p,vta,vti);
             int valmax= max1(bmpMsk[y][x], valmin);
             bmpMrk[y][x]= valmax;
            }

        //Exploración hacia atras
        for (int y= imgMrk->Height-1; y>0; y--) //y ren
          for (int x= imgMrk->Width-1; x>0; x--)//x col
          {
             int p2= bmpMrk[y][x];
             if(y+1 > imgMrk->Height-1)
              vda=255;
             else
              vda = bmpMrk[y+1][x];

             if(x+1 > imgMrk->Width-1)
               vdd=255;
             else
              vdd = bmpMrk[y][x+1];


             int valmin2= minimo(p2,vdd,vda);
             int valmax2= max1(bmpMsk[y][x], valmin2);
             bmpMrk[y][x]= valmax2;
           }

        /* Se hace una resta de las imágenes, se comparan,
        si es diferente de cero las imagenes son diferentes por lo tanto
        noestabilidad= true
        si es igual a cero
        noestabilidad = false y llega a la estabilidad termina el while*/
//      } //finishWhile
//-----------------------------------------------------------------------------

//PASO LOS DATOS A LA IMAGEN DESTINO
  for(int i=0; i < imgD->Height; i++)
  {
    Lmrk =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpMrk[i][j];
      Lmrk[j*3]= date; // este es para el azul
      Lmrk[j*3+1]= date; // este es para el verde
      Lmrk[j*3+2]= date;// este es para el rojo

    }
  }

   for (int j= 0; j < imgMsk->Height; j++)
      delete[] bmpMsk[j];
   delete[] bmpMsk;
   for (int j= 0; j < imgMrk->Height; j++)
      delete[] bmpMrk[j];
   delete bmpMrk;
   return imgD;
}

//***MÉTODO**DE**RECONSTRUCCIÓN**AUTODUAL******************************************************
Graphics::TBitmap * TMorpho::dualRec(Graphics::TBitmap *imgRe,Graphics::TBitmap *imgRd,Graphics::TBitmap *imgOri)
{

}
//----------------------------------------------------------------------------------------
int TMorpho::min(int a,int b)
{
if(a<b)
return a;
else
return b;
}
int TMorpho::max1(int c,int d)
{
if(c>d)
return c;
else
return d;
}
//----------------------------------------------------------------------------------------
Graphics::TBitmap * TMorpho::ChessBoardDistanceMap(Graphics::TBitmap * entrada)
{

}
//----------------------------------------------------------------------------------------
Graphics::TBitmap * TMorpho::CityBlock(Graphics::TBitmap * input)
{


}
//----------------------------------------------------------------------------------------
Graphics::TBitmap * TMorpho::Euclidean(Graphics::TBitmap * input)
{


}
int __fastcall TMorpho::D4(int x1, int y1, int x2, int y2)
{
      return (abs(x1 - x2) + abs(y1 - y2));
}
int __fastcall TMorpho::D8(int x1, int y1, int x2, int y2)
{
        return (max1(abs(x1 - x2),abs(y1 - y2)));
}
double __fastcall TMorpho::Deuc(int x1, int y1, int x2, int y2)
{
      return (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}
//----------------------------------------------------------------------------------------
Graphics::TBitmap * TMorpho::dilateG2(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgO);
BYTE *Lbmp, *Lse, *LbmpD;
int nR,nG, nB;

int **bmp,**se, **bmpD;

 bmp = new int*[imgO->Width];  //ren
  for (int j= 0; j < imgO->Width; j++)
      bmp[j] = new int[imgO->Height]; //col

  for(int i=0; i < imgO->Width; i++)
  {
    Lbmp =(BYTE *) imgO->ScanLine[i];

    for(int j=0; j < imgO->Height; j++)
    {
      nB =(int)Lbmp[j*3]; // este es para el azul
      nG =(int)Lbmp[j*3+1]; // este es para el verde
      nR =(int)Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmp[i][j]= rgb;
    }
  }


  se = new int*[EE->Width];  //ren
  for (int j= 0; j < EE->Width; j++)
      se[j] = new int[EE->Height]; //col

  for(int i=0; i < EE->Width; i++)
  {
    for(int j=0; j < EE->Height; j++)
    {
     int g =GetGValue(EE->Canvas->Pixels[i][j]);
     int rgb= (g+g+g)/3;
     se[i][j]= rgb;

    }
  }

  bmpD = new int*[imgO->Width];  //ren
  for (int j= 0; j < imgO->Width; j++)
      bmpD[j] = new int[imgO->Height]; //col


int k,n;

   for (int r=0; r< imgO->Width; r++)//x ren
   {
     for (int c=0; c < imgO->Height; c++) //y col
      {
         k=-10000;


         for(int rr=0; rr< EE->Width; rr++)// x ren
         {
            for(int cc=0; cc< EE->Height; cc++)// y ren
            {

               if(rango(imgO, r+rr-oy,c+cc-ox)!=0)
               {
                  if(se[rr][cc]!=255)
                  {
                    n = (se[rr][cc] + bmp[r+rr-oy][c+cc-ox]); //CHECAR
                    if (n>k)
                       k=n;
                  }

               }
            }
         }

         if (k > 255)  bmpD[r][c] = 255;
	 else if (k<0)  bmpD[r][c]= 0;
            else  bmpD[r][c]= k;
          bmpD[r][c]= k;

      }
    }

  for(int i=0; i < imgD->Width; i++)
  {
    LbmpD =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Height; j++)
    {
      int date = bmpD[i][j];
      LbmpD[j*3]= date; // este es para el azul
      LbmpD[j*3+1]= date; // este es para el verde
      LbmpD[j*3+2]= date;// este es para el rojo

    }
  }


   delete bmp;
   delete se;
   delete bmpD;
   return imgD;
}
//************MÉTODO DE ESQUELETIZACIÓN BINARIA***********************************************************
Graphics::TBitmap * TMorpho::SequentialThinningB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy,int Iteracion,int rotationCSE){
        

}
//************MÉTODO DE HIT OR MISS***********************************************************
Graphics::TBitmap * TMorpho::HitOrMiss(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{

}
//************MÉTODO DE PODA ***********************************************************
Graphics::TBitmap * TMorpho::Prune(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy)
{

}
//***********************************************************************************************************
Graphics::TBitmap * TMorpho::RotaEEC(int angulo, int tam,Graphics::TBitmap *EER, int ox, int oy)
{
        
}
//***********************************************************************************************************



#pragma package(smart_init)










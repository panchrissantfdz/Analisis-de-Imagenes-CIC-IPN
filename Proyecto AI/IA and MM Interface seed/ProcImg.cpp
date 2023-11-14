//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

#pragma hdrstop

//#include "MaskF.h"
#include "ProcImg.h"
#include "Main.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//************MÉTODO PARA CONVERTIR LA IMG EN NIVELES DE GRIS*****************************
Graphics::TBitmap * TProcImg::GrayLevel(Graphics::TBitmap *bmpE)
{
Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
bmpS->Assign(bmpE);

 BYTE *GL;
 int nR,nG, nB;

  for(int i=0; i < bmpS->Height; i++)
  {
    GL =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
      nB =GL[j*3]; // este es para el azul
      nG =GL[j*3+1]; // este es para el verde
      nR =GL[j*3+2]; // este es para el rojo

     //int rgb = ((0.155*nB)+(0.587*nG)+(0.258*nR));
    //int rgb = ((0.114*nB)+(0.587*nG)+(0.299*nR));
     int rgb= (nB+nG+nR)/3;

      GL[j*3]= rgb; // este es para el azul
      GL[j*3+1]=rgb; // este es para el verde
      GL[j*3+2]=rgb; // este es para el rojo
    }
  }

  return bmpS;
}
//************MÉTODO DE REVERSION DE LA IMAGEN******************************************
Graphics::TBitmap * TProcImg::Invertir(Graphics::TBitmap *bmpE)
{ //esta es una version alterna a la presentada más abajo, se puede hacer asi o negando logicamente el valor del px
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE); //bitmap auxiliar para no dañar el original, se almacena una copia exacta del original.


 BYTE *LineE;//apuntador a byte, para almacenar temporalmente cada fila de la imagen

  for(int i=0; i < bmpS->Height; i++)
  {
    LineE =(BYTE *) bmpS->ScanLine[i];//se almacena la fila
    for(int j=0; j < bmpS->Width; j++)
    {
       LineE[j*3]=  (255 - LineE[j*3]); // este es para el azul  esto o ~LineE[j*3];
       LineE[j*3+1]=(255 - LineE[j*3+1]); // este es para el verde
       LineE[j*3+2]=(255 - LineE[j*3+2]); // este es para el rojo

    }
  }

 return bmpS;
}
//************MÉTODO PARA CONVERTIR LA IMG PLANO ROJO EN COLORES*****************************
Graphics::TBitmap * TProcImg::RedPlane(Graphics::TBitmap *bmpE)
{
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Rojo;

  for(int i=0; i < bmpS->Height; i++)
  {
    Rojo =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
       Rojo[j*3]=0; // este es para el azul   //se ponen los otros componentes en 0 y solo se respeta la componente q se quiere dejar
       Rojo[j*3+1]=0; // este es para el verde
       Rojo[j*3+2]; // este es para el rojo

    }
  }

  return bmpS;
}
//************MÉTODO PARA CONVERTIR LA IMG PLANO ROJO EN NG*****************************
Graphics::TBitmap * TProcImg::RedPlaneNG(Graphics::TBitmap *bmpE)//esta obtiene el plano rojo en escala de grises
{
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Rojo;

  for(int i=0; i < bmpS->Height; i++)
  {
    Rojo =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {    //todas las componentes se igualan a la roja, asi se saca una img en grises
       Rojo[j*3]= Rojo[j*3+2]; // este es para el azul
       Rojo[j*3+1]=Rojo[j*3+2]; // este es para el verde
       Rojo[j*3+2]=Rojo[j*3+2]; // este es para el rojo

    }
  }

  return bmpS;
}

//************MÉTODO PARA CONVERTIR LA IMG PLANO VERDE*****************************
Graphics::TBitmap * TProcImg::GreenPlane(Graphics::TBitmap *bmpE)
{ //misma situacion que con el canal rojo, pero ahora el verde en colores
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Verde;

  for(int i=0; i < bmpS->Height; i++)
  {
    Verde =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
       Verde[j*3]=0; // este es para el azul
       Verde[j*3+1]; // este es para el verde
       Verde[j*3+2]=0; // este es para el rojo

    }
  }

  return bmpS;
}
//************MÉTODO PARA CONVERTIR LA IMG PLANO VERDE*NG****************************
Graphics::TBitmap * TProcImg::GreenPlaneNG(Graphics::TBitmap *bmpE)
{    //lo mismo que para el canal rojo en escala de grises.
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Verde;

  for(int i=0; i < bmpS->Height; i++)
  {
    Verde =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
       Verde[j*3]=Verde[j*3+1]; // este es para el azul
       Verde[j*3+1]=Verde[j*3+1]; // este es para el verde
       Verde[j*3+2]=Verde[j*3+1]; // este es para el rojo

    }
  }

  return bmpS;
}

//************MÉTODO PARA CONVERTIR LA IMG EN PLANO AZUL*****************************
Graphics::TBitmap * TProcImg::BluePlane(Graphics::TBitmap *bmpE)
{     //lo mismo que los canales rojo y verde en color.
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Azul;

  for(int i=0; i < bmpS->Height; i++)
  {
    Azul =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
       Azul[j*3]; // este es para el azul
       Azul[j*3+1]=0; // este es para el verde
       Azul[j*3+2]=0; // este es para el rojo

    }
  }

  return bmpS;
}
//************MÉTODO PARA CONVERTIR LA IMG EN PLANO AZUL*****************************
Graphics::TBitmap * TProcImg::BluePlaneNG(Graphics::TBitmap *bmpE)
{     //lo mismo que los canales rojo y verde en grises.
 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 bmpS->Assign(bmpE);

 BYTE *Azul;

  for(int i=0; i < bmpS->Height; i++)
  {
    Azul =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < bmpS->Width; j++)
    {
       Azul[j*3]=Azul[j*3]; // este es para el azul
       Azul[j*3+1]=Azul[j*3]; // este es para el verde
       Azul[j*3+2]=Azul[j*3]; // este es para el rojo

    }
  }

  return bmpS;
}


//************MÉTODO DE THRESHOLDING DE LA IMAGEN*****************************************
Graphics::TBitmap * TProcImg::UmbralI(int Umbral,int Resto,Graphics::TBitmap *bmpE,AnsiString Thres)
{

}
//************MÉTODO DE THRESHOLDING DE LA IMAGEN*****************************************
Graphics::TBitmap * TProcImg::UmbralX(int Umbral,int Resto,Graphics::TBitmap *bmpE,AnsiString Thres)
{

}

//************MÉTODO DE THRESHOLDING BINARY INVERT***********************************
Graphics::TBitmap * TProcImg::UmbralBiX(int Umbral,int Resto,Graphics::TBitmap *bmpE, int T1, int T2)
{

}

//************MÉTODO DE THRESHOLDING DE LA IMAGEN*****************************************
Graphics::TBitmap * TProcImg::Umbral(Graphics::TBitmap *bmpE,AnsiString Thres)
{

}
//************MÉTODO DE THRESHOLDING BINARY DE LA IMAGEN***********************************
Graphics::TBitmap * TProcImg::UmbralBi(Graphics::TBitmap *bmpE, int T1, int T2)
{

}

//************MÉTODO DE THRESHOLDING BINARY INVERT***********************************
Graphics::TBitmap * TProcImg::UmbralBiInv(Graphics::TBitmap *bmpE, int T1, int T2)
{

}

//************MÉTODO DE GRAY SCALE THRESHOLDING*****************************************
Graphics::TBitmap * TProcImg::UmbralGS(Graphics::TBitmap *bmpE, int T1, int T2)
{

}

//************MÉTODO DE GRAY SCALE THRESHOLDING INVERTIDO***********************************
Graphics::TBitmap * TProcImg::UmbralGSInv(Graphics::TBitmap *bmpE, int T1, int T2)
{

}

//************MÉTODO CENTROIDE*************************************************************
Graphics::TBitmap * TProcImg::Centroide(Graphics::TBitmap *bmpE)
{

}


//************MÉTODO**EXTENSION*************************************************************
Graphics::TBitmap * TProcImg::Extension(Graphics::TBitmap *bmpE, int T1, int T2)
{

}
//************MÉTODO**RESTA**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Resta(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);

int **bmpA,**bmpB, **bmpD;

// *****IMAGEN MINUENDO******************

bmpA= BmpToMtx(imgA); // transformo el bmp a mtx

//******IMAGEN SUSTRAENDO*********************

bmpB= BmpToMtx(imgB);// transformo el bmp a mtx

//******IMAGEN Destino*********************
  bmpD = new int*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new int[imgD->Width]; //col

        for (int x=0; x< imgD->Height; x++)//x ren
          for (int y=0; y < imgD->Width; y++) //y col
          {
              int n = abs(bmpA[x][y] - bmpB[x][y]);
              n = ((n < 0)? 0: n)  ;
              bmpD[x][y]= n;
          }

//**RESULTADO*************************
imgD->Assign(MtxToBmp(bmpD, imgD)); // transformo la matriz a bmp

   for(int i = 0; i < imgA->Height; i++)
       delete[] bmpA[i];
   delete[] bmpA;
   for(int i = 0; i < imgB->Height; i++)
       delete[] bmpB[i];
   delete[] bmpB;
   for(int i = 0; i < imgD->Height; i++)
       delete[] bmpD[i];
   delete[] bmpD;
   return imgD;
}

//************MÉTODO**SUMA**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Suma(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);

int **bmpA,**bmpB, **bmpD;

// *****IMAGEN SUMANDO******************

bmpA= BmpToMtx(imgA); // transformo el bmp a mtx

//******IMAGEN SUMADOR*********************

bmpB= BmpToMtx(imgB);// transformo el bmp a mtx

//******IMAGEN Destino*********************
  bmpD = new int*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new int[imgD->Width]; //col

        for (int y=0; y < imgD->Height; y++) //y ren
          for (int x=0; x< imgD->Width; x++)//x col
          {
              int n = abs(bmpA[y][x] + bmpB[y][x]);
              n = ((n > 255)? 255:n);
              bmpD[y][x]= n;
          }

//**RESULTADO*************************
imgD->Assign(MtxToBmp(bmpD, imgD));

   delete bmpA;
   delete bmpB;
   delete bmpD;
   return imgD;
}
//************MÉTODO**MULTIPLICACION**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Multiplica(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);

int **bmpA,**bmpB, **bmpD;

// *****IMAGEN MULTIPLICANDO******************

bmpA= BmpToMtx(imgA); // transformo el bmp a mtx

//******IMAGEN MULTIPLICADOR*********************

bmpB= BmpToMtx(imgB);// transformo el bmp a mtx

//******IMAGEN Destino*********************
 bmpD = new int*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new int[imgD->Width]; //col

        for (int x=0; x< imgD->Height; x++)//x col
          for (int y=0; y < imgD->Width; y++) //y ren
          {
              int n = abs(bmpA[x][y] * bmpB[x][y]);
              n = ((n > 255)? 255: n );
              bmpD[x][y]= n;
           }

//**RESULTADO*************************
imgD->Assign(MtxToBmp(bmpD, imgD));

   delete bmpA;
   delete bmpB;
   delete bmpD;
   return imgD;
}

 //************MÉTODO**DIVISION**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Divide(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);

BYTE *Lbmp;
int nB, nG, nR;
double **bmpA,**bmpB, **bmpD;

// *****IMAGEN DIVIDENDO******************
 bmpA = new double*[imgA->Height];  //col
  for (int j= 0; j < imgA->Height; j++)
      bmpA[j] = new double[imgA->Width]; //col

  for(int i=0; i < imgA->Height; i++)
  {
    Lbmp =(BYTE *) imgA->ScanLine[i];

    for(int j=0; j < imgA->Width; j++)
    {
      nB =Lbmp[j*3]; // este es para el azul
      nG =Lbmp[j*3+1]; // este es para el verde
      nR =Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpA[i][j]= rgb+1;
    }
  }
//******IMAGEN DIVISOR*********************
  bmpB = new double*[imgB->Height];  //col
  for (int j= 0; j < imgB->Height; j++)
      bmpB[j] = new double[imgB->Width]; //ren

  for(int i=0; i < imgB->Height; i++)
  {
    Lbmp =(BYTE *) imgB->ScanLine[i];

    for(int j=0; j < imgB->Width; j++)
    {
      nB =Lbmp[j*3]; // este es para el azul
      nG =Lbmp[j*3+1]; // este es para el verde
      nR =Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmpB[i][j]= rgb+1;
    }
  }
//******IMAGEN Destino*********************
      bmpD = new double*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new double[imgD->Width]; //col

        for (int x=0; x< imgD->Height; x++)//x ren
          for (int y=0; y < imgD->Width; y++) //y col
          {
              int n = abs(bmpA[x][y] / bmpB[x][y]);
              n = ((n < 0)? 0: n);
              bmpD[x][y]= n;
               //marca error con división por cero ARREGLAR
          }

  for(int i=0; i < imgD->Height; i++)
  {
    Lbmp =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      int date = bmpD[i][j];
      Lbmp[j*3]= date; // este es para el azul
      Lbmp[j*3+1]= date; // este es para el verde
      Lbmp[j*3+2]= date;// este es para el rojo

    }
  }

   delete bmpA;
   delete bmpB;
   delete bmpD;
   return imgD;
}
//************MÉTODO**INTERSECCION**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Intersecta(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
//AND = INTESECCIÓN = MIN = A*B
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);
int **bmpA,**bmpB, **bmpD;

// *****IMAGEN A******************

bmpA= BmpToMtx(imgA); // transformo el bmp a mtx

//******IMAGEN B*********************

bmpB= BmpToMtx(imgB);// transformo el bmp a mtx

//******IMAGEN Destino*********************
  bmpD = new int*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new int[imgD->Width]; //col

        for (int x=0; x< imgD->Height; x++)//x col
          for (int y=0; y < imgD->Width; y++) //y ren
          {
              bmpD[x][y]= min1(bmpA[x][y],bmpB[x][y]);   //INVETIGAR SI ESTA MAL, DEBE SER MIN era max
          }

//**RESULTADO*************************
imgD->Assign(MtxToBmp(bmpD, imgD));

   delete bmpA;
   delete bmpB;
   delete bmpD;
   return imgD;
}

 //************MÉTODO**UNION**DE**IMÁGENES*****************************************************
Graphics::TBitmap * TProcImg::Union(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB)
{
//OR= UNION= MAX= A+B
Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
imgD->Assign(imgA);

int **bmpA,**bmpB, **bmpD;

// *****IMAGEN A******************

bmpA= BmpToMtx(imgA); // transformo el bmp a mtx

//******IMAGEN B*********************

bmpB= BmpToMtx(imgB);// transformo el bmp a mtx

//******IMAGEN Destino*********************
  bmpD = new int*[imgD->Height];  //ren
  for (int j= 0; j < imgD->Height; j++)
      bmpD[j] = new int[imgD->Width]; //col

        for (int x=0; x< imgD->Height; x++)//x ren
          for (int y=0; y < imgD->Width; y++) //y col
          {
              bmpD[x][y]= max1(bmpA[x][y],bmpB[x][y]);   //INVESTIGAR SI ESTA MAL, DEBE SER MAX era min
          }

//**RESULTADO*************************
imgD->Assign(MtxToBmp(bmpD, imgD));

   delete bmpA;
   delete bmpB;
   delete bmpD;
   return imgD;
}

//************MÉTODO**ESCANEO**IMÁGENES**PARA COMPARAR***************************************
int TProcImg::Scan(Graphics::TBitmap *imgF)
{
 Graphics::TBitmap *bmpIn= new Graphics::TBitmap();// creo un bitmap destino
 bmpIn->Assign(imgF);

 BYTE *LinePtr;
 int nR, nG, nB;
 int sum=0;

  for(int i=0; i < bmpIn->Height; i++) //ren
  {     LinePtr =(BYTE *) bmpIn->ScanLine[i];
    for(int j=0; j < bmpIn->Width; j++) //col
    {
      nB =LinePtr[j*3]; // este es para el azul
      nG =LinePtr[j*3+1]; // este es para el verde
      nR =LinePtr[j*3+2]; // este es para el rojo
      int rgb= (nB+nG+nR)/3;
      sum=sum + rgb;
    }
  }
    bmpIn->FreeImage();
    delete bmpIn;
    if(sum != 0) //si la suma es dif. de cero
     return 1;  // las imagenes son diferentes
    else        // si no
      return 0; // la imágenes son iguales
}


//************MÉTODO**PARA SACAR ESTADISTICAS**IMÁGENES*****************************************************
/*Graphics::TBitmap * TProcImg::Statistic(Graphics::TBitmap *img)
{

}  */
//************MÉTODO**PARA SACAR LAPLACIANODELGAUSSIANO************************************
/*0  0 -1  0  0
  0 -1 -2 -1  0
 -1 -2 16 -2 -1
  0 -1 -2 -1  0
  0  0 -1  0  0*/
Graphics::TBitmap * TProcImg::LoG(Graphics::TBitmap *img)
{

}



//************************MÉTODO**PARA**FILTRO**GAUSSIANO************************************
Graphics::TBitmap * TProcImg::Gaussian(Graphics::TBitmap *img, int size, double desv)
{

}

//************************MÉTODO**PARA**FILTRO**MEDIANA******************************
Graphics::TBitmap * TProcImg::Average(Graphics::TBitmap *img, int sizek)
{

}


//************MÉTODO**PARA**RESTAR**VALORES**DE**LA**BRILLANTES**DE**LA**IMAGEN**************
Graphics::TBitmap * TProcImg::BrigthR(Graphics::TBitmap *bmpE, int val)
{


}
//************MÉTODO**PARA**SUMAR**VALORES**DE**LA**BRILLANTES**DE**LA**IMAGEN**************
Graphics::TBitmap * TProcImg::BrigthS(Graphics::TBitmap *bmpE, int val)
{


}

//***********************MÉTODO**DE**NORMALIZACION**DEL**HISTOGRAM************************
double * TProcImg::NormalizaHistograma(int *Hist,int W, int H)
{


}
//***********************MÉTODO**DE**CALCULO**DEL**HISTOGRAM************************
int * TProcImg::Histogram(Graphics::TBitmap *bmp)
{
  TColor imgc;
  int * Hist= new int[256] ;
  for (int i=0 ; i< 256 ; i++)
     Hist[i]=0 ;

  for (int i = 0 ; i < bmp->Width ; i++)
    for (int j= 0 ; j < bmp->Height ; j++ )
    {
       imgc= (bmp->Canvas->Pixels[i][j]);
        int R=(GetRValue(imgc));
        int G=(GetGValue(imgc));
        int B=(GetBValue(imgc));
        int L= ((R+G+B)/3);
        Hist[L]++;
    }
  return Hist ;
}



//***********************MÉTODO**DE**UMBRALIZACIÓN**OTSU************************
int TProcImg::ThresholdOtsu(Graphics::TBitmap *bmp,double eps)
{


}
//***********************MÉTODO**DE**ETIQUETADO************************
Graphics::TBitmap * TProcImg::Etiqueta(Graphics::TBitmap *bmp)
{
/*       x= width= col,  y= height= ren
--------------------
|x-1, |  *   |x+1, |
|y-1  |x,y-1 |y-1  |
|-----|------|-----|
|x-1, |  *   | x+1,|
| y * | x,y  |  y  |
|-----|------|-----|
|x-1, |x,y+1 |x+1, |
|y+1  |      |y+1  |
--------------------  */


}
//---------------------------------------------------------------------------------------------------
int** TProcImg::BmpToMtx(Graphics::TBitmap *bmpO) // de bitmap a matriz de enteros
{
BYTE *Lbmp;
int nR,nG, nB;
int **bmp;

 bmp = new int*[bmpO->Height];  //ren
  for (int j= 0; j < bmpO->Height; j++)
      bmp[j] = new int[bmpO->Width]; //col

  for(int i=0; i < bmpO->Height; i++)
  {
    Lbmp =(BYTE *) bmpO->ScanLine[i];

    for(int j=0; j < bmpO->Width; j++)
    {
      nB =Lbmp[j*3]; // este es para el azul
      nG =Lbmp[j*3+1]; // este es para el verde
      nR =Lbmp[j*3+2]; // este es para el rojo

     int rgb= (nB+nG+nR)/3;
     bmp[i][j]= rgb;
    }
  }

 return bmp;

}

Graphics::TBitmap * TProcImg::MtxToBmp(int **bmp, Graphics::TBitmap *bmpO) // de matriz a bitmap
{
 Graphics::TBitmap *imgD= new Graphics::TBitmap();  // creo un bitmap destino
 imgD->Assign(bmpO);
 BYTE *Lbmp;
 int nR,nG, nB;
  // int max=510;
  for(int i=0; i < imgD->Height; i++)
  {
    Lbmp =(BYTE *) imgD->ScanLine[i];

    for(int j=0; j < imgD->Width; j++)
    {
      //int date =( (bmp[i][j]*255)/max);
      int date = bmp[i][j];
      Lbmp[j*3]= date; // este es para el azul
      Lbmp[j*3+1]= date; // este es para el verde
      Lbmp[j*3+2]= date;// este es para el rojo

    }
  }
return imgD;
}


//******MÉTODO**PARA**ENCONTRAR**EL**MINIMO**RELATIVO**PARA**LOS**OBJETOS**NEGROS************************
int TProcImg::MRThres(int *Hist)
{

}


//******MÉTODO**PARA**ENCONTRAR**EL**MINIMO**RELATIVO**PARA**LOS**OBJETOS**BLANCOS************************
int TProcImg::MRThresW(int *Hist)
{
     
}
//************************MÉTODO**PARA**LIMPIAR**CURVAS******************************
Graphics::TBitmap * TProcImg::CleanCurve(Graphics::TBitmap *imgO)
{

/*       c= width= col,  r= height= ren
--------------------
|c-1, |  *   |c+1, |
|r-1  |c,r-1 |r-1  |
|-----|------|-----|
|c-1, |  *   | c+1,|
| r * | c,r  |  r  |
|-----|------|-----|
|c-1, |c,r+1 |c+1, |
|r+1  |      |r+1  |
--------------------  */


}

//************************MÉTODO**CUENTA**DE**OBJETOS**Y**AREAS******************************
void TProcImg::CountOA(Graphics::TBitmap *imgO)
//AnsiString TProcImg::CountOA(Graphics::TBitmap *imgO)
{


}


//************MÉTODO AREA DEL OBJETO*************************************************************
int TProcImg::Area(Graphics::TBitmap *img)
{

}

//************************MÉTODO**ZOOM**BILINEAR******************************
Graphics::TBitmap * TProcImg::MetBilinear(Graphics::TBitmap *imgO, double zoom)
{

  int w= imgO->Width;  //tamaño original
  int h= imgO->Height;
  int wz= w*zoom;     //tamano original x el zoom
  int hz= h*zoom;
  int **bmpR, **bmpG, **bmpB;
  int **bmpRZ, **bmpGZ, **bmpBZ;
  BYTE *Lbmp;
  int nR,nG, nB;


  bmpR= BmpToMtxRed(imgO); // de bitmap a matriz de enteros rojos
  bmpG= BmpToMtxGreen(imgO); // de bitmap a matriz de enteros verde
  bmpB= BmpToMtxBlue(imgO); // de bitmap a matriz de enteros azul

  bmpRZ = new int * [hz] ;  //renglon
    for(int i =0 ; i<  hz ; i++)
    {
       bmpRZ[i] = new int [wz] ;
       for(int j =0 ; j< wz ; j++)//columna
          bmpRZ[i][j] = 0 ;
    }
 bmpGZ = new int * [hz] ;  //renglon
    for(int i =0 ; i<  hz ; i++)
    {
       bmpGZ[i] = new int [wz] ;
       for(int j =0 ; j< wz ; j++)//columna
          bmpGZ[i][j] = 0 ;
    }
 bmpBZ = new int * [hz] ;  //renglon
    for(int i =0 ; i<  hz ; i++)
    {
       bmpBZ[i] = new int [wz] ;
       for(int j =0 ; j< wz ; j++)//columna
          bmpBZ[i][j] = 0 ;
    }



  double scaleX= (double) w/wz;
  double scaleY= (double) h/hz;

  for(int r=0; r< hz; r++)
  {
    double srcY= scaleY*r;
    for(int c=0; c< wz; c++)
     {
       double srcX= scaleX*c;
       bmpRZ[r][c]= interpola(srcX, srcY, bmpR,w,h);
       bmpGZ[r][c]= interpola(srcX, srcY, bmpG,w,h);
       bmpBZ[r][c]= interpola(srcX, srcY, bmpB,w,h);

     }

  }

 Graphics::TBitmap *bmpS= new Graphics::TBitmap();// creo un bitmap destino
 imgO->Width= wz;
 imgO->Height= hz;
 bmpS->Assign(imgO);



  for(int i=0; i < hz; i++)
  {
    Lbmp =(BYTE *) bmpS->ScanLine[i];

    for(int j=0; j < wz; j++)
    {
      Lbmp[j*3]= bmpBZ[i][j]; // este es para el azul
      Lbmp[j*3+1]= bmpGZ[i][j];// este es para el verde
      Lbmp[j*3+2]= bmpRZ[i][j];// este es para el rojo
    }
  }


return bmpS;
}


//************MÉTODO**DE**INTERPOLACION********************************************************

int TProcImg::interpola(double x, double y, int **mtx, int w, int h )
{
      int px = (int)x;
      int py = (int)y;

      double u = x - px;
      double v = y - py;

      //if (px < 0 || px >= w || py < 0 || py >= h)
      //   return 0;

      int p00 = mtx[py][px];
      int p01 = (px < w-1) ? mtx[py][px + 1] : p00;
      int p10 = (py < h-1) ? mtx[py+1][px] : p00;
      int p11 = (py < h-1 && px < w-1) ? mtx[py+1][px+1] : p00;

      double interp = (1-v) * ((1 - u) * p00 + u * p01) +
                        v * ((1-u) * p10 + u * p11);


      return (int)interp;
}

//****************DE**BMP**A**MATRIZ**DE**ROJOS************************************
int** TProcImg::BmpToMtxRed(Graphics::TBitmap *bmpO) // de bitmap a matriz de enteros
{
BYTE *Lbmp;
int nR,nG, nB;
int **mtxR;

 mtxR = new int*[bmpO->Height];  //ren
  for (int j= 0; j < bmpO->Height; j++)
      mtxR[j] = new int[bmpO->Width]; //col

  for(int i=0; i < bmpO->Height; i++)
  {
    Lbmp =(BYTE *) bmpO->ScanLine[i];

    for(int j=0; j < bmpO->Width; j++)
    {
      nR =Lbmp[j*3+2]; // este es para el rojo
     mtxR[i][j]= nR;
    }
  }

 return mtxR;
}

//****************DE**BMP**A**MATRIZ**DE**VERDES************************************
int** TProcImg::BmpToMtxGreen(Graphics::TBitmap *bmpO) // de bitmap a matriz de enteros
{
BYTE *Lbmp;
int nR,nG, nB;
int **mtxG;

 mtxG = new int*[bmpO->Height];  //ren
  for (int j= 0; j < bmpO->Height; j++)
      mtxG[j] = new int[bmpO->Width]; //col

  for(int i=0; i < bmpO->Height; i++)
  {
    Lbmp =(BYTE *) bmpO->ScanLine[i];

    for(int j=0; j < bmpO->Width; j++)
    {
      nG =Lbmp[j*3+1]; // este es para el verde
     mtxG[i][j]= nG;
    }
  }

 return mtxG;

}
//****************DE**BMP**A**MATRIZ**DE**AZULES************************************
int** TProcImg::BmpToMtxBlue(Graphics::TBitmap *bmpO) // de bitmap a matriz de enteros
{
BYTE *Lbmp;
int nR,nG, nB;
int **mtxB;

 mtxB = new int*[bmpO->Height];  //ren
  for (int j= 0; j < bmpO->Height; j++)
      mtxB[j] = new int[bmpO->Width]; //col

  for(int i=0; i < bmpO->Height; i++)
  {
    Lbmp =(BYTE *) bmpO->ScanLine[i];

    for(int j=0; j < bmpO->Width; j++)
    {
      nB =Lbmp[j*3]; // este es para el azul
     mtxB[i][j]= nB;
    }
  }

 return mtxB;

}

//---------------------------------------------------------------------------------------------------
int TProcImg::max1(int a,int b)
{
if(a>=b)
return a;
else
return b;
}
int TProcImg::min1(int a,int b)
{
if(a<=b)
return a;
else
return b;
}

//Funciones de minh y maxh---------------------------------------------------

    Graphics::TBitmap* TProcImg::Resh(Graphics::TBitmap* bmpIn, int h){
        BYTE *gl1, *gl2;
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(bmpIn);
        for(int i = 0; i < bmpIn->Height; i++){
           gl1 = (BYTE *) bmpIn->ScanLine[i];
           gl2 = (BYTE *) bmpOut->ScanLine[i];
           for(int j = 0; j < bmpIn->Width; j++){
                 gl2[j * 3] = ((gl1[j * 3] - h) < 0)?0:gl1[j * 3] - h;
                 gl2[j * 3 + 1] = ((gl1[j * 3 + 1] - h) < 0)?0:gl1[j * 3 + 1] - h;
                 gl2[j * 3 + 2] = ((gl1[j * 3 + 2] - h) < 0)?0:gl1[j * 3 + 2] - h; 
           }
        }
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::Sumh(Graphics::TBitmap* bmpIn, int h){
        BYTE *gl1, *gl2;
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(bmpIn);
        for(int i = 0; i < bmpIn->Height; i++){
           gl1 = (BYTE *) bmpIn->ScanLine[i];
           gl2 = (BYTE *) bmpOut->ScanLine[i];
           for(int j = 0; j < bmpIn->Width; j++){
               gl2[j * 3] = ((gl1[j * 3] + h) > 255)?255:gl1[j * 3] + h;
                 gl2[j * 3 + 1] = ((gl1[j * 3 + 1] + h) > 255)?255:gl1[j * 3 + 1] + h;
                 gl2[j * 3 + 2] = ((gl1[j * 3 + 2] + h) > 255)?255:gl1[j * 3 + 2] + h; 
           }
        }
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::Mulh(Graphics::TBitmap* bmpIn, int h){
        BYTE *gl1, *gl2;
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(bmpIn);
        for(int i = 0; i < bmpIn->Height; i++){
           gl1 = (BYTE *) bmpIn->ScanLine[i];
           gl2 = (BYTE *) bmpOut->ScanLine[i];
           for(int j = 0; j < bmpIn->Width; j++){
               gl2[j * 3] = ((gl1[j * 3] * h) > 255)?255:gl1[j * 3] * h;
                 gl2[j * 3 + 1] = ((gl1[j * 3 + 1] * h) > 255)?255:gl1[j * 3 + 1] * h;
                 gl2[j * 3 + 2] = ((gl1[j * 3 + 2] * h) > 255)?255:gl1[j * 3 + 2] * h;
           }
        }
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::Divh(Graphics::TBitmap* bmpIn, int h){
        BYTE *gl1, *gl2;
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(bmpIn);
        for(int i = 0; i < bmpIn->Height; i++){
           gl1 = (BYTE *) bmpIn->ScanLine[i];
           gl2 = (BYTE *) bmpOut->ScanLine[i];
           for(int j = 0; j < bmpIn->Width; j++){
               gl2[j * 3] = ((gl1[j * 3] / h) > 255)?255:gl1[j * 3] / h;
                 gl2[j * 3 + 1] = ((gl1[j * 3 + 1] / h) > 255)?255:gl1[j * 3 + 1] / h;
                 gl2[j * 3 + 2] = ((gl1[j * 3 + 2] / h) > 255)?255:gl1[j * 3 + 2] / h;
           }
        }
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::RecGD(Graphics::TBitmap* masc, Graphics::TBitmap* marc){
        Graphics::TBitmap* ee = new Graphics::TBitmap();
        Graphics::TBitmap* marcact = new Graphics::TBitmap();
        Graphics::TBitmap* marcant = new Graphics::TBitmap();
        marcact->Assign(marc);
        int r;
        ee->PixelFormat = pf24bit;
        ee->Width = 3;
        ee->Height = 3;
        for(int i = 0; i  < ee->Height; i++){
           BYTE* line = (BYTE *) ee->ScanLine[i];
           for(int j = 0; j < ee->Width; j++){
               line[j] = 0;
               line[j * 3 + 1] = 0;
               line[j * 3 + 2] = 0;
           }
        }
        do{
            Graphics::TBitmap* aux;
            marcant->Assign(marcact);
            aux = FSEB->Morpho->dilateG(marcact, ee, 1,1);
            marcact->Assign(aux);
            aux->FreeImage();
            delete aux;
            aux = FSEB->Morpho->dilRec(marcact, masc);
            marcact->Assign(aux);
            aux->FreeImage();
            delete aux;
            aux = subImgs(marcant, marcact);
            r = Scan(aux);
            aux->FreeImage();
            delete aux;
        }while(r);
        ee->FreeImage();
        delete ee;
        marcant->FreeImage();
        delete marcant;
        return marcact;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::RecGE(Graphics::TBitmap* masc, Graphics::TBitmap* marc){
        Graphics::TBitmap* ee = new Graphics::TBitmap();
        Graphics::TBitmap* marcact = new Graphics::TBitmap();
        Graphics::TBitmap* marcant = new Graphics::TBitmap();
        marcact->Assign(marc);
        int r;
        ee->PixelFormat = pf24bit;
        ee->Width = 3;
        ee->Height = 3;
        for(int i = 0; i  < ee->Height; i++){
           BYTE* line = (BYTE *) ee->ScanLine[i];
           for(int j = 0; j < ee->Width; j++){
               line[j * 3] = 0;
               line[j * 3 + 1] = 0;
               line[j * 3 + 2] = 0;
           }
        }
        do{
            Graphics::TBitmap* aux;
            marcant->Assign(marcact);
            aux = FSEB->Morpho->erodeG(marcact, ee, 1,1);
            marcact->Assign(aux);
            aux->FreeImage();
            delete aux;
            aux = FSEB->Morpho->eroRec(marcact, masc);
            marcact->Assign(aux);
            aux->FreeImage();
            delete aux;
            aux = subImgs(marcant, marcact);
            r = Scan(aux);
            aux->FreeImage();
            delete aux;
        }while(r);
        ee->FreeImage();
        delete ee;
        marcant->FreeImage();
        delete marcant;
        return marcact;
    }


//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::Maxh(Graphics::TBitmap* bmpIn, int h){
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(Resh(bmpIn, h));
        bmpOut->Assign(RecGD(bmpIn, bmpOut));
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::Minh(Graphics::TBitmap* bmpIn, int h){
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(Sumh(bmpIn, h));
        bmpOut->Assign(RecGE(bmpIn, bmpOut));
        return bmpOut;
    }

//---------------------------------------------------------------------------

    Graphics::TBitmap* TProcImg::NGG(Graphics::TBitmap* bmpIn){
        BYTE *gl1;
        Graphics::TBitmap* bmpOut = new Graphics::TBitmap();
        bmpOut->Assign(bmpIn);
        for(int i = 0; i < bmpOut->Height; i++){
           gl1 = (BYTE *) bmpOut->ScanLine[i];
           for(int j = 0; j < bmpOut->Width; j++){
                 gl1[j * 3] = gl1[j * 3 + 1];
                 gl1[j * 3 + 2] = gl1[j * 3 + 1];
           }
        }
        return bmpOut;

    }

//---------------------------------------------------------------------------

    void TProcImg::Hist(Graphics::TBitmap* bmpIn, int* hist, int columns){
       BYTE* gl;
       for(int j=0; j < columns; j++)
           hist[j]=0;
       for(int i=0; i< bmpIn->Height; i++){
           gl=(BYTE *) bmpIn->ScanLine[i];
           for(int j=0; j< bmpIn->Width; j++){
               hist[gl[j*3]]++;
           }
       }
    }

//---------------------------------------------------------------------------

    int TProcImg::nivMax(int* hist, int columns){
        int max = 0;
        for(int i = 1; i < columns; i++)
            if(hist[max] < hist[i])
                max = i;
        return max;
    }

//---------------------------------------------------------------------------

    int TProcImg::nivMin(int* hist, int columns){
        int min = 0;
        for(int i = 1; i < columns; i++)
            if(hist[min] > hist[i])
                min = i;
        return min;
    }

//---------------------------------------------------------------------------

    int* TProcImg::MaxR(int* histog, int tam, int venth)
    {
       if(tam)
       {
           int* nvo = new int[tam];
           for( int i = 0; i < tam; i++)
               nvo[i] = histog[i] != 0 ? histog[i] + 1 : 0;
           int* nvo1 = new int[tam];
           for( int i = 0; i < tam; i++)
               nvo1[i] = 0;
           int eel = venth;
           int ref = eel / 2;
           for(int i = 0; i < tam; i++)
           {
               int max = i;
               for(int j = 0; j < eel; j++)
                   if(((i + j - ref) >= 0) && (tam > (i + j - ref)))
                       if(histog[max] < histog[i + j - ref])
                           max = i + j - ref;
               nvo1[i] = histog[max];
           }
           for(int i = 0; i < tam; i++)
               nvo1[i] = (nvo[i] < nvo1[i]) ? nvo[i] : nvo1[i];
           for(int i = 0; i < tam; i++)
               nvo1[i] = nvo[i] - nvo1[i];
           delete[] nvo;
           return nvo1;
       }
       return NULL;
    }

//---------------------------------------------------------------------------

    int* TProcImg::MinR(int* histog, int tam,int venth)
    {
        if(tam)
       {
           int* nvo = new int[tam];
           for( int i = 0; i < tam; i++)
               nvo[i] = histog[i] != 0 ? histog[i] + 1 : 0;
           int* nvo1 = new int[tam];
           for( int i = 0; i < tam; i++)
               nvo1[i] = 0;
           int eel = venth;
           int ref = eel / 2;
           for(int i = 0; i < tam; i++)
           {
               int max = i;
               for(int j = 0; j < eel; j++)
                   if(((i + j - ref) >= 0) && (tam >(i + j - ref)))
                       if((nvo[max] > nvo[i + j - ref]) && (nvo[i + j - ref] > 0)) //Prueba de nvo[i + j - ref] > 0
                           max = i + j - ref;
               nvo1[i] = nvo[max];
           }
           for(int i = 0; i < tam; i++)
               nvo[i] = (histog[i] > nvo1[i]) ? histog[i] : nvo1[i];
           for(int i = 0; i < tam; i++)
               nvo1[i] = nvo[i] - histog[i];
           delete[] nvo;
           return nvo1;
       }
       return NULL;
    }

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Rmax(Graphics::TBitmap *bmpIn)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Rmin(Graphics::TBitmap* bmpIn)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Emax(Graphics::TBitmap* bmpIn, int h)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Emin(Graphics::TBitmap* bmpIn, int h)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::hconvex(Graphics::TBitmap* bmpIn, int h)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::hconcave(Graphics::TBitmap* bmpIn, int h)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::subImgs(Graphics::TBitmap* bmpSust, Graphics::TBitmap* bmpsustry)
{
    Graphics::TBitmap* sust = new Graphics::TBitmap();
    int x, y;
    x = (bmpSust->Width > bmpsustry->Width)?bmpSust->Width:bmpsustry->Width;
    y = (bmpSust->Height > bmpsustry->Height)?bmpSust->Height:bmpsustry->Height;
    BYTE *line, *line2, *line3;
    sust->Assign(bmpSust);
    sust->Width = x;
    sust->Height = y;
    for(int i = 0; i < y; i++)
    {
        line = (BYTE *) bmpSust->ScanLine[i];
        line2 = (BYTE *) bmpsustry->ScanLine[i];
        line3 = (BYTE *) sust->ScanLine[i];
        for(int j = 0; j < x; j++)
        {
            line3[j * 3] = (line[j * 3] - line2[j * 3]) % 256;
            line3[j * 3 + 1] = (line[j * 3 + 1] - line2[j * 3 + 1]) % 256;
            line3[j * 3 + 2] = (line[j * 3 + 2] - line2[j * 3 + 2]) % 256;
        }
    }

    return sust;
}
//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::QuitarObjetosBorde(Graphics::TBitmap* imgIn, int obj, int bkg,int CC)
{

}
//---------------------------------------------------------------------------

int** TProcImg::etiquetasBorde(Graphics::TBitmap* imgEt, int obj, int bkg, int CC)
{
   
}

//---------------------------------------------------------------------------


Graphics::TBitmap* TProcImg::etiquetar(Graphics::TBitmap* imgIn, int obj, int bkg,int CC, int& noo)
{

}

//---------------------------------------------------------------------------

int** TProcImg::etiquetas(Graphics::TBitmap* imgEt, int obj, int bkg, int CC)
{

}

//---------------------------------------------------------------------------

int TProcImg::objs(int** matlab, int rows, int cols, int bkg)
{

}

//---------------------------------------------------------------------------

long TProcImg::cantcolor(Graphics::TBitmap* imgIn, int ncolor)
{

}

//---------------------------------------------------------------------------

int TProcImg::mmax(int* hist, int* maxs, int cols)
{

}

//---------------------------------------------------------------------------

int* TProcImg::ordena(int* histg, int cols)
{

}

//---------------------------------------------------------------------------

double TProcImg::omega(int q, int k, int* histimg)
{

}

//---------------------------------------------------------------------------

double TProcImg::miu(int q, int k, double omga, int* histimg)
{

}

//---------------------------------------------------------------------------

int TProcImg::nivotsu(Graphics::TBitmap* imgIn)
{

}

//---------------------------------------------------------------------------

int TProcImg::numtotpix(int* histimg, int nvls)
{

}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Impmin(Graphics::TBitmap* bmpIn)
{
   
}

//---------------------------------------------------------------------------

Graphics::TBitmap* TProcImg::Impmax(Graphics::TBitmap* bmpIn)
{
    
}

//---------------------------------------------------------------------------
Graphics::TBitmap* TProcImg::Fillhole(Graphics::TBitmap* bmpIn)
{

}
//---------------------------------------------------------------------------
void TProcImg::NearestNeighborZoom(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto)
{
int w= BitmapZoom->Width;
int h= BitmapZoom->Height;

BitmapZoom->Width = BitmapOriginal->Width*ancho;
BitmapZoom->Height = BitmapOriginal->Height*alto;

int nw = w * ancho;
int nh = h * alto;
byte **R = MainForm->Pdi->getR(BitmapOriginal);
byte **R2 = new byte*[nw];
byte **G = MainForm->Pdi->getG(BitmapOriginal);
byte **G2 = new byte*[nw];
byte **B = MainForm->Pdi->getB(BitmapOriginal);
byte **B2 = new byte*[nw];


int x0=0, y0=0;
float conteo=0;
float conteoy=0;
for(int i=0; i< nw ; i++){
 R2[i] = new byte[nh];
 G2[i] = new byte[nh];
 B2[i] = new byte[nh];
}
for(int j=0;j<nh;j++)
 for(int i=0;i<nw;i++){
    int x= INT((i+(ancho-1)*x0)/ancho);
    int y= INT((j+(alto-1)*y0)/alto);
    R2[i][j]=R[x][y];
    G2[i][j]=G[x][y];
    B2[i][j]=B[x][y];
 }
ColocaMatricesRGBenBitmap(R2,G2,B2,BitmapZoom);
}
//---------------------------------------------------------------------------
void TProcImg::InterpolacionBilineal(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto)
{
int w = BitmapOriginal->Width;
int h = BitmapOriginal->Height;
BitmapZoom->Width=BitmapOriginal->Width*ancho;
BitmapZoom->Height=BitmapOriginal->Height*alto;

int nw = w * ancho;
int nh = h * alto;

byte **R = getR(BitmapOriginal);
byte **R2 = new byte*[nw];

byte **G = getG(BitmapOriginal);
byte **G2 = new byte*[nw];

byte **B = getB(BitmapOriginal);
byte **B2 = new byte*[nw];

for(int i=0; i< nw ; i++){
     R2[i] = new byte[nh];
     G2[i] = new byte[nh];
     B2[i] = new byte[nh];
}
double scaleX = (double)w / nw;
double scaleY = (double)h / nh;

for (int j = 0; j < nh; j++){
      double srcY = scaleY * j;
      for (int i = 0; i < nw; i++){
          double srcX = scaleX * i;
          R2[i][j] = interpola(srcX,srcY,R,w,h);
          G2[i][j] = interpola(srcX,srcY,G,w,h);
          B2[i][j] = interpola(srcX,srcY,B,w,h);
         }
     }
ColocaMatricesRGBenBitmap(R2,G2,B2,BitmapZoom);
}
//-----------------------------------------------------------------------------
byte TProcImg::interpola(double x, double y, byte **Canal,int w, int h){
int px = (int)x;
int py = (int)y;

double u = x - px;
double v = y - py;
if (px < 0 || px >= w || py < 0 || py >= h)
return 0;

int p00 = Canal[px][py];
int p01 = (px < w - 1) ? Canal[px + 1][py] : p00;
int p10 = (py < h - 1) ? Canal[px][py+1] : p00;
int p11 = (py < h - 1 && px < w - 1) ? Canal[px+1][py+1] : p00;


double interp = (1-v) * ((1 - u) * p00 + u * p01) +
                        v * ((1-u) * p10 + u * p11);

return (byte)interp;
}
//----------------------------------------------------------------------------
byte** TProcImg::getR(Graphics::TBitmap* BMP){
int imageWidth = BMP->Width;
int imageHeight = BMP->Height;
byte **r = new byte*[imageWidth];

for(int i=0; i<imageWidth ; i++){
        r[i] = new byte[imageHeight];
}

RGBTRIPLE *buffer;
for(int j=0; j<imageHeight;j++){
buffer=(RGBTRIPLE*)BMP->ScanLine[j];
for(int i =0;i<imageWidth;i++){
        r[i][j] = (byte) buffer[i].rgbtRed;
}
}

return r;
}
//----------------------------------------------------------------------------
byte** TProcImg::getG(Graphics::TBitmap* BMP){
        //obtiene el tamaño de la imagen
        int imageWidth = BMP->Width;
	int imageHeight = BMP->Height;
        byte **g = new byte*[imageWidth];

        for(int i=0; i<imageWidth ; i++){
                g[i] = new byte[imageHeight];
        }
        RGBTRIPLE *buffer;
        for(int j=0; j<imageHeight;j++){
             buffer=(RGBTRIPLE*)BMP->ScanLine[j];
            for(int i =0;i<imageWidth;i++){
                        g[i][j] = (byte) buffer[i].rgbtGreen;
             }
        }
        return g;
}
//----------------------------------------------------------------------------
byte** TProcImg::getB(Graphics::TBitmap* BMP){
        //obtiene el tamaño de la imagen
        int imageWidth = BMP->Width;
      	int imageHeight = BMP->Height;
        byte **b = new byte*[imageWidth];

        for(int i=0; i<imageWidth ; i++){
                b[i] = new byte[imageHeight];
        }
        RGBTRIPLE *buffer;
        for(int j=0; j<imageHeight;j++){
             buffer=(RGBTRIPLE*)BMP->ScanLine[j];
            for(int i =0;i<imageWidth;i++){
                        b[i][j] = (byte) buffer[i].rgbtBlue;
             }
        }
  return b;
}
//----------------------------------------------------------------------------
void TProcImg::EscalarImagen(TImage *ImageEscalada,int anchoOriginal,int altoOriginal,int Top,int Left,int AnchoAltoImageForm,TBevel *BevelImagen)
{
if(anchoOriginal==altoOriginal && altoOriginal>=AnchoAltoImageForm){
           ImageEscalada->Height=AnchoAltoImageForm;
           ImageEscalada->Width=AnchoAltoImageForm;
}
else if(altoOriginal>anchoOriginal && altoOriginal>=AnchoAltoImageForm){
           ImageEscalada->Height=AnchoAltoImageForm;
           ImageEscalada->Width=(AnchoAltoImageForm*anchoOriginal)/altoOriginal;
}
else if(altoOriginal<anchoOriginal && anchoOriginal>=AnchoAltoImageForm){
           ImageEscalada->Width=AnchoAltoImageForm;
           ImageEscalada->Height=(AnchoAltoImageForm*altoOriginal)/anchoOriginal;
}
else{
ImageEscalada->Height=altoOriginal;
ImageEscalada->Width=anchoOriginal;
}
if(BevelImagen->Height>=ImageEscalada->Height){
ImageEscalada->Top = BevelImagen->Top+((BevelImagen->Height - ImageEscalada->Height)/2);
}
else{
ImageEscalada->Top = Top;
}
if(BevelImagen->Width>=ImageEscalada->Width){
ImageEscalada->Left = BevelImagen->Left+((BevelImagen->Width - ImageEscalada->Width)/2);
}
else{
ImageEscalada->Left = Left;
}
}
//----------------------------------------------------------------------------
void TProcImg::ZoomImagen(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float escalaAncho,float escalaAlto)
{
TRect rectangulo;
rectangulo.Top=0;
rectangulo.Left=0;
rectangulo.Right=BitmapOriginal->Width*escalaAncho;
rectangulo.Bottom=BitmapOriginal->Height*escalaAlto;
BitmapZoom->Width=BitmapOriginal->Width*escalaAncho;
BitmapZoom->Height=BitmapOriginal->Height*escalaAlto;
BitmapZoom->Canvas->StretchDraw(rectangulo,BitmapOriginal);
}
//---------------------------------------------------------------------------
void TProcImg::IgualarImagen(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,int ancho,int alto)
{
TRect rectangulo;
rectangulo.Top=0;
rectangulo.Left=0;
rectangulo.Right=ancho;
rectangulo.Bottom=alto;
BitmapZoom->Width=ancho;
BitmapZoom->Height=alto;
BitmapZoom->Canvas->StretchDraw(rectangulo,BitmapOriginal);
}
//---------------------------------------------------------------------------
void TProcImg::PromedioOIntensidadImagen(Graphics::TBitmap* BitmapPoI)
{
//ESTE METODO OBTIENE LA ESCALA DE GRISES PROMEDIADA
BYTE *P;//PARA RECORRER UNA IMAGEN SERÁ FUNDAMENTAL UN APUNTADOR (O ARREGLO DINAMICO) DE BYTES, YA QUE CADA COMPONENTE DEL PIXEL ES UN BYTE
for (int i=0;  i<BitmapPoI->Height; i++)//NORMALMENTE SE INICIA CON LA ALTURA DE LA IMAGEN DE 0 A Npx (EN ALTURA)
        {
            P=(BYTE *)BitmapPoI->ScanLine[i];//AQUI ES DONDE SE USA EL APUNTADOR, YA QUE EN ESTE SE ALMACENA CADA "FILA" DE LA IMAGEN
            for (int j=0; j<BitmapPoI->Width; j++) //UNA VEZ OBTENIDA LA FILA SE RECORRE BYTE A BYTE (EN ANCHURA)
                {
                      if(!(P[j*3+1]==0 && P[j*3+2]==0 && P[j*3]==0)){  //PIXEL VERDE, PIXEL ROJO, PIXEL AZUL
                      P[j*3+1]=((float)(P[j*3]+P[j*3+1]+P[j*3+2]))/3;     //Verde
                      P[j*3]= P[j*3+1];   //Azul
                      P[j*3+2]= P[j*3+1];   //Rojo
                      }
                }
        }
}
//---------------------------------------------------------------------------
void TProcImg::Saturacion(Graphics::TBitmap* BitmapPoI)
{

}
//---------------------------------------------------------------------------
void TProcImg::Matiz(Graphics::TBitmap* BitmapPoI)
{

}
//---------------------------------------------------------------------------
void TProcImg::BitPlane(int plane,Graphics::TBitmap* BitmapPlano)
{
BYTE *p0;
for (int y=0;  y<BitmapPlano->Height; y++)
        {
            p0=(BYTE *)BitmapPlano->ScanLine[y];
            for (int x=0; x<BitmapPlano->Width; x++)
                {
                      p0[x*3]=(p0[x*3]&(BYTE)pow(2,plane))!=0 ? 255:0;    // Modifica el valor de Azul con la LUT
                      p0[x*3+1]=(p0[x*3+1]&(BYTE)pow(2,plane))!=0 ? 255:0;  // Modifica el valor de Verde con la LUT
                      p0[x*3+2]=(p0[x*3+2]&(BYTE)pow(2,plane))!=0 ? 255:0;  // Modifica el valor de Rojo con la LUT
                }
        }
}
//---------------------------------------------------------------------------
void TProcImg::GrayScaleWeighted(Graphics::TBitmap* BitmapGrayScale)  //ESCALA DE GRISES PONDERADA (NTSC)
{
BYTE *p0;  //EL APUNTADOR A BYTE QUE ES OBLIGATORIO
for (int y=0;  y<BitmapGrayScale->Height; y++)     //RECORRER LA IMAGEN EN ALTURA
        {
            p0=(BYTE *)BitmapGrayScale->ScanLine[y]; //USAR CADA FILA DE LA IMAGEN
            for (int x=0; x<BitmapGrayScale->Width; x++)
                {
                      int R=(int)p0[x*3+2];//COMPONENTE ROJA
                      int G=(int)p0[x*3+1];//COMPONENTE VERDE
                      int B=(int)p0[x*3]; //COMPONENTE AZUL
                      long double dato3= 0.299*(double)R;//APLICA LA FORMULA A CADA COMPNENTE
                      long double dato2= 0.587*(double)G;
                      long double dato1= 0.114*(double)B;
                      double final2=dato1+dato2+dato3;//SUMAR LAS COMPONENTES
                      int final= final2;//IGUALAR UN DOUBLE A UN ENTRO (PARA RESTAR PRECISIÓN Y QUITAR EL PUNTO DECIMAL)
                      p0[x*3+1]= (Byte)final;//ESTABLECER LAS COMPONENTES AL MISMO VALOR
                      p0[x*3]=  (Byte)final;
                      p0[x*3+2]=  (Byte)final;
                      }
                }
}
//---------------------------------------------------------------------------
void TProcImg::CanalRojo(Graphics::TBitmap* BitmapRojo)
{

}
//---------------------------------------------------------------------------
void TProcImg::CanalVerde(Graphics::TBitmap* BitmapVerde)
{

}
//---------------------------------------------------------------------------
void TProcImg::CanalAzul(Graphics::TBitmap* BitmapAzul)
{

}
//---------------------------------------------------------------------------
void TProcImg::CanalRojoGris(Graphics::TBitmap* BitmapRojo)
{
BYTE *p0;
for (int y=0;  y<BitmapRojo->Height; y++)
        {
            p0=(BYTE *)BitmapRojo->ScanLine[y];
            for (int x=0; x<BitmapRojo->Width; x++)
                {
                p0[x*3]=p0[x*3+1]=p0[x*3+2];
                }
            }
}
//---------------------------------------------------------------------------
void TProcImg::CanalVerdeGris(Graphics::TBitmap* BitmapVerde)
{
BYTE *p0;
for (int y=0;  y<BitmapVerde->Height; y++)
        {
            p0=(BYTE *)BitmapVerde->ScanLine[y];
            for (int x=0; x<BitmapVerde->Width; x++)
                {
               p0[x*3]=p0[x*3+2]=p0[x*3+1];
                }
            }
}
//---------------------------------------------------------------------------
void TProcImg::CanalAzulGris(Graphics::TBitmap* BitmapAzul)
{
BYTE *p0;
for (int y=0;  y<BitmapAzul->Height; y++)
        {
            p0=(BYTE *)BitmapAzul->ScanLine[y];
            for (int x=0; x<BitmapAzul->Width; x++)
                {
                p0[x*3+2]=p0[x*3+1]=p0[x*3];
                }
            }
}
//---------------------------------------------------------------------------
void TProcImg::CanalesRG(Graphics::TBitmap* BitmapRG)
{

}
//---------------------------------------------------------------------------
void TProcImg::CanalesRB(Graphics::TBitmap* BitmapRB)
{

}
//---------------------------------------------------------------------------
void TProcImg::CanalesGB(Graphics::TBitmap* BitmapGB)
{

}
//---------------------------------------------------------------------------
void TProcImg::OperacionLogica(char operacion,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe)
{
BYTE *P1,*P2,*POpe;
        for(int i=0; i<BitmapOpe->Height; i++)
        {
                P1=(BYTE *)Bitmap1->ScanLine[i];
                P2=(BYTE *)Bitmap2->ScanLine[i];
                POpe=(BYTE *)BitmapOpe->ScanLine[i];
                for(int j=0; j<BitmapOpe->Width; j++)
                {
                switch (operacion) {
                        case '&' :
                                 POpe[j*3]=P1[j*3]&P2[j*3];
                                 POpe[j*3+1]=P1[j*3+1]&P2[j*3+1];
                                 POpe[j*3+2]=P1[j*3+2]&P2[j*3+2];
                                 break;
                        case '|' :
                                 POpe[j*3]=P1[j*3]|P2[j*3];
                                 POpe[j*3+1]=P1[j*3+1]|P2[j*3+1];
                                 POpe[j*3+2]=P1[j*3+2]|P2[j*3+2];
                                 break;
                        case '^' :
                                 POpe[j*3]=P1[j*3]^P2[j*3];
                                 POpe[j*3+1]=P1[j*3+1]^P2[j*3+1];
                                 POpe[j*3+2]=P1[j*3+2]^P2[j*3+2];
                                 break;
                }
                }
         }
}
//---------------------------------------------------------------------------
void TProcImg::OperacionArtimetica(char operacion,char opcion,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe)
{
BYTE *P1,*P2,*P3;
int resultado,i,j;
int y=BitmapOpe->Height;
int x=BitmapOpe->Width;
                switch (operacion) {
                        case '+' : //suma
                                 switch (opcion) {
                                        case 'L' ://limitada
                                                for(i=0;i<y;i++){
                                                P1=(BYTE*)Bitmap1->ScanLine[i];//op1
                                                P2=(BYTE*)Bitmap2->ScanLine[i]; //op2
                                                P3=(BYTE*)BitmapOpe->ScanLine[i];//resultado
                                                for(j=0;j<x;j++){
                                                  resultado = (P1[j*3]+P2[j*3]);  //resultado para azul
                                                  if(resultado>255){resultado = 255;} //si rebasa los 255 se forza el resulado
                                                  else if (resultado<0){resultado =  0;}  //si x algo el valor es negativo, se forza el cero
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]+P2[j*3+1]);  //resultado para verde
                                                  if(resultado>255){resultado = 255;} //limitar el resultado
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]+P2[j*3+2]);//resultado para rojo
                                                  if(resultado>255){resultado = 255;} //limitar resultado
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+2] = resultado;
                                                }
                                               }
                                        break;
                                        case 'S' ://escalado
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];//operandos
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];//resultado
                                                 for(j=0;j<x;j++){
                                                 P3[j*3] = abs((255*(P1[j*3]+P2[j*3]))/510);//escala para la suma de los dos valores px azul
                                                 P3[j*3+1] = abs((255*(P1[j*3+1]+P2[j*3+1]))/510);  //px verde
                                                 P3[j*3+2] = abs((255*(P1[j*3+2]+P2[j*3+2]))/510); //px rojo
                                                 }
                                                }
                                        break;
                                        case 'C' : //ciclico
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                  resultado = (P1[j*3]+P2[j*3]);//suma de valores para azul
                                                  if(resultado>255){ //hacer ciclico el resultado
                                                        resultado = resultado-256;}  //si el valor es 256 poner a 0, 257 a 1, ...
                                                  else if (resultado<0){
                                                        resultado =  256+resultado;} //si el resultado es negativo -1 a 255 -2 a 254, ...
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]+P2[j*3+1]);  //para la componente verde verde
                                                  if(resultado>255){    //lo mismo que el paso anterior
                                                        resultado = resultado-256;}
                                                  else if (resultado<0){
                                                        resultado =  256+resultado;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]+P2[j*3+2]);
                                                  if(resultado>255){
                                                        resultado = resultado-256;}
                                                  else if (resultado<0){
                                                        resultado =  256+resultado;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                 }
                                        break;
                                 }
                                 break;
                        case '-' :  //Resta. Mismo procedimiento que para la suma
                                switch (opcion) {
                                        case 'L' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                  resultado = (P1[j*3]-P2[j*3]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]-P2[j*3+1]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]-P2[j*3+2]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                }
                                        break;
                                        case 'S' :
                                                  for(i=0;i<y;i++){
                                                         P1=(BYTE*)Bitmap1->ScanLine[i];
                                                         P2=(BYTE*)Bitmap2->ScanLine[i];
                                                         P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                         for(j=0;j<x;j++){
                                                               P3[j*3] = abs((255*(P1[j*3]-P2[j*3]))/510);
                                                               P3[j*3+1] = abs((255*(P1[j*3+1]-P2[j*3+1]))/510);
                                                               P3[j*3+2] = abs((255*(P1[j*3+2]-P2[j*3+2]))/510);
                                                        }
                                                  }
                                        break;
                                        case 'C' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                  resultado = (P1[j*3]-P2[j*3]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]-P2[j*3+1]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]-P2[j*3+2]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                 }
                                        break;
                                 }
                                 break;
                        case '*' :  //Multiplicación, mismo caso que la suma
                                 switch (opcion) {
                                        case 'L' :
                                                 for(i=0;i<y;i++){
                                                  P1=(BYTE*)Bitmap1->ScanLine[i];
                                                  P2=(BYTE*)Bitmap2->ScanLine[i];
                                                  P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                  for(j=0;j<x;j++){
                                                          resultado = (P1[j*3]*P2[j*3]);
                                                          if(resultado>255){resultado = 255;}
                                                          else if (resultado<0){resultado =  0;}
                                                          P3[j*3] = resultado;
                                                          resultado = (P1[j*3+1]*P2[j*3+1]);
                                                          if(resultado>255){resultado = 255;}
                                                          else if (resultado<0){resultado =  0;}
                                                          P3[j*3+1] = resultado;
                                                          resultado = (P1[j*3+2]*P2[j*3+2]);
                                                          if(resultado>255){resultado = 255;}
                                                          else if (resultado<0){resultado =  0;}
                                                          P3[j*3+2] = resultado;
                                                  }
                                                 }
                                        break;
                                        case 'S' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                 P3[j*3] = abs((255*(P1[j*3]*P2[j*3]))/65025);
                                                 P3[j*3+1] = abs((255*(P1[j*3+1]*P2[j*3+1]))/65025);
                                                 P3[j*3+2] = abs((255*(P1[j*3+2]*P2[j*3+2]))/65025);
                                                 }
                                                }
                                        break;
                                        case 'C' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                   resultado = (P1[j*3]*P2[j*3]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]*P2[j*3+1]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]*P2[j*3+2]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                }
                                        break;
                                 }
                                 break;
                        case '/' :   //división, mismo caso que la suma.
                                 switch (opcion) {
                                        case 'L' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                  if(P2[j*3] == 0){P2[j*3] = 1;}
                                                  if(P2[j*3+1] == 0){P2[j*3+1] = 1;}
                                                  if(P2[j*3+2] == 0){P2[j*3+2] = 1;}
                                                  resultado = (P1[j*3]/P2[j*3]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]/P2[j*3+1]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]/P2[j*3+2]);
                                                  if(resultado>255){resultado = 255;}
                                                  else if (resultado<0){resultado =  0;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                }
                                        break;
                                        case 'S' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                         if(P2[j*3] == 0){P2[j*3] = 1;}
                                                         if(P2[j*3+1] == 0){P2[j*3+1] = 1;}
                                                         if(P2[j*3+2] == 0){P2[j*3+2] = 1;}
                                                         P3[j*3] = abs((P1[j*3]/P2[j*3]));
                                                         P3[j*3+1] = abs((P1[j*3+1]/P2[j*3+1]));
                                                         P3[j*3+2] = abs((P1[j*3+2]/P2[j*3+2]));
                                                 }
                                                }
                                        break;
                                        case 'C' :
                                                for(i=0;i<y;i++){
                                                 P1=(BYTE*)Bitmap1->ScanLine[i];
                                                 P2=(BYTE*)Bitmap2->ScanLine[i];
                                                 P3=(BYTE*)BitmapOpe->ScanLine[i];
                                                 for(j=0;j<x;j++){
                                                  if(P2[j*3] == 0){P2[j*3] = 1;}
                                                  if(P2[j*3+1] == 0){P2[j*3+1] = 1;}
                                                  if(P2[j*3+2] == 0){P2[j*3+2] = 1;}
                                                  resultado = (P1[j*3]/P2[j*3]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3] = resultado;
                                                  resultado = (P1[j*3+1]/P2[j*3+1]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+1] = resultado;
                                                  resultado = (P1[j*3+2]/P2[j*3+2]);
                                                  if(resultado>255){resultado = resultado-256;}
                                                  else if (resultado<0){resultado =  256+resultado;}
                                                  P3[j*3+2] = resultado;
                                                  }
                                                }
                                        break;
                                 }
                                 break;
                }
}
//---------------------------------------------------------------------------
void TProcImg::Negado(Graphics::TBitmap* Bitmap)//NEGACION DE UNA IMAGEN
{
BYTE *P; //NUEVAMENTE EL APUNTADOR A BYTE QUE NOS PERMITIRA ACCEDER A CADA COMPONENTE DE LA IMAGEN
for(int i=0; i<Bitmap->Height; i++){ //RECORRER LA IMAGEN EN ALTURA
        P=(BYTE *)Bitmap->ScanLine[i];//OBTENER LA FILA DE LA IMAGEN
        for(int j=0; j<Bitmap->Width; j++){//RECORRER EN ANCHURA CADA FILA DE LA IMAGEN
                        P[j*3]=~P[j*3]; //NEGACION LOGICA, EQUIVALE A 255-P[j*3]; comp azul
                        P[j*3+1]=~P[j*3+1]; //NEGACION LOGICA, EQUIVALE A 255-P[j*3+1];  comp verde
                        P[j*3+2]=~P[j*3+2]; //NEGACION LOGICA, EQUIVALE A 255-P[j*3+2]; comp roja
        }
}
}
//---------------------------------------------------------------------------
void TProcImg::CombiningRGB(Graphics::TBitmap* BitmapR,Graphics::TBitmap* BitmapG,Graphics::TBitmap* BitmapB,Graphics::TBitmap* BitmapRGB)
{
BYTE *PR,*PG,*PB,*PRGB; //imagen con el canal rojo, verde, azul y resultado
        for(int i=0; i<BitmapRGB->Height; i++)  //recorrer en altura
        {
                PR=(BYTE *)BitmapR->ScanLine[i];//obtener las filas para cada imagen componente y para el resultado
                PG=(BYTE *)BitmapG->ScanLine[i];
                PB=(BYTE *)BitmapB->ScanLine[i];
                PRGB=(BYTE *)BitmapRGB->ScanLine[i];
                for(int j=0; j<BitmapRGB->Width; j++)
                {
                        PRGB[j*3+2] = PR[j*3+2]; //poner la componente roja de la imagen roja
                        PRGB[j*3+1] = PG[j*3+1]; //poner componente verde de la img verde
                        PRGB[j*3+0] = PB[j*3+0]; //componente azul de la imagen azul
                }
         }
}
//---------------------------------------------------------------------------
void TProcImg::CombiningHSIRGB(Graphics::TBitmap* BitmapH,Graphics::TBitmap* BitmapS,Graphics::TBitmap* BitmapI,Graphics::TBitmap* BitmapRGB)
{

}
//---------------------------------------------------------------------------
void TProcImg::ObtenerBordeImagen(Graphics::TBitmap* Bitmap,int PixelsEdge,TColor ColorEdge,int PixelsRest,TColor ColorRest)
{

}
//---------------------------------------------------------------------------
void TProcImg::ColorearObjetos(Graphics::TBitmap* Bitmap,String Rango,TColor PixelsA,TColor PixelsB,TColor Color)
{

}
//---------------------------------------------------------------------------
void TProcImg::ColocaMatricesRGBenBitmap(byte **R,byte **G,byte **B,Graphics::TBitmap* BitmapResultado){
RGBTRIPLE *PixelRGB;  //se puede usar este tipo de dato para abstraer los pixeles
for(int j=0;j<BitmapResultado->Height;j++){ //recorrer en altura
  PixelRGB=(RGBTRIPLE*)BitmapResultado->ScanLine[j]; //hacer un cast de un arreglo de bytes al apuntador RGBTriple
  for(int i=0;i<BitmapResultado->Width;i++){    //recorrer en anchura el apuntador
    PixelRGB[i].rgbtBlue= B[i][j];  //aqui se hace una asignación mas elegante para los componentes del pixel se podria usar en todos los metodos
    PixelRGB[i].rgbtRed= R[i][j];
    PixelRGB[i].rgbtGreen= G[i][j];
    }
  }
}
//----------------------------------------------------------------------------
void TProcImg::InterpolacionBicubic(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto)
{
int in_width = BitmapOriginal->Width;
int in_height = BitmapOriginal->Height;
BitmapZoom->Width=BitmapOriginal->Width*ancho;
BitmapZoom->Height=BitmapOriginal->Height*alto;
int out_width = in_width * ancho;
int out_height = in_height * alto;

byte **f = getR(BitmapOriginal);
byte **g = new byte*[out_width ];
for(int i=0; i< out_width ; i++){
        g[i] = new byte[out_height];
}


int larger_out_dimension;
int n=ancho, d=1, j, k, l, m, index;
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
 ColocaMatricesRGBenBitmap(g,g,g,BitmapZoom);
}
//-----------------------------------------------------------------------------
double TProcImg::C0(double t)
{
  double a;
  return -a * t * t * t + a * t * t;
}
//-----------------------------------------------------------------------------
double TProcImg::C1(double t)
{
  double a;
  return -(a + 2.0f) * t * t * t + (2.0f * a + 3.0f) * t * t - a * t;
}
//-----------------------------------------------------------------------------
double TProcImg::C2(double t)
{
  double a;
  return (a + 2.0f) * t * t * t - (a + 3.0f) * t * t + 1.0f;
}
//-----------------------------------------------------------------------------
double TProcImg::C3(double t)
{
  double a;
  return a * t * t * t - 2.0f * a * t * t + a * t;
}
//-----------------------------------------------------------------------------
void TProcImg::Superimpose(TColor ExceptPixel,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe)
{
BitmapOpe->Assign(Bitmap1);
        for(int i=0; i<BitmapOpe->Width; i++){
                for(int j=0; j<BitmapOpe->Height; j++){
                if(Bitmap2->Canvas->Pixels[i][j]!=ExceptPixel && i<Bitmap2->Width && j<Bitmap2->Height){
                    BitmapOpe->Canvas->Pixels[i][j]=Bitmap2->Canvas->Pixels[i][j];
                  }
                }
        }
}
//-----------------------------------------------------------------------------
void TProcImg::Rotar(float grados,float angle,Graphics::TBitmap* pBitmap,TColor Fondo)
{

}
//-----------------------------------------------------------------------------
void TProcImg::Difuminado(TColor Fondo,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe)
{

}
//-----------------------------------------------------------------------------
void TProcImg::TransparentColors(TColor TransparentColorA,TColor TransparentColorB,String TransparentRango,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe)
{

}
//-----------------------------------------------------------------------------
void TProcImg::RemoveLinesColumnsConstantColor(TColor Fondo,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* BitmapOpe)
{

}
//-----------------------------------------------------------------------------
void TProcImg::RemoveRowsColumnsSimilarEdges(Graphics::TBitmap* Bitmap,Graphics::TBitmap* BitmapOpe)
{

}
//-----------------------------------------------------------------------------
int TProcImg::umbralados(int indice,Graphics::TBitmap* Bitmap)
{
        //obtener la sumatoria hasta U de cada valor del pixel
        //obtener la sumatoria desde U+1 hasta L-1 (255)
        //obtener mu (sumatoria) desde cero hasta U
        //obtener mu (sumatoria) desde U+1 hasta L-1
        //obtener ro (sumatoria) desde cero hasta U
        
}
//---------------------------------------------------------------------------
void TProcImg::DecreaseColor8bit(Graphics::TBitmap* bmp)
{

}
//---------------------------------------------------------------------------
void TProcImg::DecreaseColorXbit(Graphics::TBitmap* bmp,int XColor,TColor ColorList[])
{

}
//---------------------------------------------------------------------------
void TProcImg::FiltroAverage(Graphics::TBitmap* img,float **masc,Graphics::TBitmap* sal,int dim)
{

}
//---------------------------------------------------------------------------


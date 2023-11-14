//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StrucEE.h"
#include "fstream.h"
#include "ElemStrucBi.h"

//---------------------------------------------------------------------------
TStrEE::TStrEE()
{
//  tipo="";
  x=y=0;
  yren=xcol=0;
  bmp = new int*[yren];
   for (int j= 0; j < yren; j++)
          bmp[j] = new int[xcol];

  for(int i=0; i< yren; i++) //height
    for(int j=0; j< xcol; j++)//width
        bmp[i][j]=0;

}

void TStrEE::guarda(char *path)
{
   ofstream f;
   f.open(path);
   f.flush();
//   f<<"[tipo]"<<endl;
//   f<<(char)tipo<<endl;
    f<<"[tamaño]"<<endl;
   f<<(int)yren<<" "<<(int)xcol<<endl;
   f<<"[valores]"<<endl;
  for (int r=0; r< yren;r++)//height
   {
    for (int c=0;c< xcol;c++)//width
      {
         f<<bmp[r][c]<<"\t";
      }
      f<<"\n";
   }

   f<<"[centro]"<<endl;
   f<<(int)x<<" "<<(int)y<<endl;
   f<<"[fin]"<<endl;
   f.close();
}

void TStrEE::carga(char *path)
{
 ifstream f;
   char buffer[255];
   int t;
   f.open(path);
   f>>buffer;
   f>>t;
   xcol =(int)t;
   f>>t;
   yren=(int)t;
   f>>buffer;

  bmp = new int*[yren];
   for (int j= 0; j < yren; j++)
          bmp[j] = new int[xcol];

  for (int r=0; r< yren;r++)//height
   {    for (int c=0;c< xcol;c++)//width
       {  f>>t;
          bmp[r][c]=(int)t;
       }
   }
   f>>buffer;
   f>>t;
   x=(int)t;
   f>>t;
   y=(int)t;
   f>>buffer;
   f.close();
}



//---------------------------------------------------------------------------
#pragma package(smart_init)










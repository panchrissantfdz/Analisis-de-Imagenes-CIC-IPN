//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#pragma hdrstop

#include "MedialAxis.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMedial_Axis *Medial_Axis;
//---------------------------------------------------------------------------
__fastcall TMedial_Axis::TMedial_Axis(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void  EjeMedio( Graphics::TBitmap  *Original , bool c)
{
        int width  = Original->Width;   //Ancho
        int height = Original->Height;  //Altura

        if(    c == true ){

                for(int y = 0; y<height; y++){     //cuenta ancho
                        bool areaEncontrada = false;
                        for(int x = 0; x<width; x++){
                                if( Original->Canvas->Pixels[x][y] == 0) {      //si es pixel negro guarda dato en vector y suma contador
                                        areaEncontrada = true;
                                        int xinit = x;
                                        while(Original->Canvas->Pixels[x][y] == 0 && x < width){
                                                x++;
                                        }
                                        int xend = x;
                                        int medio = xinit + ((xend - xinit) / 2);
                                        Original->Canvas->Pixels[medio][y] = RGB(255,0,0);
                                        areaEncontrada = false;

                                }
                        }
                }

        }
        else{

            for(int y = 0; y<width; y++){     //cuenta ancho
                        bool areaEncontrada = false;
                        for(int x = 0; x<height; x++){
                                if( Original->Canvas->Pixels[y][x] == 0) {      //si es pixel negro guarda dato en vector y suma contador
                                        areaEncontrada = true;
                                        int xinit = x;
                                        while(Original->Canvas->Pixels[y][x] == 0 && x < height){
                                                x++;
                                        }
                                        int xend = x;
                                        int medio = xinit + ((xend - xinit) / 2);
                                        Original->Canvas->Pixels[y][medio] = RGB(255,0,0);
                                        areaEncontrada = false;

                                }
                        }
                }

        }
}


void __fastcall TMedial_Axis::OKClick(TObject *Sender)
{

          bool c;
          if(Vertical->Checked == true){
                c = true;
          }
          else{
                c = false;
          }

         TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;       //llama la imagen
        if(Child!=NULL){
                Graphics::TBitmap *BitmapRuido=new Graphics::TBitmap();     // crea un mapa de bits (BitmapRuido) de la imagen
                BitmapRuido->Assign(Child->ActiveBitmap());                 //crea copia del mapa de bits

             EjeMedio(BitmapRuido, c);                //llamando funcion

         String name=ExtractFilePath(Child->FileName)+"\Eje Medio ="+ExtractFileName(Child->FileName);   // creando nombre del proceso
       // MainForm->CreateMDIChild(name,BitmapSuavizado);
         MainForm->CreateMDIChild(name,BitmapRuido);               //Crea una nueva imagen de la copia y con su nombre del proceso
         BitmapRuido->FreeImage();                     //vacia la variable BitmapEuido
         delete BitmapRuido;                     //libera memoria

         }

        Close();
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#pragma hdrstop

#include "Ruido.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNoise *Noise;

//---------------------------------------------------------------------------
__fastcall TNoise::TNoise(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNoise::Button2Click(TObject *Sender)
{
        Close();
}


  void AplicarRuido(Graphics::TBitmap *bitmap, int v) {

    int width = bitmap->Width;
    int height = bitmap->Height;
    int r;
    float f = v/100;
        srand(time(0));
    // Bucle externo que recorre las filas de la imagen
    for (int y = 0; y < height; y++) {
        // Bucle interno que recorre las columnas de la imagen
        for (int x = 0; x < width; x++) {
             r = rand()%6;
             if(r == 0){
            TColor medianColor;
            int ran = rand() % 256;


            if(ran == 0){
            medianColor = TColor(ran+v);
            }
            else if(ran >= 240){
             medianColor = TColor(ran-v);
             }
             else{

             medianColor = TColor(ran*f);
             }





          // bitmap->Canvas->Pixels[x][y] =  bitmap->Canvas->Pixels[x][y] - medianColor;
          if(bitmap->Canvas->Pixels[x][y] == 0){
                bitmap->Canvas->Pixels[x][y] = RGB(bitmap->Canvas->Pixels[x][y] + medianColor,bitmap->Canvas->Pixels[x][y] + medianColor,bitmap->Canvas->Pixels[x][y] + medianColor) ;
          }
          else{
              // bitmap->Canvas->Pixels[x][y] = RGB(155,0,0);
               bitmap->Canvas->Pixels[x][y] = RGB(bitmap->Canvas->Pixels[x][y] - medianColor,bitmap->Canvas->Pixels[x][y] - medianColor,bitmap->Canvas->Pixels[x][y] - medianColor) ;
          }
           //   bitmap->Canvas->Pixels[x][y] = RGB(bitmap->Canvas->Pixels[x][y],bitmap->Canvas->Pixels[x][y],bitmap->Canvas->Pixels[x][y])  ;
          }


        }
    }
}



//---------------------------------------------------------------------------
void __fastcall TNoise::Button1Click(TObject *Sender)
{
        int valor;
        valor = Valor->Text.ToInt();

         TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
        if(Child!=NULL){
                Graphics::TBitmap *BitmapRuido=new Graphics::TBitmap();
                BitmapRuido->Assign(Child->ActiveBitmap());

              AplicarRuido(BitmapRuido, valor);

         String name=ExtractFilePath(Child->FileName)+"\Ruido Uniforme ="+ExtractFileName(Child->FileName);
       // MainForm->CreateMDIChild(name,BitmapSuavizado);
         MainForm->CreateMDIChild(name,BitmapRuido);
         BitmapRuido->FreeImage();
         delete BitmapRuido;

         }

        Close();

}
//---------------------------------------------------------------------------


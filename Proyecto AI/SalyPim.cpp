//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>
#pragma hdrstop

#include "SalyPim.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSaltnPepper *SaltnPepper;
//---------------------------------------------------------------------------

void AplicarRuido(Graphics::TBitmap *bitmap, int v) {

    int width = bitmap->Width;
    int height = bitmap->Height;
    int r;

    // Bucle externo que recorre las filas de la imagen
    for (int y = 0; y < height; y++) {
        // Bucle interno que recorre las columnas de la imagen
        for (int x = 0; x < width; x++) {
            // r = rand()%2;


            //float randomValue = static_cast<float>(rand()) / RAND_MAX;
                 int ran = rand()%2;
                if(ran != 0){
                      bitmap->Canvas->Pixels[x][y] =  clBlack;
                       }
                else{
                       bitmap->Canvas->Pixels[x][y] =  clWhite;
                       }




        }
    }
}




__fastcall TSaltnPepper::TSaltnPepper(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------






void __fastcall TSaltnPepper::OKClick(TObject *Sender)
{
       int valor;
        valor = 0  ;

         TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
        if(Child!=NULL){
                Graphics::TBitmap *BitmapRuido=new Graphics::TBitmap();
                BitmapRuido->Assign(Child->ActiveBitmap());

              AplicarRuido(BitmapRuido, valor);

         String name=ExtractFilePath(Child->FileName)+"\Ruido Sal y Pimienta ="+ExtractFileName(Child->FileName);
       // MainForm->CreateMDIChild(name,BitmapSuavizado);
         MainForm->CreateMDIChild(name,BitmapRuido);
         BitmapRuido->FreeImage();
         delete BitmapRuido;

         }
        Close();

}
//---------------------------------------------------------------------------


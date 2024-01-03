//---------------------------------------------------------------------------

#include <vcl.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#pragma hdrstop

#include "Exp.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExponencial *Exponencial;
//---------------------------------------------------------------------------
__fastcall TExponencial::TExponencial(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

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



            int ran = rand() % 256;


            float ruidoExponencial = -log(1.0f - ran) / f;
            int valor = ruidoExponencial;
            valor = std::max(0.0f, std::min(255.0f, valor));




                bitmap->Canvas->Pixels[x][y] = RGB(valor,valor,valor) ;



        }
    }
}





void __fastcall TExponencial::OKClick(TObject *Sender)
{
        int valor;
        valor = Valor->Text.ToInt();

         TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
        if(Child!=NULL){
                Graphics::TBitmap *BitmapRuido=new Graphics::TBitmap();
                BitmapRuido->Assign(Child->ActiveBitmap());

              AplicarRuido(BitmapRuido, valor);

         String name=ExtractFilePath(Child->FileName)+"\Ruido Exponencial ="+ExtractFileName(Child->FileName);
       // MainForm->CreateMDIChild(name,BitmapSuavizado);
         MainForm->CreateMDIChild(name,BitmapRuido);
         BitmapRuido->FreeImage();
         delete BitmapRuido;

         }
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TExponencial::CancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

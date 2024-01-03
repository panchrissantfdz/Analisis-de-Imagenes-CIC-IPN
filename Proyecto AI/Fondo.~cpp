//---------------------------------------------------------------------------

#include <vcl.h>
#include <jpeg.hpp>
#include <tchar.h>
#pragma hdrstop
#pragma argsused

#include "Fondo.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBackground *Background;
//---------------------------------------------------------------------------
__fastcall TBackground::TBackground(TComponent* Owner)
        : TForm(Owner)
{
}

void Pseudocolor(Graphics::TBitmap  *Original, Graphics::TBitmap  *Copia)  {

        

        int ancho = Original->Width;
        int alto = Original->Height;
        int umbral = 128;

        int umbralAnterior;
        do {
                umbralAnterior = umbral;
                int sumAbove = 0;
                int countAbove = 0;
                int sumBelow = 0;
                int countBelow = 0;

                for (int y = 0; y < alto; y++) {
                        for (int x = 0; x < ancho; x++) {
                                TColor pixelColor = Copia->Canvas->Pixels[x][y];
                                int intensidad = GetRValue(pixelColor);

                                if (intensidad > umbral) {
                                        sumAbove += intensidad;
                                        countAbove++;
                                } else {
                                        sumBelow += intensidad;
                                        countBelow++;
                                }
                        }
                }

        // Calcular las medias
                int mediaAbove = (countAbove > 0) ? sumAbove / countAbove : 0;
                int mediaBelow = (countBelow > 0) ? sumBelow / countBelow : 0;
                umbral = (mediaAbove + mediaBelow) / 2;

        } while (abs(umbral - umbralAnterior) > 1);

        for (int y = 0; y < alto; y++) {
                for (int x = 0; x < ancho; x++) {
                        TColor pixelColor = Copia->Canvas->Pixels[x][y];
                        int intensidad = GetRValue(pixelColor);

                        // Binarizar según el umbral final
                        if (intensidad > umbral) {
                                Copia->Canvas->Pixels[x][y] = clWhite;  // Píxel blanco (por encima del umbral)
                        } else {
                                Copia->Canvas->Pixels[x][y] = clBlack;  // Píxel negro (por debajo del umbral)
                        }
                }
        }

        TColor colorFondo = RGB(0, 255, 0); // Verde puro

        for (int y = 0; y < alto; y++) {
                for (int x = 0; x < ancho; x++) {
                        TColor pixelColor = Copia->Canvas->Pixels[x][y];

                        // Verificar si el píxel pertenece al fondo (píxel negro en la imagen binaria)
                        if (pixelColor == clBlack) {
                                // Aplicar el pseudocolor verde al fondo
                                Original->Canvas->Pixels[x][y] = colorFondo;
                        }
                }
        }



}

//---------------------------------------------------------------------------
void __fastcall TBackground::OKClick(TObject *Sender)
{
        
         TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;       //llama la imagen
        if(Child!=NULL){
                Graphics::TBitmap *BitmapRuido=new Graphics::TBitmap();    // crea un mapa de bits (BitmapRuido) de la imagen
                Graphics::TBitmap *Copia=new Graphics::TBitmap();
                BitmapRuido->Assign(Child->ActiveBitmap());                 //crea copia del mapa de bits
                Copia->Assign(Child->ActiveBitmap()); 

             Pseudocolor(BitmapRuido, Copia);                //llamando funcion

         String name=ExtractFilePath(Child->FileName)+"\Pseudocolor ="+ExtractFileName(Child->FileName);   // creando nombre del proceso
       // MainForm->CreateMDIChild(name,BitmapSuavizado);
         MainForm->CreateMDIChild(name,BitmapRuido);               //Crea una nueva imagen de la copia y con su nombre del proceso
         BitmapRuido->FreeImage();                     //vacia la variable BitmapEuido
         delete BitmapRuido;                     //libera memoria

         }

        Close();

}
//---------------------------------------------------------------------------


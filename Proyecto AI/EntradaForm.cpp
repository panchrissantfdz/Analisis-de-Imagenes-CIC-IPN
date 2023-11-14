//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EntradaForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEntrada *FormEntrada;
//---------------------------------------------------------------------------
__fastcall TFormEntrada::TFormEntrada(TComponent* Owner)
        : TForm(Owner)
{
   // Width = ImageEntrada->Picture->Bitmap->Width;
   // Height = ImageEntrada->Picture->Bitmap->Height;
    Top = Screen->Height/2-(ClientHeight/2);
    Left = Screen->Width/2-(ClientWidth/2);

}
//---------------------------------------------------------------------------
void __fastcall TFormEntrada::FormShow(TObject *Sender)
{
AnimateWindow(Handle, 1000, AW_BLEND | AW_ACTIVATE);        
}
//---------------------------------------------------------------------------
void __fastcall TFormEntrada::WmEraseBkgnd(TWMEraseBkgnd& msg)
{
    BitBlt(msg.DC, 0, 0, ClientWidth, ClientHeight, ImageEntrada->Canvas->Handle, 0, 0, SRCCOPY);
}
//---------------------------------------------------------------------------
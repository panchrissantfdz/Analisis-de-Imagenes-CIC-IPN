//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Normalizar.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNormalizeForm *NormalizeForm;
//---------------------------------------------------------------------------
__fastcall TNormalizeForm::TNormalizeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNormalizeForm::BitBtnOKClick(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
float dimension=StrToFloat(GetNormalize->Text);
if(dimension>0){
Graphics::TBitmap *BitmapZoom=new Graphics::TBitmap();
BitmapZoom->Assign(Child->ActiveBitmap());
float act;
if(BitmapZoom->Width>BitmapZoom->Height)
  act=BitmapZoom->Width;
else
  act=BitmapZoom->Height;
float fact=dimension/act;
try
{
MainForm->Pdi->InterpolacionBilineal(BitmapZoom,Child->Image->Picture->Bitmap,fact,fact);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
String name=ExtractFilePath(Child->FileName)+"\Normalized "+dimension+"="+ExtractFileName(Child->FileName);
MainForm->CreateMDIChild(name,BitmapZoom);
TMDIChild *Child2 =(TMDIChild *)MainForm->ActiveMDIChild;
String proceso=": Normalized";
MainForm->AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Scale factor: ")+dimension);
Child2->ImageClick(Child2);
}
catch(...)
{
 ShowMessage("Insufficient space to process this command");
}
BitmapZoom->FreeImage();
delete BitmapZoom;
}
else{
MessageDlg("Write a other than number zero",mtInformation, TMsgDlgButtons() << mbOK, 0);
}
}
}
//---------------------------------------------------------------------------


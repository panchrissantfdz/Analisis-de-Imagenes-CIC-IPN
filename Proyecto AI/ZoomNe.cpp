//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ZoomNe.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TZoomN *ZoomN;
//---------------------------------------------------------------------------
__fastcall TZoomN::TZoomN(TComponent* Owner)
        : TForm(Owner)
{
}
//-----------------------------------------------------------------------------
void __fastcall TZoomN::BitBtn1Click(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
float dimension=StrToFloat(Edit1->Text);
if(dimension>0){
Graphics::TBitmap *BitmapZoom=new Graphics::TBitmap();
BitmapZoom->Assign(Child->ActiveBitmap());
try
{
MainForm->Pdi->NearestNeighborZoom(BitmapZoom,Child->Image->Picture->Bitmap,dimension,dimension);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
String name=ExtractFilePath(Child->FileName)+"\Nearest Neighbor Zoom "+dimension+"="+ExtractFileName(Child->FileName);
MainForm->CreateMDIChild(name,BitmapZoom);
TMDIChild *Child2 =(TMDIChild *)MainForm->ActiveMDIChild;
String proceso=": Nearest Neighbor Zoom";
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





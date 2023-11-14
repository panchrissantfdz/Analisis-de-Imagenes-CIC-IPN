/*
try{

}
catch ( ... )
   {
   ShowMessage("Is not a valid integer value");
   }
/*
String name=ExtractFilePath(Child->FileName)+"\Negative="+ExtractFileName(Child->FileName);
*/
/*
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
Bitmap->Assign(Child->ActiveBitmap());
*/
/*
Screen->Cursor = crHourGlass;
Screen->Cursor = crDefault;
*/
/*
Bitmap->FreeImage();
delete Bitmap;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
*/
/*  Main
String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
CreateMDIChild(name,pBitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": Proceso";
AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
*/
/* otro formulario
String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
MainForm->CreateMDIChild(name ,pBitmap);
TMDIChild *Child2 =(TMDIChild *)MainForm->ActiveMDIChild;
String proceso=": Proceso";
MainForm->AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "EntradaForm.h"
//---------------------------------------------------------------------------
USEFORM("AboutWin.cpp", AboutBox);
USEFORM("HistogramWin.cpp", HistogramForm);
USEFORM("Main.cpp", MainForm);
USEFORM("Operaciones_Log.cpp", OperacionesLog);
USEFORM("Normalizar.cpp", NormalizeForm);
USEFORM("Resolution.cpp", FrmRes);
USEFORM("Resolution1.cpp", FrmRes1);
USEFORM("Zoom.cpp", Bilineal);
USEFORM("ZoomNe.cpp", ZoomN);
USEFORM("operaciones.cpp", FormArithmeticOperations);
USEFORM("ElemStrucBi.cpp", FSEB);
USEFORM("ZoomInForm.cpp", FormZoom);
USEFORM("ErosionGeodesicForm.cpp", FormErosionGeodesic);
USEFORM("GeodesicDilationForm.cpp", FormGeodesicDilation);
USEFORM("ReconstructionErosionForm.cpp", FormReconstructionErosion);
USEFORM("ReconstructionDilationForm.cpp", FormReconstructionDilation);
USEFORM("EntradaForm.cpp", FormEntrada);
USEFORM("ChildWin.cpp", MDIChild);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 FormEntrada = new TFormEntrada(static_cast<void *>(NULL));
                 FormEntrada->Show();
                 Application->Title = "IPSS";
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TOperacionesLog), &OperacionesLog);
                 Application->CreateForm(__classid(THistogramForm), &HistogramForm);
                 Application->CreateForm(__classid(TNormalizeForm), &NormalizeForm);
                 Application->CreateForm(__classid(TFrmRes), &FrmRes);
                 Application->CreateForm(__classid(TFrmRes1), &FrmRes1);
                 Application->CreateForm(__classid(TBilineal), &Bilineal);
                 Application->CreateForm(__classid(TZoomN), &ZoomN);
                 Application->CreateForm(__classid(TFormArithmeticOperations), &FormArithmeticOperations);
                 Application->CreateForm(__classid(TFSEB), &FSEB);
                 Application->CreateForm(__classid(TFormZoom), &FormZoom);
                 Application->CreateForm(__classid(TFormErosionGeodesic), &FormErosionGeodesic);
                 Application->CreateForm(__classid(TFormGeodesicDilation), &FormGeodesicDilation);
                 Application->CreateForm(__classid(TFormReconstructionErosion), &FormReconstructionErosion);
                 Application->CreateForm(__classid(TFormReconstructionDilation), &FormReconstructionDilation);
                 Application->Run();
                 }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

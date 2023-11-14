//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReconstructionDilationForm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReconstructionDilation *FormReconstructionDilation;
//---------------------------------------------------------------------------
__fastcall TFormReconstructionDilation::TFormReconstructionDilation(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormReconstructionDilation::FormClose(TObject *Sender,
      TCloseAction &Action)
{
ImageMarker->Picture->Bitmap->Assign(NULL);
ImageMask->Picture->Bitmap->Assign(NULL);        
}
//---------------------------------------------------------------------------
void __fastcall TFormReconstructionDilation::BitBtnMarkerClick(
      TObject *Sender)
{
TMDIChild *Child=(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
int anchoOriginal=Child->Image->Picture->Bitmap->Width;
int altoOriginal=Child->Image->Picture->Bitmap->Height;
int TopImageForm=16;
int LeftImageForm=16;
int AnchoAltoImageForm=105;
ImageMarker->Picture->Bitmap->Assign(Child->Image->Picture->Bitmap);
ImageMarkerName=(Child->FileName);
MainForm->Pdi->EscalarImagen(ImageMarker,anchoOriginal,altoOriginal,TopImageForm,LeftImageForm,AnchoAltoImageForm,Bevel1);
}
else{ImageMarker->Picture->Bitmap->Assign(NULL);
Refresh();
}          
}
//---------------------------------------------------------------------------
void __fastcall TFormReconstructionDilation::BitBtnMaskClick(
      TObject *Sender)
{
TMDIChild *Child=(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
int anchoOriginal=Child->Image->Picture->Bitmap->Width;
int altoOriginal=Child->Image->Picture->Bitmap->Height;
int TopImageForm=16;
int LeftImageForm=16;
int AnchoAltoImageForm=105;
ImageMask->Picture->Bitmap->Assign(Child->Image->Picture->Bitmap);
ImageMaskName=(Child->FileName);
MainForm->Pdi->EscalarImagen(ImageMask,anchoOriginal,altoOriginal,TopImageForm,LeftImageForm,AnchoAltoImageForm,Bevel2);
}
else{ImageMask->Picture->Bitmap->Assign(NULL);
Refresh();
}          
}
//---------------------------------------------------------------------------
void __fastcall TFormReconstructionDilation::BitBtnOKClick(TObject *Sender)
{
if(!(ImageMarker->Picture->Bitmap->Empty) && !(ImageMask->Picture->Bitmap->Empty)){
if(ImageMarker->Picture->Bitmap->Width==ImageMask->Picture->Bitmap->Width &&
        ImageMarker->Picture->Bitmap->Height==ImageMask->Picture->Bitmap->Height){
Screen->Cursor=crHourGlass;
Graphics::TBitmap *Marcadora=new Graphics::TBitmap();
Graphics::TBitmap *Mascara=new Graphics::TBitmap();
Graphics::TBitmap *MascaraActual=new Graphics::TBitmap();
Marcadora->Assign(ImageMarker->Picture->Bitmap);
MascaraActual->Assign(ImageMask->Picture->Bitmap);
MainForm->Pdi->PromedioOIntensidadImagen(Marcadora);
bool noestabilidad=true;
int iteraciones=0;
while(noestabilidad){
Mascara->Assign(FSEB->Morpho->dilateG(MascaraActual,FSEB->EE,FSEB->ox,FSEB->oy));
Mascara->Assign(FSEB->Morpho->dilRec(Mascara,Marcadora));
int value=MainForm->Pdi->Scan(MainForm->Pdi->Resta(MascaraActual,Mascara));
iteraciones++;
if(value!=0)
  noestabilidad=true;
else
  noestabilidad=false;
MascaraActual->Assign(Mascara);
}
String name="\\Reconstruction by dilation("+AnsiString(iteraciones)+" iterations)=("+ExtractFileName(ImageMarkerName)+")&("+ExtractFileName(ImageMaskName)+")";
MainForm->CreateMDIChild(name,MascaraActual);
Marcadora->FreeImage();
delete Marcadora;
Mascara->FreeImage();
delete Mascara;
MascaraActual->FreeImage();
delete MascaraActual;
Screen->Cursor=crDefault;
}
else{ShowMessage("The images do not have the same size");}
}
}
//---------------------------------------------------------------------------

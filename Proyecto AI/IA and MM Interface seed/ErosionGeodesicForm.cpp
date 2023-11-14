//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ErosionGeodesicForm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormErosionGeodesic *FormErosionGeodesic;
//---------------------------------------------------------------------------
__fastcall TFormErosionGeodesic::TFormErosionGeodesic(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormErosionGeodesic::BitBtnMarkerClick(TObject *Sender)
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
void __fastcall TFormErosionGeodesic::BitBtnMaskClick(TObject *Sender)
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
void __fastcall TFormErosionGeodesic::FormClose(TObject *Sender,
      TCloseAction &Action)
{
ImageMarker->Picture->Bitmap->Assign(NULL);
ImageMask->Picture->Bitmap->Assign(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TFormErosionGeodesic::BitBtnOKClick(TObject *Sender)
{
if(!(ImageMarker->Picture->Bitmap->Empty) && !(ImageMask->Picture->Bitmap->Empty)){
if(ImageMarker->Picture->Bitmap->Width==ImageMask->Picture->Bitmap->Width &&
        ImageMarker->Picture->Bitmap->Height==ImageMask->Picture->Bitmap->Height){
Graphics::TBitmap *Marcadora=new Graphics::TBitmap();
Graphics::TBitmap *Mascara=new Graphics::TBitmap();
Marcadora->Assign(ImageMarker->Picture->Bitmap);
Mascara->Assign(ImageMask->Picture->Bitmap);
MainForm->Pdi->PromedioOIntensidadImagen(Marcadora);
Mascara=FSEB->Morpho->erodeG(Mascara,FSEB->EE,FSEB->ox,FSEB->oy);
Marcadora=FSEB->Morpho->eroGeo(Marcadora,Mascara);
String name="\\Geodesic erosion=("+ExtractFileName(ImageMarkerName)+")&("+ExtractFileName(ImageMaskName)+")";
MainForm->CreateMDIChild(name,Marcadora);
Marcadora->FreeImage();
delete Marcadora;
Mascara->FreeImage();
delete Mascara;
}
else{ShowMessage("The images do not have the same size");}
}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "operaciones.h"
#include "Main.h"
#include "ChildWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormArithmeticOperations *FormArithmeticOperations;
//---------------------------------------------------------------------------
__fastcall TFormArithmeticOperations::TFormArithmeticOperations(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormArithmeticOperations::ButtonAddClick(TObject *Sender)
{
if(!(Image1->Picture->Bitmap->Empty) && !(Image2->Picture->Bitmap->Empty)){
Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
Graphics::TBitmap *Bitmap2=new Graphics::TBitmap();
Graphics::TBitmap *BitmapOpe=new Graphics::TBitmap();
Bitmap1->Assign(Image1->Picture->Bitmap);
Bitmap2->Assign(Image2->Picture->Bitmap);
int ancho, alto;
String opcion;
if(!(Bitmap1->Width==Bitmap2->Width && Bitmap1->Height==Bitmap2->Height)){
if(CheckBoxFitSizeImage->Checked==true){
        if(RadioButtonImage1->Checked==true){
                ancho=Bitmap1->Width;
                alto=Bitmap1->Height;
                MainForm->Pdi->IgualarImagen(Bitmap2,Image2->Picture->Bitmap,ancho,alto);
        }
        else if(RadioButtonImage2->Checked==true){
                ancho=Bitmap2->Width;
                alto=Bitmap2->Height;
                MainForm->Pdi->IgualarImagen(Bitmap1,Image1->Picture->Bitmap,ancho,alto);
        }
}
else if(CheckBoxFitSizeImage->Checked==false){
        ancho=Bitmap1->Width;
        alto=Bitmap1->Height;
        if(ancho<Bitmap2->Width){ancho=Bitmap2->Width;}
        if(alto<Bitmap2->Height){alto=Bitmap2->Height;}
        Bitmap1->Width=ancho;
        Bitmap1->Height=alto;
        Bitmap2->Width=ancho;
        Bitmap2->Height=alto;
}
}
else{
ancho=Bitmap1->Width;
alto=Bitmap1->Height;
}
BitmapOpe->PixelFormat=pf24bit;
BitmapOpe->Width=ancho;
BitmapOpe->Height=alto;

if(RadioButtonLimited->Checked==true){
MainForm->Pdi->OperacionArtimetica('+','L',Bitmap1,Bitmap2,BitmapOpe);
opcion="Limited";
}
else if(RadioButtonScaled->Checked==true){
MainForm->Pdi->OperacionArtimetica('+','S',Bitmap1,Bitmap2,BitmapOpe);
opcion="Scaled";
}
else if(RadioButtonCyclic->Checked==true){
MainForm->Pdi->OperacionArtimetica('+','C',Bitmap1,Bitmap2,BitmapOpe);
opcion="Cyclic";
}
String name="\\Add=("+ExtractFileName(Image1Name)+")&("+ExtractFileName(Image2Name)+")";
MainForm->CreateMDIChild(name,BitmapOpe);
Bitmap1->FreeImage();
delete Bitmap1;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
}
//String name="\\Add "+opcion+"=("+ExtractFileName(MainForm->FileNameimg1)+")+("+ExtractFileName(MainForm->FileNameimg2)+")";
//MainForm->CreateMDIChild(name ,aux3);
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::ButtonSubtractClick(TObject *Sender)
{
if(!(Image1->Picture->Bitmap->Empty) && !(Image2->Picture->Bitmap->Empty)){
Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
Graphics::TBitmap *Bitmap2=new Graphics::TBitmap();
Graphics::TBitmap *BitmapOpe=new Graphics::TBitmap();
Bitmap1->Assign(Image1->Picture->Bitmap);
Bitmap2->Assign(Image2->Picture->Bitmap);
int ancho, alto;
String opcion;
if(!(Bitmap1->Width==Bitmap2->Width && Bitmap1->Height==Bitmap2->Height)){
if(CheckBoxFitSizeImage->Checked==true){
        if(RadioButtonImage1->Checked==true){
                ancho=Bitmap1->Width;
                alto=Bitmap1->Height;
                MainForm->Pdi->IgualarImagen(Bitmap2,Image2->Picture->Bitmap,ancho,alto);
        }
        else if(RadioButtonImage2->Checked==true){
                ancho=Bitmap2->Width;
                alto=Bitmap2->Height;
                MainForm->Pdi->IgualarImagen(Bitmap1,Image1->Picture->Bitmap,ancho,alto);
        }
}
else if(CheckBoxFitSizeImage->Checked==false){
        ancho=Bitmap1->Width;
        alto=Bitmap1->Height;
        if(ancho<Bitmap2->Width){ancho=Bitmap2->Width;}
        if(alto<Bitmap2->Height){alto=Bitmap2->Height;}
        Bitmap1->Width=ancho;
        Bitmap1->Height=alto;
        Bitmap2->Width=ancho;
        Bitmap2->Height=alto;
}
}
else{
ancho=Bitmap1->Width;
alto=Bitmap1->Height;
}
BitmapOpe->PixelFormat=pf24bit;
BitmapOpe->Width=ancho;
BitmapOpe->Height=alto;

if(RadioButtonLimited->Checked==true){
MainForm->Pdi->OperacionArtimetica('-','L',Bitmap1,Bitmap2,BitmapOpe);
opcion="Limited";
}
else if(RadioButtonScaled->Checked==true){
MainForm->Pdi->OperacionArtimetica('-','S',Bitmap1,Bitmap2,BitmapOpe);
opcion="Scaled";
}
else if(RadioButtonCyclic->Checked==true){
MainForm->Pdi->OperacionArtimetica('-','C',Bitmap1,Bitmap2,BitmapOpe);
opcion="Cyclic";
}
//String name="\\Subtract "+opcion+"=("+ExtractFileName(MainForm->FileNameimg1)+")+("+ExtractFileName(MainForm->FileNameimg2)+")";
String name="\\Subtract=("+ExtractFileName(Image1Name)+")&("+ExtractFileName(Image2Name)+")";
MainForm->CreateMDIChild(name,BitmapOpe);
String iguales="Both images are equal";
BYTE *POpe;
for(int i=0;i<BitmapOpe->Height;i++){
 POpe=(BYTE*)BitmapOpe->ScanLine[i];
 for(int j=0;j<BitmapOpe->Width;j++){
  if (POpe[j*3]!=0 || POpe[j*3+1]!=0 || POpe[j*3+2]!=0){
  iguales="Both images are different";
  break;
  }
 }
}
MessageBeep(0);
//Beep();
MainForm->StatusBar->Panels->Items[15]->Text =iguales;
Bitmap1->FreeImage();
delete Bitmap1;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
}
}
//---------------------------------------------------------------------------
void __fastcall TFormArithmeticOperations::ButtonDivisionClick(TObject *Sender)
{
if(!(Image1->Picture->Bitmap->Empty) && !(Image2->Picture->Bitmap->Empty)){
Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
Graphics::TBitmap *Bitmap2=new Graphics::TBitmap();
Graphics::TBitmap *BitmapOpe=new Graphics::TBitmap();
Bitmap1->Assign(Image1->Picture->Bitmap);
Bitmap2->Assign(Image2->Picture->Bitmap);
int ancho, alto;
String opcion;
if(!(Bitmap1->Width==Bitmap2->Width && Bitmap1->Height==Bitmap2->Height)){
if(CheckBoxFitSizeImage->Checked==true){
        if(RadioButtonImage1->Checked==true){
                ancho=Bitmap1->Width;
                alto=Bitmap1->Height;
                MainForm->Pdi->IgualarImagen(Bitmap2,Image2->Picture->Bitmap,ancho,alto);
        }
        else if(RadioButtonImage2->Checked==true){
                ancho=Bitmap2->Width;
                alto=Bitmap2->Height;
                MainForm->Pdi->IgualarImagen(Bitmap1,Image1->Picture->Bitmap,ancho,alto);
        }
}
else if(CheckBoxFitSizeImage->Checked==false){
        ancho=Bitmap1->Width;
        alto=Bitmap1->Height;
        if(ancho<Bitmap2->Width){ancho=Bitmap2->Width;}
        if(alto<Bitmap2->Height){alto=Bitmap2->Height;}
        Bitmap1->Width=ancho;
        Bitmap1->Height=alto;
        Bitmap2->Width=ancho;
        Bitmap2->Height=alto;
}
}
else{
ancho=Bitmap1->Width;
alto=Bitmap1->Height;
}
BitmapOpe->PixelFormat=pf24bit;
BitmapOpe->Width=ancho;
BitmapOpe->Height=alto;

if(RadioButtonLimited->Checked==true){
MainForm->Pdi->OperacionArtimetica('/','L',Bitmap1,Bitmap2,BitmapOpe);
opcion="Limited";
}
else if(RadioButtonScaled->Checked==true){
MainForm->Pdi->OperacionArtimetica('/','S',Bitmap1,Bitmap2,BitmapOpe);
opcion="Scaled";
}
else if(RadioButtonCyclic->Checked==true){
MainForm->Pdi->OperacionArtimetica('/','C',Bitmap1,Bitmap2,BitmapOpe);
opcion="Cyclic";
}
String name="\\Division=("+ExtractFileName(Image1Name)+")&("+ExtractFileName(Image2Name)+")";
MainForm->CreateMDIChild(name,BitmapOpe);
Bitmap1->FreeImage();
delete Bitmap1;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
}
//String name="\\Division "+opcion+"=("+ExtractFileName(MainForm->FileNameimg1)+")+("+ExtractFileName(MainForm->FileNameimg2)+")";
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::ButtonMultiplicationClick(TObject *Sender)
{
if(!(Image1->Picture->Bitmap->Empty) && !(Image2->Picture->Bitmap->Empty)){
Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
Graphics::TBitmap *Bitmap2=new Graphics::TBitmap();
Graphics::TBitmap *BitmapOpe=new Graphics::TBitmap();
Bitmap1->Assign(Image1->Picture->Bitmap);
Bitmap2->Assign(Image2->Picture->Bitmap);
int ancho, alto;
String opcion;
if(!(Bitmap1->Width==Bitmap2->Width && Bitmap1->Height==Bitmap2->Height)){
if(CheckBoxFitSizeImage->Checked==true){
        if(RadioButtonImage1->Checked==true){
                ancho=Bitmap1->Width;
                alto=Bitmap1->Height;
                MainForm->Pdi->IgualarImagen(Bitmap2,Image2->Picture->Bitmap,ancho,alto);
        }
        else if(RadioButtonImage2->Checked==true){
                ancho=Bitmap2->Width;
                alto=Bitmap2->Height;
                MainForm->Pdi->IgualarImagen(Bitmap1,Image1->Picture->Bitmap,ancho,alto);
        }
}
else if(CheckBoxFitSizeImage->Checked==false){
        ancho=Bitmap1->Width;
        alto=Bitmap1->Height;
        if(ancho<Bitmap2->Width){ancho=Bitmap2->Width;}
        if(alto<Bitmap2->Height){alto=Bitmap2->Height;}
        Bitmap1->Width=ancho;
        Bitmap1->Height=alto;
        Bitmap2->Width=ancho;
        Bitmap2->Height=alto;
}
}
else{
ancho=Bitmap1->Width;
alto=Bitmap1->Height;
}
BitmapOpe->PixelFormat=pf24bit;
BitmapOpe->Width=ancho;
BitmapOpe->Height=alto;

if(RadioButtonLimited->Checked==true){
MainForm->Pdi->OperacionArtimetica('*','L',Bitmap1,Bitmap2,BitmapOpe);
opcion="Limited";
}
else if(RadioButtonScaled->Checked==true){
MainForm->Pdi->OperacionArtimetica('*','S',Bitmap1,Bitmap2,BitmapOpe);
opcion="Scaled";
}
else if(RadioButtonCyclic->Checked==true){
MainForm->Pdi->OperacionArtimetica('*','C',Bitmap1,Bitmap2,BitmapOpe);
opcion="Cyclic";
}
String name="\\Multiplication=("+ExtractFileName(Image1Name)+")&("+ExtractFileName(Image2Name)+")";
MainForm->CreateMDIChild(name,BitmapOpe);
Bitmap1->FreeImage();
delete Bitmap1;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
}
//String name="\\Multiplication "+opcion+"=("+ExtractFileName(MainForm->FileNameimg1)+")+("+ExtractFileName(MainForm->FileNameimg2)+")";
}
//---------------------------------------------------------------------------
/* int TFormArithmeticOperations::maximo(char in[],int largo)
 {
 int k;
 int maximo=0;
 for(k=0;k<largo;k++)
 {
 if(in[k]>maximo){
 maximo=in[k];
 }
 }
 return maximo;
 }
*/
//----------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Image1->Picture->Bitmap->Assign(NULL);
Image2->Picture->Bitmap->Assign(NULL);
MainForm->StatusBar->Panels->Items[13]->Text ="";
}
//---------------------------------------------------------------------------


void __fastcall TFormArithmeticOperations::BitBtnI1Click(TObject *Sender)
{
TMDIChild *Child=(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
int anchoOriginal=Child->Image->Picture->Bitmap->Width;
int altoOriginal=Child->Image->Picture->Bitmap->Height;
int TopImageForm=16;
int LeftImageForm=16;
int AnchoAltoImageForm=105;
Image1->Picture->Bitmap->Assign(Child->Image->Picture->Bitmap);
Image1Name=(Child->FileName);
MainForm->Pdi->EscalarImagen(Image1,anchoOriginal,altoOriginal,TopImageForm,LeftImageForm,AnchoAltoImageForm,Bevel1);
}
else{Image1->Picture->Bitmap->Assign(NULL);
Refresh();
}        
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::BitBtnI2Click(TObject *Sender)
{
TMDIChild *Child=(TMDIChild *)MainForm->ActiveMDIChild;
if(Child!=NULL){
int anchoOriginal=Child->Image->Picture->Bitmap->Width;
int altoOriginal=Child->Image->Picture->Bitmap->Height;
int TopImageForm=16;
int LeftImageForm=16;
int AnchoAltoImageForm=105;
Image2->Picture->Bitmap->Assign(Child->Image->Picture->Bitmap);
Image2Name=(Child->FileName);
MainForm->Pdi->EscalarImagen(Image2,anchoOriginal,altoOriginal,TopImageForm,LeftImageForm,AnchoAltoImageForm,Bevel2);
}
else{Image2->Picture->Bitmap->Assign(NULL);
Refresh();
}        
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::FormCreate(TObject *Sender)
{
CheckBoxFitSizeImage->Checked=false;
RadioButtonImage1->Checked=true;
RadioButtonImage2->Checked=false;
RadioButtonImage1->Enabled=false;
RadioButtonImage2->Enabled=false;
BitBtnChooseColor->Enabled=false;
PanelColor->Enabled=false;        
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::CheckBoxFitSizeImageClick(TObject *Sender)
{
if(CheckBoxFitSizeImage->Checked==true){
RadioButtonImage1->Enabled=true;
RadioButtonImage2->Enabled=true;
}
else if(CheckBoxFitSizeImage->Checked==false){
RadioButtonImage1->Enabled=false;
RadioButtonImage2->Enabled=false;
}        
}
//---------------------------------------------------------------------------



void __fastcall TFormArithmeticOperations::ButtonSuperimposeClick(TObject *Sender)
{
if(!(Image1->Picture->Bitmap->Empty) && !(Image2->Picture->Bitmap->Empty)){
Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
Graphics::TBitmap *Bitmap2=new Graphics::TBitmap();
Graphics::TBitmap *BitmapOpe=new Graphics::TBitmap();
Bitmap1->Assign(Image1->Picture->Bitmap);
Bitmap2->Assign(Image2->Picture->Bitmap);
int ancho, alto;
if(!(Bitmap1->Width==Bitmap2->Width) && !(Bitmap1->Height==Bitmap2->Height)){
if(CheckBoxFitSizeImage->Checked==true){
        if(RadioButtonImage1->Checked==true){
                ancho=Bitmap1->Width;
                alto=Bitmap1->Height;
                MainForm->Pdi->IgualarImagen(Bitmap2,Image2->Picture->Bitmap,ancho,alto);
        }
        else if(RadioButtonImage2->Checked==true){
                ancho=Bitmap2->Width;
                alto=Bitmap2->Height;
                MainForm->Pdi->IgualarImagen(Bitmap1,Image1->Picture->Bitmap,ancho,alto);
        }
}
else if(CheckBoxFitSizeImage->Checked==false){
        ancho=Bitmap1->Width;
        alto=Bitmap1->Height;
        if(ancho<Bitmap2->Width){ancho=Bitmap2->Width;}
        if(alto<Bitmap2->Height){alto=Bitmap2->Height;}
}
}
else{
ancho=Bitmap1->Width;
alto=Bitmap1->Height;
}
BitmapOpe->PixelFormat=pf24bit;
BitmapOpe->Width=ancho;
BitmapOpe->Height=alto;

TColor ExceptPixel;
if(RadioButtonBlack->Checked==true){
ExceptPixel=clBlack;}
else if(RadioButtonWhite->Checked==true){
ExceptPixel=clWhite;}
else if(RadioButtonOtherColor->Checked==true){
ExceptPixel=PanelColor->Color;}
MainForm->Pdi->Superimpose(ExceptPixel,Bitmap1,Bitmap2,BitmapOpe);
String name="\\Superimpose=("+ExtractFileName(Image1Name)+")with("+ExtractFileName(Image2Name)+")";
MainForm->CreateMDIChild(name,BitmapOpe);
Bitmap1->FreeImage();
delete Bitmap1;
Bitmap2->FreeImage();
delete Bitmap2;
BitmapOpe->FreeImage();
delete BitmapOpe;
}        
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::BitBtnChooseColorClick(
      TObject *Sender)
{
ColorDialogSuperimpose->Execute();
PanelColor->Color=ColorDialogSuperimpose->Color;
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::RadioButtonOtherColorClick(
      TObject *Sender)
{
BitBtnChooseColor->Enabled=true;
PanelColor->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::RadioButtonBlackClick(
      TObject *Sender)
{
BitBtnChooseColor->Enabled=false;
PanelColor->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormArithmeticOperations::RadioButtonWhiteClick(
      TObject *Sender)
{
BitBtnChooseColor->Enabled=false;
PanelColor->Enabled=false;
}
//---------------------------------------------------------------------------



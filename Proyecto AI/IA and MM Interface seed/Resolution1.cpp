//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Resolution1.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRes1 *FrmRes1;
//---------------------------------------------------------------------------
__fastcall TFrmRes1::TFrmRes1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int TFrmRes1::ValidaFormato(Graphics::TBitmap *Bitmap)
{

     switch(Bitmap->PixelFormat){
            case 3: return 1;           //8 bits
                   // break;
            case 5: return 3;           //24 bits
                   // break;
            case 6: return 3;           //32 bits
                   // break;
            default: return 0;
                    // break;
        }
}
//---------------------------------------------------------------------------

void TFrmRes1::ResolucionColor(Graphics::TBitmap *Bitmap, int res)
{
//Por Segmentación
int LUT[3][256];
int sR=0;
int nivelGris;
int x=0;
int nseccion=1;
int seccion=256 / res;
int restante=256 - (seccion * res);
int seccionnivelgris=255 / (res-1);
int restantenivelgris=255 - (seccionnivelgris * res);
  for(int y=0; y<256; y++){
    if((sR >= (seccion*(nseccion-1))) && (sR<(seccion * nseccion))){
     nivelGris=seccionnivelgris*(nseccion-1);
     LUT[x][y]=nivelGris;
     LUT[x+1][y]=nivelGris;
     LUT[x+2][y]=nivelGris;
     sR++;}
  else if(sR>=(seccion*nseccion)){
   if(restante!=0){
     restante--;
     LUT[x][y]=nivelGris;
     LUT[x+1][y]=nivelGris;
     LUT[x+2][y]=nivelGris;
     }
   else{y--;}
   nseccion++;
   }
}
BYTE *LinePtr;
for(int y  = 0 ; y < Bitmap->Height ; y++ ){
     LinePtr = (BYTE *)Bitmap->ScanLine[y];
     for( int x = 0 ; x < Bitmap->Width ; x++){
              LinePtr[x*3] = (BYTE)LUT[2][(int)LinePtr[x*3]];
              LinePtr[x*3+1] = (BYTE)LUT[1][(int)LinePtr[x*3+1]];
              LinePtr[x*3+2] = (BYTE)LUT[0][(int)LinePtr[x*3+2]];
     }
}
}

//---------------------------------------------------------------------------//---------------------------------------------------------------------------


void __fastcall TFrmRes1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
if(UpDown1->Position>256){
UpDown1->Position=2;
}
if(UpDown1->Position<1){
UpDown1->Position=256;
}
}
//---------------------------------------------------------------------------
void __fastcall TFrmRes1::Edit1Change(TObject *Sender)
{
try{
if(StrToInt(Edit1->Text)>256){
Edit1->Text=2;
}
if(StrToInt(Edit1->Text)<1){
Edit1->Text=256;
}
switch(StrToInt(Edit1->Text))
        {
          case 2:RadioGroup1->ItemIndex = 0; break;
          case 4:RadioGroup1->ItemIndex = 1;break;
          case 8:RadioGroup1->ItemIndex = 2;break;
          case 16:RadioGroup1->ItemIndex = 3;break;
          case 32:RadioGroup1->ItemIndex = 4;break;
          case 64:RadioGroup1->ItemIndex = 5;break;
          case 128:RadioGroup1->ItemIndex = 6;break;
          case 256:RadioGroup1->ItemIndex = 7;break;
          default:RadioGroup1->ItemIndex = -1;break;
        }
}
catch ( ... )
   {
   ShowMessage("Is not a valid integer value");
   }
}
//---------------------------------------------------------------------------
void __fastcall TFrmRes1::RadioGroup1Click(TObject *Sender)
{
   switch(RadioGroup1->ItemIndex)
        {
          case 0:Edit1->Text=2;UpDown1->Position=2;RadioGroup1->ItemIndex = 0;break;
          case 1:Edit1->Text=4;UpDown1->Position=4;RadioGroup1->ItemIndex = 1;break;
          case 2:Edit1->Text=8;UpDown1->Position=8;RadioGroup1->ItemIndex = 2;break;
          case 3:Edit1->Text=16;UpDown1->Position=16;RadioGroup1->ItemIndex = 3;break;
          case 4:Edit1->Text=32;UpDown1->Position=32;RadioGroup1->ItemIndex = 4;break;
          case 5:Edit1->Text=64;UpDown1->Position=64;RadioGroup1->ItemIndex = 5;break;
          case 6:Edit1->Text=128;UpDown1->Position=128;RadioGroup1->ItemIndex = 6;break;
          case 7:Edit1->Text=256;UpDown1->Position=256;RadioGroup1->ItemIndex = 7;break;
          default:break;
        };
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes1::BitBtnOKClick(TObject *Sender)
{
TMDIChild *Uno=(TMDIChild*)MainForm->ActiveMDIChild;
Screen->Cursor = crHourGlass;
if(Uno!=NULL){
        Graphics::TBitmap *Original = new Graphics::TBitmap;
        Graphics::TBitmap *Bitmap = new Graphics::TBitmap;
        Original->Assign(Uno->ActiveBitmap());
        if(RadioButtonA->Checked==true){
        Bitmap->Assign(Original);
        MainForm->Pdi->PromedioOIntensidadImagen(Bitmap);
        ResolucionColor(Bitmap,StrToInt(Edit1->Text));
        String name=ExtractFilePath(Uno->FileName)+"\Level Resolution Averaged:"+Edit1->Text+"="+ExtractFileName(Uno->FileName);
        MainForm->CreateMDIChild(name ,Bitmap);
        }
        else if(RadioButtonW->Checked==true){
        Bitmap->Assign(Original);
        MainForm->Pdi->GrayScaleWeighted(Bitmap);
        ResolucionColor(Bitmap,StrToInt(Edit1->Text));
        String name=ExtractFilePath(Uno->FileName)+"\Level Resolution Weighted:"+Edit1->Text+"="+ExtractFileName(Uno->FileName);
        MainForm->CreateMDIChild(name ,Bitmap);
        }
        else if(RadioButtonRGBG->Checked==true){
         if(CheckBoxR->Checked==true){
         Bitmap->Assign(Original);
         MainForm->Pdi->CanalRojoGris(Bitmap);
         ResolucionColor(Bitmap,StrToInt(Edit1->Text));
         String name=ExtractFilePath(Uno->FileName)+"\Level Resolution Red:"+Edit1->Text+"="+ExtractFileName(Uno->FileName);
         MainForm->CreateMDIChild(name ,Bitmap);
         }
         if(CheckBoxG->Checked==true){
         Bitmap->Assign(Original);
         MainForm->Pdi->CanalVerdeGris(Bitmap);
         ResolucionColor(Bitmap,StrToInt(Edit1->Text));
         String name=ExtractFilePath(Uno->FileName)+"\Level Resolution Green:"+Edit1->Text+"="+ExtractFileName(Uno->FileName);
         MainForm->CreateMDIChild(name ,Bitmap);
         }
         if(CheckBoxB->Checked==true){
         Bitmap->Assign(Original);
         MainForm->Pdi->CanalAzulGris(Bitmap);
         ResolucionColor(Bitmap,StrToInt(Edit1->Text));
         String name=ExtractFilePath(Uno->FileName)+"\Level Resolution Blue:"+Edit1->Text+"="+ExtractFileName(Uno->FileName);
         MainForm->CreateMDIChild(name ,Bitmap);
         }
        }
    Bitmap->FreeImage();
    delete Bitmap;
    Original->FreeImage();
    delete Original;
}
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes1::RadioButtonRGBGClick(TObject *Sender)
{
CheckBoxR->Enabled=true;
CheckBoxG->Enabled=true;
CheckBoxB->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes1::RadioButtonWClick(TObject *Sender)
{
CheckBoxR->Enabled=false;
CheckBoxG->Enabled=false;
CheckBoxB->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes1::RadioButtonAClick(TObject *Sender)
{
CheckBoxR->Enabled=false;
CheckBoxG->Enabled=false;
CheckBoxB->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes1::FormCreate(TObject *Sender)
{
CheckBoxR->Enabled=false;
CheckBoxG->Enabled=false;
CheckBoxB->Enabled=false;
}
//---------------------------------------------------------------------------




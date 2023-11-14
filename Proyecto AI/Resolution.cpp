//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Resolution.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRes *FrmRes;
//---------------------------------------------------------------------------
__fastcall TFrmRes::TFrmRes(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmRes::ResolucionEspacial(Graphics::TBitmap *Bitmap, int res)
{
  int x, y;
  BYTE *LinePtr1, *LinePtr2;
  BYTE r,g,b;

  for(y = 0 ; y < Bitmap->Height ; y++){
    if( y%res == 0 ) LinePtr1 = (BYTE *)Bitmap->ScanLine[y];
    LinePtr2 = (BYTE *)Bitmap->ScanLine[y];
    for(x = 0 ; x < Bitmap->Width ; x++ ){
      if( x%res == 0 ){
         b = LinePtr1[3*x];
         g = LinePtr1[3*x+1];
         r = LinePtr1[3*x+2];
         LinePtr2[3*x] = b;
         LinePtr2[3*x+1] = g;
         LinePtr2[3*x+2] = r;
      }
      else{
         LinePtr2[3*x] = b;
         LinePtr2[3*x+1] = g;
         LinePtr2[3*x+2] = r;
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
if(UpDown1->Position>128){
UpDown1->Position=1;
}
if(UpDown1->Position<1){
UpDown1->Position=128;
}
}
//---------------------------------------------------------------------------
void __fastcall TFrmRes::Edit1Change(TObject *Sender)
{
try{
if(StrToInt(Edit1->Text)>128){
Edit1->Text=1;
}
if(StrToInt(Edit1->Text)<1){
Edit1->Text=128;
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
          default:RadioGroup1->ItemIndex = -1;break;
        }
}
catch ( ... )
   {
   ShowMessage("Is not a valid integer value");
   }
}
//---------------------------------------------------------------------------
void __fastcall TFrmRes::RadioGroup1Click(TObject *Sender)
{
   switch(RadioGroup1->ItemIndex)
        {
          case 0:UpDown1->Position=2; RadioGroup1->ItemIndex = 0; break;
          case 1:UpDown1->Position=4;RadioGroup1->ItemIndex = 1;break;
          case 2:UpDown1->Position=8;RadioGroup1->ItemIndex = 2;break;
          case 3:UpDown1->Position=16;RadioGroup1->ItemIndex = 3;break;
          case 4:UpDown1->Position=32;RadioGroup1->ItemIndex = 4;break;
          case 5:UpDown1->Position=64;RadioGroup1->ItemIndex = 5;break;
          case 6:UpDown1->Position=128;RadioGroup1->ItemIndex = 6;break;
          default:break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRes::BitBtnOKClick(TObject *Sender)
{
 TMDIChild *Uno=(TMDIChild*)MainForm->ActiveMDIChild;
 Screen->Cursor = crHourGlass;
 if(Uno!=NULL){
     Graphics::TBitmap *Bitmap = new Graphics::TBitmap;
     Bitmap->Assign(Uno->ActiveBitmap());
     ResolucionEspacial(Bitmap,StrToInt(Edit1->Text));
     //tipo="Space Resolution";
      String name=ExtractFilePath(Uno->FileName)+"\Spatial Resolution "+Edit1->Text+"="+ExtractFileName(Uno->FileName);
     MainForm->CreateMDIChild(name ,Bitmap);
  }
 Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------



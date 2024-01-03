//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#pragma hdrstop
#include "AboutWin.h"
#include "Main.h"
#include "HistogramWin.h"
#include "Operaciones_Log.h"
#include "Normalizar.h"
#include "Zoom.h"
#include "ZoomNe.h"
#include "BicubicForm.h"
#include "Resolution.h"
#include "Resolution1.h"
#include "operaciones.h"
#include "Zoom.h"
#include "ElemStrucBi.h"
#include "dir.h"
#include "ZoomInForm.h"
#include "EntradaForm.h"
#include "ErosionGeodesicForm.h"
#include "GeodesicDilationForm.h"
#include "ReconstructionErosionForm.h"
#include "ReconstructionDilationForm.h"
#include "ChildWin.h"
#include "MedialAxis.h"
#include "Ruido.h"
#include "SalyPim.h"
#include "Exp.h"
#include <jpeg.hpp>
#include "Fondo.h"





//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
int nopen,reopen=0;
char *ventananombre;
char *sal;



//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
TransparentColorA=(TColor)RGB(0,0,0);
TransparentColorB=(TColor)RGB(0,0,0);
TransparentRango="Black";
pms = new TMemoryStream();
ImageForPage=6;
venthM = 41;
venthm = 11;

}
//---------------------------------------------------------------------------
void obtennombre(String x){
int i;
ventananombre=x.c_str();
for(i=x.Length();ventananombre[i]!='\\';i--);
{sal=&ventananombre[i+1];}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MHAboutClick(TObject *Sender)
{
AboutBox= new TAboutBox(Application);
AboutBox->ShowModal();
delete AboutBox;
}
//---------------------------------------------------------------------------
// FUNCION QUE CARGA UNA IMAGEN EN UN MDIChild
TMDIChild* TMainForm::CreateMDIChild(String Name,Graphics::TBitmap *pBitmap)
{
int x;
TMDIChild *Child;
Graphics::TBitmap  *Bitmap = new Graphics::TBitmap();
if(pBitmap!=NULL){//Carga Child con una imagen nueva resultado de un proceso
 Child = new TMDIChild(Application);
 obtennombre(Name);
 Child->Caption = sal;//sal+String("  ")+String(tipo);
 Child->FileName = Name;
 TMenuItem *NewItem = new TMenuItem(MFReopen);
 NewItem->Tag = 0;
 NewItem->Caption = Name;
 if(reopen==1){
  NewItem->OnClick=ReopenFile;
  MFReopen->Insert(0,NewItem);
  nopen++;                                          
  reopen=0;
  }
 //                pBitmap->PixelFormat=pf24bit;
 Child->cImage(pBitmap);
 //---------------------------------------------------------------------------
 Child->Image->Height = Child->Image->Picture->Bitmap->Height;
 Child->Image->Width = Child->Image->Picture->Bitmap->Width;
 Child->ClientHeight = Child->Image->Picture->Bitmap->Height;
 Child->ClientWidth = Child->Image->Picture->Bitmap->Width;
 //---------------------------------------------------------------------------
}
else{//Carga Child con una imagen de una archivo existente
 if (FileExists(Name)){
  if((ExtractFileExt(Name)==".bmp")||(ExtractFileExt(Name)==".BMP")||
     (ExtractFileExt(Name)==".jpg")||(ExtractFileExt(Name)==".JPG")||
     (ExtractFileExt(Name)==".jpeg")||(ExtractFileExt(Name)==".JPEG")){
   Child = new TMDIChild(Application);
   Child->NombreComando=sal;
   Child->ConteoProcesos=0;
   Child->ReportProcessedImageChild->SelAttributes->Style=
   Child->ReportProcessedImageChild->SelAttributes->Style << fsBold;
   Child->ReportProcessedImageChild->SelAttributes->Size=12;
   Child->ReportProcessedImageChild->Lines->Add("Report of the analysis sequence");
   Child->ReportProcessedImageChild->Lines->Add("");
   Child->ReportProcessedImageChild->SelAttributes->Style=
   Child->ReportProcessedImageChild->SelAttributes->Style << fsBold;
   Child->ReportProcessedImageChild->Lines->Add(AnsiString("Image name: ")+sal);
   Child->Caption =  sal;//+String("  ")+String(tipo);
   Child->FileName = Name;
   //obtennombre(Name);
   TMenuItem *NewItem = new TMenuItem(MFReopen); // create the new item
   NewItem->Tag = 0;
   NewItem->Caption = Name;
   if(reopen==1){
    NewItem->OnClick=ReopenFile;
    MFReopen->Insert(0,NewItem);
    nopen++;
    reopen=0;
    }
    // Abre el Archivo *.jpg o *.jpeg
   if((ExtractFileExt(Name)==".jpg")||(ExtractFileExt(Name)==".jpeg")||(ExtractFileExt(Name)==".JPG")){
    TJPEGImage *jp = new TJPEGImage();
    jp->LoadFromFile(Name);
    Bitmap->Assign(jp);
    Child->PixelFormatDepthColor=Bitmap->PixelFormat;
    Bitmap->PixelFormat=pf24bit;
    Child->cImage(Bitmap);
    }
    else{
    // Abre *.bmp
     Bitmap->LoadFromFile(Name);
     Child->PixelFormatDepthColor=Bitmap->PixelFormat;
     Bitmap->PixelFormat=pf24bit;
     Child->cImage(Bitmap);}
    //---------------------------------------------------------------------------
    Child->Image->Height = Child->Image->Picture->Bitmap->Height;
    Child->Image->Width = Child->Image->Picture->Bitmap->Width;
    Child->ClientHeight = Child->Image->Picture->Bitmap->Height;
    Child->ClientWidth = Child->Image->Picture->Bitmap->Width;
    //---------------------------------------------------------------------------
    }
  else
   MessageDlg("Error : Images invalidate",mtError,TMsgDlgButtons() << mbOK,0);
 }// Si no Existe el Archivo
 else{
  if(Name!=("NONAME" + IntToStr(MDIChildCount + 1))){
   MessageDlg("File not Found: "+Name,mtWarning,TMsgDlgButtons() << mbOK,0);
    return 0;}
  }
}
Child->Image->Hint=Child->Caption;
StatusBar->Panels->Items[11]->Text = Child->Tipo;
Child->dibujo = Child->Image->Picture;
Child->ImageClick(this);
return Child;
}
//---------------------------------------------------------------------------

// Funcion que Guarda los archivos en diferentes formatos
void TMainForm::SaveFile(String name)
{
 TJPEGImage *jp = new TJPEGImage();
 TMDIChild *Child;
 Graphics::TBitmap *Bitmap;

 Child=(TMDIChild *)ActiveMDIChild;

  if((ExtractFileExt(name)==".jpg")||(ExtractFileExt(name)==".jpeg"))
     {

          try
          {
                  jp->Assign(Child->ActiveBitmap());
                  jp->SaveToFile(name);
          }
          __finally
          {
            delete jp;
          }
     }
  else
  if(ExtractFileExt(name)==".bmp")
  {
   Bitmap = new Graphics::TBitmap();
   try{
   Bitmap->Assign(Child->ActiveBitmap());
   Bitmap->SaveToFile(name);
   }
    __finally
     {
       delete Bitmap;
     }

  }
  else
   MessageDlg("Error : Non valid image",mtError,TMsgDlgButtons() << mbOK,0);

}

//---------------------------------------------------------------------------



void __fastcall TMainForm::FileOpenExecute(TObject *Sender)
{
 TOpenPictureDialog *OpenDialog = new TOpenPictureDialog(this);
 OpenDialog->InitialDir="Imágenes de estudio";
   OpenDialog->Filter = "All (*.bmp;*.jpg;*.jpeg)|*.bmp;*.jpg;*.jpeg|Bitmaps (*.bmp)| *.bmp|JPEG Image File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg";
    OpenDialog->Options.Clear();
    OpenDialog->Options << ofAllowMultiSelect << ofFileMustExist << ofNoDereferenceLinks;
if (OpenDialog->Execute())
{
reopen=1;
//MessageDlg(OpenDialog->FileName,mtError,TMsgDlgButtons() << mbOK,0);
obtennombre(OpenDialog->FileName);
CreateMDIChild(OpenDialog->FileName,NULL);
/*MEdit->Enabled = true;
MView->Enabled=true;
MColor->Enabled=true;
MImage->Enabled=true;
MTools->Enabled=true;
MMorphology->Enabled=true;
MWindow->Enabled=true;
ToolButtonSave->Enabled=true;
ToolButtonCloseAll->Enabled=true;
ToolButtonCut->Enabled=true;
ToolButtonCopy->Enabled=true;
ToolButtonCascade->Enabled=true;
ToolButtonHorizontally->Enabled=true;
ToolButtonVertically->Enabled=true;
ToolButtonHistogramView->Enabled=true;
ToolButtonPrint->Enabled=true;
ToolButtonSearchPixel->Enabled=true;
ToolButtonGlasses->Enabled=true;
ToolButtonSelection->Enabled=true;
ToolButtonArrow->Enabled=true; */

}
else{};
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FileExitExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FileCloseAllExecute(TObject *Sender)
{
for(int i = MDIChildCount-1; i >= 0; i--)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FileCloseAllUpdate(TObject *Sender)
{
if (MDIChildCount==0)
        {
        FileCloseAll->Enabled=false;
        }
else
        {
        FileCloseAll->Enabled=true;
        FileCloseNoActive->Enabled=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileSaveAsExecute(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
String aFileName = Child->FileName;
SaveDialog->FileName=aFileName;
if(SaveDialog->Execute())
        SaveFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
margenes.left = 2500;
margenes.top = 2500;
dirApplication=ExtractFilePath(Application->ExeName);
TIniFile *Ini;
int index;
String NameFiles[4];
TMenuItem *NewItem;

nopen=0;
if((Ini=new TIniFile(dirApplication+"IPST.ini"))!=NULL)
        //{try
        {
                NameFiles[0] =Ini->ReadString("Window", "File0", NameFiles[0]);
                NameFiles[1] =Ini->ReadString("Window", "File1", NameFiles[1]);
                NameFiles[2] =Ini->ReadString("Window", "File2", NameFiles[2]);
                NameFiles[3] =Ini->ReadString("Window", "File3", NameFiles[3]);
                if((NameFiles[0]=="")&&(NameFiles[1]=="")&&(NameFiles[2]=="")&&(NameFiles[3]==""))
                  {
                   NewItem= new TMenuItem(MFReopen); // create the new item
                   NewItem->Tag=0;
                   NewItem->Caption="Open New";
                   NewItem->OnClick=ReopenFile;
                   MFReopen->Insert(0,NewItem);// add it to the Popupmenu
                  }
                else
                { for(index=0; index<4; index++)
                  {
                   if(NameFiles[index]!="")
                    {
                     NewItem= new TMenuItem(MFReopen); // create the new item
                     NewItem->Tag=0;
                     NewItem->AutoHotkeys=maManual;
                     NewItem->Caption=NameFiles[index];
                     NewItem->OnClick=ReopenFile;
                     MFReopen->Insert(index,NewItem);// add it to the Popupmenu
                     nopen++;
                    }
                  }
                }
         //}
        /* catch(EFilerError *e)
         {
         ShowMessage(e->Message);
         }*/

         Ini->FreeInstance();
        }
TClipboard* Clip = new TClipboard();
MFile->Enabled=true;
MView->Enabled=false;
MColor->Enabled=false;
MImage->Enabled=false;
MTools->Enabled=false;
MMorphology->Enabled=false;
MHelp->Enabled=true;
MWindow->Enabled=false;
ToolButtonSave->Enabled=false;
ToolButtonCloseAll->Enabled=false;


ToolButtonCascade->Enabled=false;
ToolButtonHorizontally->Enabled=false;
ToolButtonVertically->Enabled=false;
ToolButtonHistogramView->Enabled=false;






}
//--------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
int index;
TIniFile *Ini;
if((Ini=new TIniFile(dirApplication+"IPST.ini"))!=NULL)
        {try{
                for(index=0;  index<nopen; index++)
                {
                // if(r1->Items[index]->Tag!=-1)
                 //{
                  Ini->WriteString("Window", "File"+IntToStr(index),MFReopen->Items[index]->Caption);
                 //}
                }
         }
         catch(EFilerError *e)
         {
         ShowMessage(e->Message);
         }

         Ini->FreeInstance();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReopenFile(TObject * Sender)
{
TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
if (ClickedItem){
 switch (ClickedItem->Tag){
  case 0:{
        obtennombre(ClickedItem->Caption);
        CreateMDIChild(ClickedItem->Caption,NULL);
        break;
        }
  case -1:{
  //CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1),NULL);
        break;
            }
        }
    }
}
//---------------------------------------------------------------------------

void TMainForm::UndoUpdate()
{

}
//---------------------------------------------------------------------------

void TMainForm::RedoUpdate()
{

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::HistogramExecute(TObject *Sender)
{
    Histo = true;
    TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
    String name="Histogram="+ExtractFileName(Child->FileName);
    //HistogramForm= new THistogramForm(Application,Child);
    HistogramForm->pChild=Child;
    HistogramForm->Caption=name;
    HistogramForm->NuevoHist();
    //Child->SetForma(HistogramForm);
    HistogramForm->Show();
}
//---------------------------------------------------------------------------

/*
void __fastcall TMainForm::MVTTStatusBarClick(TObject *Sender)
{
if(MVTTStatusBar->Checked==false)
{
 StatusBar->Visible=true;
 MVTTStatusBar->Checked=true;
}
else
{
StatusBar->Visible=false;
 MVTTStatusBar->Checked=false;
}
}     */
//---------------------------------------------------------------------------

void __fastcall TMainForm::DuplicateExecute(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
BYTE *p0;

Screen->Cursor = crHourGlass;
Original=Child->ActiveBitmap();
pBitmap->Assign(Original);

        //CreateMDIChild("Copy of Active" + IntToStr(MDIChildCount + 1),pBitmap);
        String name=ExtractFilePath(Child->FileName)+"\Duplicate "+IntToStr(MDIChildCount + 1)+"="+ExtractFileName(Child->FileName);
        CreateMDIChild(name ,pBitmap);

        Screen->Cursor = crDefault;

}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SplitGrayExecute(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Screen->Cursor = crHourGlass;
pBitmap->Assign(Child->ActiveBitmap());
Pdi->PromedioOIntensidadImagen(pBitmap);
String name=ExtractFilePath(Child->FileName)+"\GrayScale Averaged="+ExtractFileName(Child->FileName);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
CreateMDIChild(name,pBitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": GrayScale Averaged";
AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
pBitmap->FreeImage();
delete pBitmap;
Screen->Cursor = crDefault;
}
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::MIRSpaceClick(TObject *Sender)
{
FrmRes->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MIRColorClick(TObject *Sender)
{
FrmRes1->Show();
}
//---------------------------------------------------------------------------
//----------------------------------------------NOISE--------------------------
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876
float ran0(long *idum)
{

}

float gasdev(long *idum)
//Returns a normally distributed deviate with zero mean and unit variance, using ran1(idum)
//as the source of uniform deviates.
{

}

//----------------------------------------

void __fastcall __AddNoiseMultGauss( Graphics::TBitmap *Bitmap, int porcentaje )
{

}
//--------------------------------------------------------------------------------------------------------------------------------
void TMainForm::ObtenerMediaDesvEst(Graphics::TBitmap  *Bitmap,int mediaA, int mediaV, int mediaR,
                                        Extended DesvEstA, Extended DesvEstV, Extended DesvEstR )
{
        double vecL[256];
        int alto;
        int ancho;
        Extended total=0, totalA=0, totalV=0, totalR=0;
        alto=Bitmap->Height;
        ancho=Bitmap->Width;
        BYTE *p0;
        for (int y=0;  y<alto; y++)
        {
            p0=(BYTE *) Bitmap->ScanLine[y];
            for (int x=0; x<ancho; x++)
                {
                        totalA+=p0[x*3];
                        totalV+=p0[x*3+1];
                        totalR+=p0[x*3+2];
                        total++;
                }
        }
        mediaR=(int)totalR/total;
        mediaV=(int)totalV/total;
        mediaA=(int)totalA/total;
        ShowMessage(mediaR);
        ShowMessage(mediaV);
        ShowMessage(mediaA);

        for (int y=0;  y<alto; y++)
        {
            p0=(BYTE *) Bitmap->ScanLine[y];
            for (int x=0; x<ancho; x++)
                {
                        DesvEstA=pow((p0[x*3]-mediaA),2);
                        DesvEstV=pow((p0[x*3+1]-mediaV),2);
                        DesvEstR=pow((p0[x*3+2]-mediaR),2);
                }
        }
        DesvEstA=sqrt(DesvEstA);
        DesvEstV=sqrt(DesvEstV);
        DesvEstR=sqrt(DesvEstR);
        ShowMessage(IntToStr((int)DesvEstA));
        ShowMessage(IntToStr((int)DesvEstV));
        ShowMessage(IntToStr((int)DesvEstR));
}

//--------------------------------------------------------------------------------------------------------------------------------
void __fastcall __AddNoiseImpulsive( Graphics::TBitmap  *Original, Graphics::TBitmap *Modificada, float p, int imin, int imax )
{


}
//---------------------------------------------------------------------------









//-------------------Ensanchameinto------------------------
void  __fastcall __EnsanchamientoHistograma24( Graphics::TBitmap  *Original, Graphics::TBitmap *Modificada )
{
 // unicamente sobre el plano azul
    int maxb=0,minb=255,maxg=0,ming=255,maxr=0,minr=255;
    BYTE *ptr;

    for( int i=0; i<Original->Height; i++){
        ptr = (BYTE *)Original->ScanLine[i];
        for( int j=0; j<Original->Width; j++){
          if( ptr[j*3] < minb )
               minb = ptr[j*3];
          if( ptr[j*3] > maxb )
               maxb = ptr[j*3];


          if( ptr[j*3+1] < ming )
               ming = ptr[j*3+1];
          if( ptr[j*3+1] > maxg )
               maxg = ptr[j*3+1];

          if( ptr[j*3+2] < minr )
               minr = ptr[j*3+2];
          if( ptr[j*3+2] > maxr )
               maxr = ptr[j*3+2];
       }
    }
    int rangeb = maxb-minb;
    int rangeg = maxg-ming;
    int ranger = maxr-minr;

    Modificada->Assign( Original );
   // if( range < 256 ){
   if(rangeb==0)
      rangeb=1;
    if(rangeg==0)
      rangeg=1;
    if(ranger==0)
       ranger=1;
          for( int i=0; i<Modificada->Height; i++){
            ptr = (BYTE *)Modificada->ScanLine[i];
            for( int j=0; j<Modificada->Width; j++){

               ptr[j*3]   =  255 * (ptr[j*3] - minb)/rangeb ;
               ptr[j*3+1] =  255 *  (ptr[j*3+1] - ming)/rangeg;
               ptr[j*3+2] =  255  * (ptr[j*3+2] - minr)/ranger;
            }
        }
    //}
}
//------------------------------------------------------------------------




void __fastcall TMainForm::MVNormalizeClick(TObject *Sender)
{
NormalizeForm->Show();
}

//---------------------------------------------------------------------------

void TMainForm::histoR(Graphics::TBitmap*imag,float res[256])
{
BYTE *linea;
int x,y,i;
//y=imag->Height;
for(i=0;i<256;i++)
res[i]=0;

for(y=0;y<imag->Height;y++)
{
linea=(BYTE*)imag->ScanLine[y];
for(x=0;x<imag->Width;x++)
{
res[linea[x]]=res[linea[x]]+1;
}
}

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::MMStructureElementClick(TObject *Sender)
{
FSEB->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMBODilationClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Graphics::TBitmap *dilation;//= new Graphics::TBitmap();
Original=Child->ActiveBitmap();
AnsiString tipo=getType(Original);

if(tipo=="Binary"){
pBitmap->Assign(Original);
dilation=FSEB->Morpho->dilateB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);


dilation=FSEB->Morpho->dilateG(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Dilation "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,dilation);
//CrearHijo("Dil with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,dilation);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Dilation "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,dilation);
//CrearHijo("Dil with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,dilation);
}
dilation->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete dilation;
Screen->Cursor=crDefault;
}
//---------------------------------------------------------------------------
Graphics::TBitmap* TMainForm::redPlane(Graphics::TBitmap * input)
{
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
BYTE *p0;
//Screen->Cursor = crHourGlass;
Original=input;
pBitmap->Assign(Original);
for (int y=0;  y<pBitmap->Height; y++)
        {
            p0=(BYTE *)pBitmap->ScanLine[y];
            for (int x=0; x<pBitmap->Width; x++)
                {
                      //codigo del plano rojo en girs
                      //hace el plano rojo en gris
                      p0[x*3]=p0[x*3+1]=p0[x*3+2];

                }
        }
      return pBitmap;
}
Graphics::TBitmap* TMainForm::greenPlane(Graphics::TBitmap* input)
{
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
BYTE *p0;
//Screen->Cursor = crHourGlass;
Original=input;
pBitmap->Assign(Original);
 for (int y=0;  y<pBitmap->Height; y++)
        {
            p0=(BYTE *)pBitmap->ScanLine[y];
            for (int x=0; x<pBitmap->Width; x++)
                {
                   //codigo del plano verde en girs
                   //hace el plano rojo en gris
                   p0[x*3]=p0[x*3+2]=p0[x*3+1];
                }
        }
 return pBitmap;
}
Graphics::TBitmap* TMainForm::bluePlane(Graphics::TBitmap* input)
{
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
BYTE *p0;
//Screen->Cursor = crHourGlass;
Original=input;
pBitmap->Assign(Original);
for (int y=0;  y<pBitmap->Height; y++)
        {
            p0=(BYTE *)pBitmap->ScanLine[y];
            for (int x=0; x<pBitmap->Width; x++)
                {
                  //codigo del plano rojo en girs
                  //hace el plano rojo en gris
                  p0[x*3+1]= p0[x*3+2]=p0[x*3];
                }
        }


return pBitmap;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MMBOErosionClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *erode;//= new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
AnsiString tipo=getType(Original);
if(tipo=="Binary"){
pBitmap->Assign(Original);
erode=FSEB->Morpho->erodeB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);
erode=FSEB->Morpho->erodeG(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
//CrearHijo("Erosion with "+FSEB->EEType+" of: "+Child->Caption,erode);
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Erosion "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,erode);
//CrearHijo("Ero with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,erode);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Erosion "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,erode);
//CrearHijo("Ero with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,erode);
}
erode->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete erode;
Screen->Cursor=crDefault;          
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMBOOpeningClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *opening;//= new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
 AnsiString tipo=getType(Original);
if(tipo=="Binary")
{
pBitmap->Assign(Original);
opening=FSEB->Morpho->openingB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);

opening=FSEB->Morpho->openingG(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);}
//CrearHijo("Opening with "+FSEB->EEType+"of: "+Child->Caption,opening);
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Opening "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,opening);
//CrearHijo("Ope with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,opening);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Opening "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,opening);
//CrearHijo("Ope with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,opening);
}
opening->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete opening;
Screen->Cursor=crDefault;           
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMBOClosingClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *closing;//= new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
AnsiString tipo=getType(Original);
if(tipo=="Binary"){
pBitmap->Assign(Original);
closing=FSEB->Morpho->closingB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);

closing=FSEB->Morpho->closingG(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);}
//CrearHijo("Closing with"+FSEB->EEType+" of: "+Child->Caption,closing);
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Closing "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,closing);
//CrearHijo("Clo with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,closing);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Closing "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,closing);
//CrearHijo("Clo with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,closing);
}
closing->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete closing;
Screen->Cursor=crDefault;               
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMBOTopHatClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *topH;//= new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
AnsiString tipo=getType(Original);
if(tipo=="Binary"){
pBitmap->Assign(Original);
topH=FSEB->Morpho->topHatB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);

topH=FSEB->Morpho->topHat(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);}
//CrearHijo("top-hat with "+FSEB->EEType+" of: "+Child->Caption,topH);
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Top-Hat "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,topH);
//CrearHijo("TH with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,topH);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Top-Hat "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,topH);
//CrearHijo("TH with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,topH);
}
topH->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete topH;
Screen->Cursor=crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMBOBotHatClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Graphics::TBitmap *botH;//= new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
AnsiString tipo=getType(Original);
if(tipo=="Binary"){
pBitmap->Assign(Original);
botH=FSEB->Morpho->botHatB(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);

botH=FSEB->Morpho->botHat(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);}
//CrearHijo("bot-hat with "+FSEB->EEType+" of: "+Child->Caption,botH);
if(FSEB->EEType=="Square"||FSEB->EEType=="Diamond"||FSEB->EEType=="Cross"||FSEB->EEType=="Circle"||
FSEB->EEType=="Ring"||FSEB->EEType=="Exs"||FSEB->EEType=="Sector"||FSEB->EEType=="Arch"||FSEB->EEType=="Polygon"||
FSEB->EEType=="Irregular"){
String name=ExtractFilePath(Child->FileName)+"\Bot-Hat "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,botH);
//CrearHijo("BH with "+FSEB->EEType+" "+IntToStr(FSEB->getTam())+" of: "+Child->Caption,botH);
}
else{
String name=ExtractFilePath(Child->FileName)+"\Bot-Hat "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+"="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,botH);
//CrearHijo("BH with "+FSEB->EEType+" "+IntToStr(FSEB->getWidth())+"x"+IntToStr(FSEB->getHeight())+" of: "+Child->Caption,botH);
}
botH->FreeImage();
pBitmap->FreeImage();
delete pBitmap;
delete botH;
Screen->Cursor=crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MMContrastEnhancementClick(TObject *Sender)
{
Screen->Cursor=crHourGlass;
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
Graphics::TBitmap *Original;// = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap=new Graphics::TBitmap();
Graphics::TBitmap *TH;// = new Graphics::TBitmap();
Graphics::TBitmap *BH;// = new Graphics::TBitmap();
Graphics::TBitmap *Suma;// = new Graphics::TBitmap();
Graphics::TBitmap *Resta;// = new Graphics::TBitmap();
Graphics::TBitmap *auxiliar=new Graphics::TBitmap();
Original=Child->ActiveBitmap();
int a=FSEB->getPlane();
if(a==1)
auxiliar=redPlane(Original);
if(a==2)
auxiliar=greenPlane(Original);
if(a==3)
auxiliar=bluePlane(Original);
pBitmap->Assign(auxiliar);

TH=FSEB->Morpho->topHat(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
BH=FSEB->Morpho->botHat(pBitmap,FSEB->EE,FSEB->ox,FSEB->oy);
Suma=Pdi->Suma(pBitmap,TH);
Resta=Pdi->Resta(Suma,BH);
String name=ExtractFilePath(Child->FileName)+"\Contrast Enhancement="+ExtractFileName(Child->FileName);
CreateMDIChild(name ,Resta);
//CrearHijo("Contrast Enhancement of: "+Child->Caption,Resta);
pBitmap->FreeImage();
TH->FreeImage();
BH->FreeImage();
Suma->FreeImage();
Resta->FreeImage();
delete pBitmap;
delete TH;
delete BH;
delete Suma;
delete Resta;
Screen->Cursor=crDefault;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------






void __fastcall TMainForm::MMGErosionClick(TObject *Sender)
{
FormErosionGeodesic->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMGDilationClick(TObject *Sender)
{
FormGeodesicDilation->Show();
}
//---------------------------------------------------------------------------
  AnsiString TMainForm::getType(Graphics::TBitmap* bit){
  int r,g,b,rgb;
  bool grayFound = false ;

  BYTE *Line;

  for(int i=0; i < bit->Height; i++)
  {
  Line =(BYTE *) bit->ScanLine[i];

    for(int j=0; j < bit->Width; j++)
    {
      b=(int) Line[j*3]; // este es para el azul
      g=(int) Line[j*3+1]; // este es para el verde
      r=(int) Line[j*3+2]; // este es para el rojo


        if (r!=g || r!=b || b!=g)
        {
          return "Color";
        }
        else if ((g != 0) && (g != 255))
                 grayFound = true ;
    }
  }

  return (grayFound)? "Gray" : "Binary" ;

  }

//************Reconstrucción por dilatación*****************************

void __fastcall TMainForm::MMRDilationClick(TObject *Sender)
{
FormReconstructionDilation->Show();
}

//************Reconstrucción por erosión*****************************

void __fastcall TMainForm::MMRErosionClick(TObject *Sender)
{
FormReconstructionErosion->Show();
}
//---------------------------------------------------------------------------

void TMainForm::OKLabeling()
{

}
//---------------------------------------------------------------------------
void TMainForm::UpdateLabeling()
{
   
}
//---------------------------------------------------------------------------
UINT APIENTRY PageSetupHook(HWND HDlg, UINT uiMsg, WPARAM WParam,
                            LPARAM LParam);
//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 

UINT APIENTRY PageSetupHook(HWND HDlg, UINT uiMsg, WPARAM WParam, 
    LPARAM LParam) 
{
    if (uiMsg == WM_INITDIALOG) 
    { 
        RECT FormRect, DialogRect;
        LPPAGESETUPDLG lppsd = (LPPAGESETUPDLG)LParam;

        ::GetWindowRect(lppsd->hwndOwner, &FormRect); 
        ::GetWindowRect(HDlg, &DialogRect);
         
        int cxForm = FormRect.right - FormRect.left;
        int cyForm = FormRect.bottom - FormRect.top;
        int cxDialog = DialogRect.right - DialogRect.left; 
        int cyDialog = DialogRect.bottom - DialogRect.top; 

        MoveWindow(HDlg,
                   (cxForm - cxDialog) / 2 + FormRect.left, 
                   (cyForm - cyDialog) / 2 + FormRect.top,
                   cxDialog, cyDialog, 
                   true); 
    }
    return 0;
}

//---------------------------------------------------------------------------

void TMainForm::Undo()
{

}
//---------------------------------------------------------------------------
void TMainForm::Redo()
{

}
//---------------------------------------------------------------------------





void __fastcall TMainForm::ZoomIn1Click(TObject *Sender)
{
FormZoom->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void TMainForm::FunSequentialThinning()
{

}
//---------------------------------------------------------------------------





void __fastcall TMainForm::MMROpeningClick(TObject *Sender)
{
    hija = (TMDIChild *) ActiveMDIChild;
    Graphics::TBitmap *Nueva =new Graphics::TBitmap();
    AnsiString tipo=getType(hija->ActiveBitmap());
    String name=ExtractFilePath(hija->FileName)+"\OpR="+ExtractFileName(hija->FileName);
    Screen->Cursor = crHourGlass;
    entrada =new Graphics::TBitmap();
    entrada = hija->ActiveBitmap();//Plano Verde
    Nueva->Assign(entrada);
    //entrada = Pdi->NGG(entrada);//Plano Verde
if(tipo=="Binary"){
entrada=FSEB->Morpho->erodeB(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
entrada=FSEB->Morpho->erodeG(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
    entrada->Assign(Pdi->RecGD(Nueva, entrada));
    Screen->Cursor=crDefault;
    CreateMDIChild(name ,entrada);
    entrada->FreeImage();
    delete entrada;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMRClosingClick(TObject *Sender)
{
    hija = (TMDIChild *) ActiveMDIChild;
    Graphics::TBitmap *Nueva =new Graphics::TBitmap();
    AnsiString tipo=getType(hija->ActiveBitmap());
    String name=ExtractFilePath(hija->FileName)+"\CLR="+ExtractFileName(hija->FileName);
    Screen->Cursor = crHourGlass;
    entrada =new Graphics::TBitmap();
    entrada = hija->ActiveBitmap();//Plano Verde
    Nueva->Assign(entrada);
    //entrada = Pdi->NGG(entrada);//Plano Verde
if(tipo=="Binary"){
entrada=FSEB->Morpho->dilateB(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
entrada=FSEB->Morpho->dilateG(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
    entrada->Assign(Pdi->RecGE(Nueva, entrada));
    Screen->Cursor=crDefault;
    CreateMDIChild(name ,entrada);
    entrada->FreeImage();
    delete entrada;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMRWhiteTopHatClick(TObject *Sender)
{
    hija = (TMDIChild *) ActiveMDIChild;
    Graphics::TBitmap *Nueva =new Graphics::TBitmap();
    AnsiString tipo=getType(hija->ActiveBitmap());
    String name=ExtractFilePath(hija->FileName)+"\THWR="+ExtractFileName(hija->FileName);
    Screen->Cursor = crHourGlass;
    entrada =new Graphics::TBitmap();
    entrada = hija->ActiveBitmap();//Plano Verde
    Nueva->Assign(entrada);
    //entrada = Pdi->NGG(entrada);//Plano Verde
if(tipo=="Binary"){
entrada=FSEB->Morpho->erodeB(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
entrada=FSEB->Morpho->erodeG(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
    entrada->Assign(Pdi->RecGD(Nueva, entrada));
    entrada->Assign(Pdi->subImgs(Nueva,entrada));
    Screen->Cursor=crDefault;
    CreateMDIChild(name ,entrada);
    entrada->FreeImage();
    delete entrada;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MMRBlackTopHatClick(TObject *Sender)
{
    hija = (TMDIChild *) ActiveMDIChild;
    Graphics::TBitmap *Nueva =new Graphics::TBitmap();
    AnsiString tipo=getType(hija->ActiveBitmap());
    String name=ExtractFilePath(hija->FileName)+"\THBR="+ExtractFileName(hija->FileName);
    Screen->Cursor = crHourGlass;
    entrada =new Graphics::TBitmap();
    entrada = hija->ActiveBitmap();//Plano Verde
    Nueva->Assign(entrada);
    //entrada = Pdi->NGG(entrada);//Plano Verde
if(tipo=="Binary"){
entrada=FSEB->Morpho->dilateB(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
else{
entrada=FSEB->Morpho->dilateG(entrada,FSEB->EE,FSEB->ox,FSEB->oy);
}
    entrada->Assign(Pdi->RecGE(Nueva, entrada));
    entrada->Assign(Pdi->subImgs(entrada,Nueva));
    Screen->Cursor=crDefault;
    CreateMDIChild(name ,entrada);
    entrada->FreeImage();
    delete entrada;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormShow(TObject *Sender)
{
if(FormEntrada)
    {
        Sleep(500);
        delete FormEntrada;
        FormEntrada = NULL;
    }
}
//---------------------------------------------------------------------------


void TMainForm::AgregarAnalisisReporte(TMDIChild *Child,TMDIChild *Child2,String proceso){
Child2->NombreComando=Child->NombreComando;
Child2->ConteoProcesos=Child->ConteoProcesos+1;
pms->Clear();
Child->ReportProcessedImageChild->Lines->SaveToStream(pms);
pms->Position = 0;
Child2->ReportProcessedImageChild->Lines->LoadFromStream(pms);
Child2->ReportProcessedImageChild->Lines->Add("");
Child2->ReportProcessedImageChild->SelAttributes->Style=
Child2->ReportProcessedImageChild->SelAttributes->Style << fsUnderline;
Child2->ReportProcessedImageChild->Lines->Add(AnsiString(Child2->ConteoProcesos)+proceso);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MCNegativeClick(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
Screen->Cursor = crHourGlass;
Bitmap->Assign(Child->ActiveBitmap());
MainForm->Pdi->Negado(Bitmap);
String name=ExtractFilePath(Child->FileName)+"\Negative="+ExtractFileName(Child->FileName);
CreateMDIChild(name,Bitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": Negative";
AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
Screen->Cursor = crDefault;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MCHStretchingClick(TObject *Sender)
{
TMDIChild* Child = (TMDIChild *)ActiveMDIChild;
Screen->Cursor = crHourGlass;
if(Child!=NULL){
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();

    __EnsanchamientoHistograma24( Child->Image->Picture->Bitmap, pBitmap);
String name=ExtractFilePath(Child->FileName)+"\Stretching="+ExtractFileName(Child->FileName);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
CreateMDIChild(name,pBitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": Stretching";
AgregarAnalisisReporte(Child,Child2,proceso);
Child2->ImageClick(Child2);
pBitmap->FreeImage();
delete pBitmap;
}
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FileCloseNoActiveExecute(TObject *Sender)
{
int i;
for(int i =MDIChildCount-1; i>=0; i--){
 if(ActiveMDIChild!=MDIChildren[i])
  MDIChildren[i]->Close();
 }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MILogicalOperationsClick(TObject *Sender)
{
OperacionesLog->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MIArthmeticOperationsClick(TObject *Sender)
{
FormArithmeticOperations->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ActualizarMainFormUpdate(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
MFile->Enabled=true;
MEdit->Enabled = true;
MView->Enabled=true;
MColor->Enabled=true;
MImage->Enabled=true;
MTools->Enabled=true;
MMorphology->Enabled=true;
MHelp->Enabled=true;
MWindow->Enabled=true;
ToolButtonSave->Enabled=true;
ToolButtonCloseAll->Enabled=true;
ToolButtonCascade->Enabled=true;
ToolButtonHorizontally->Enabled=true;
ToolButtonVertically->Enabled=true;
ToolButtonHistogramView->Enabled=true;


TClipboard* Clip = new TClipboard();
if (Clip->HasFormat(CF_BITMAP)){

}
else{

}


FileNew->Enabled=true;
FileClose->Enabled=true;
FileCloseAll->Enabled=true;
FileCloseNoActive->Enabled=true;
//FileSave->Enabled=true;
FileSaveAs->Enabled=true;
FileSaveAll->Enabled=true;
FileSaveCopyAs->Enabled=true;
//MFDelete->Enabled=true;
//MFSend->Enabled=true;
FilePageSetup->Enabled=true;
FilePrint->Enabled=true;
FilePrintPreview->Enabled=true;
//MFPrintMultipleImages->Enabled=true;
}
else{
MFile->Enabled=true;
MEdit->Enabled=false;
MView->Enabled=false;
MColor->Enabled=false;
MImage->Enabled=false;
MTools->Enabled=false;
MMorphology->Enabled=false;
MHelp->Enabled=true;
MWindow->Enabled=false;
ToolButtonSave->Enabled=false;
ToolButtonCloseAll->Enabled=false;


ToolButtonCascade->Enabled=false;
ToolButtonHorizontally->Enabled=false;
ToolButtonVertically->Enabled=false;
ToolButtonHistogramView->Enabled=false;




FileNew->Enabled=false;
FileClose->Enabled=false;
FileCloseAll->Enabled=false;
FileCloseNoActive->Enabled=false;
FileSave->Enabled=false;
FileSaveAs->Enabled=false;
FileSaveAll->Enabled=false;
FileSaveCopyAs->Enabled=false;

FilePageSetup->Enabled=false;
FilePrint->Enabled=false;
FilePrintPreview->Enabled=false;

}
}
//---------------------------------------------------------------------------

int TMainForm::Redondea(float r)
{
int r1 = r;
float resta = r - r1;
if (resta >= 0 && resta < 0.5)
        {return r1;}
else if (resta >= 0.5 && resta < 1)
        {return r1 + 1;}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButtonGlassesClick(TObject *Sender)
{
//FormGlasses->FormaEstaAbierta=true;
//FormGlasses->Show();
//SetFocus();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL&& Child->ImagePegarSeleccion->Tag!=0){
Child->PixelXMove=X-Child->ClientOrigin.x-Child->Image->Left;
Child->PixelYMove=Y-Child->ClientOrigin.y+40-Child->Image->Top;
Child->PegarSeleccionComo(Child->PixelXMove,Child->PixelYMove);
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormDblClick(TObject *Sender)
{
TMDIChild *Child=(TMDIChild*)ActiveMDIChild;
if(Child!=NULL && Child->ImagePegarSeleccion->Tag!=0){
Child->ImagePegarSeleccion->Tag=0;
}
}
//---------------------------------------------------------------------------

int TMainForm::RedondeaPositivos(double numero)
{
SetRoundMode(rmNearest);
double incremento=10000000;
for(int digito=6;digito>0;digito--){
numero=RoundTo(numero,-digito);
numero=numero+(1/incremento);
incremento=incremento/10;
}
numero=numero+0.5;
int valor=(int)numero;
return valor;
}
//---------------------------------------------------------------------------
void TMainForm::EqualizacionHistograma(TMDIChild *Child,Graphics::TBitmap* pBitmap)
{

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MCGWeightedClick(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Screen->Cursor = crHourGlass;
pBitmap->Assign(Child->ActiveBitmap());
Pdi->GrayScaleWeighted(pBitmap);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
String name=ExtractFilePath(Child->FileName)+"\GrayScale Weighted="+ExtractFileName(Child->FileName);
CreateMDIChild(name,pBitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": GrayScale Weighted";
AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
pBitmap->FreeImage();
delete pBitmap;
Screen->Cursor = crDefault;
}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Weighted21Click(TObject *Sender)
{
TMDIChild *Child =(TMDIChild *)ActiveMDIChild;
if(Child!=NULL){
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
Screen->Cursor = crHourGlass;
pBitmap->Assign(Child->ActiveBitmap());
Pdi->GrayScaleWeighted(pBitmap);
//String name=ExtractFilePath(Child->FileName)+AnsiString(strtok(ExtractFileName(Child->NombreComando).c_str(),"."))+" "+AnsiString(Child->ConteoProcesos+1)+ExtractFileExt(Child->FileName);
String name=ExtractFilePath(Child->FileName)+"\GrayScale Weighted="+ExtractFileName(Child->FileName);
CreateMDIChild(name,pBitmap);
TMDIChild *Child2 =(TMDIChild *)ActiveMDIChild;
String proceso=": GrayScale Weighted";
AgregarAnalisisReporte(Child,Child2,proceso);
//Agregar atributos del proceso
//Child2->ReportProcessedImageChild->Lines->Add(AnsiString("Etiqueta: ")+);
Child2->ImageClick(Child2);
pBitmap->FreeImage();
delete pBitmap;
Screen->Cursor = crDefault;
}
}
//---------------------------------------------------------------------------












/*
//-------------------Funciones de Eje Medio / Esqueleto------------------------
void  __fastcall __EjeMedio( Graphics::TBitmap  *Original, Graphics::TBitmap *Modificada )
{

Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
int width  = Bitmap1->Width;   //Ancho
int height = Bitmap1->Height;  //Altura
int kx = 0, ky = 0, kz = 0;
std::vector<int> ValorMedio;
 int maxb=0,minb=255,maxg=0,ming=255,maxr=0,minr=255;




        for(int x = 0; x<width; x++){

          for(int y = 0; y<height; y++){
              if( y == 0) {
                 ky += y;
                 ValorMedio.push_back((Bitmap1->Canvas->Pixels[x][y]));

              }
          }
                if(ValorMedio.size() % 2 == 0){
                        kz  = ValorMedio.size()/2;
                }
                else{
                        kz = ky/ValorMedio.size(); //obteniendo el valor medio de y
               }
               TColor medio;
               medio = TColor(clRed);
               //Agrega para colorear el pixel
               Bitmap1->Canvas->Pixels[x][kz] = medio;

            // ky = (Bitmap1->Canvas->Pixels[x][height])/2;
           // ValorMedio.push_back((bitmap->Canvas->Pixels[x][height/2]));
           ky = 0;
           ValorMedio.empty();

        }






}
//------------------------------------------------------------------------






      */


    //-------------------Funciones de Eje Medio / Esqueleto------------------------
void  __fastcall __EjeMedio( Graphics::TBitmap  *Original )
{

Graphics::TBitmap *Bitmap1=new Graphics::TBitmap();
int width  = Bitmap1->Width;   //Ancho
int height = Bitmap1->Height;  //Altura
int kx = 0, ky = 0, kz = 0;
std::vector<int> ValorMedio;
 int maxb=0,minb=255,maxg=0,ming=255,maxr=0,minr=255;




        for(int y = 0; y<width; y++){

          for(int x = 0; x<height; x++){
              if( x == 0) {
                 ky += x;
                 ValorMedio.push_back((Bitmap1->Canvas->Pixels[x][y]));

              }
          }
                if(ValorMedio.size() % 2 == 0){
                        kz  = ValorMedio.size()/2;
                }
                else{
                        kz = ky/ValorMedio.size(); //obteniendo el valor medio de y
               }
               TColor medio;
               medio = TColor(10);
               //Agrega para colorear el pixel
               for(int c = kz-4; c<kz+4;c++){
                 Bitmap1->Canvas->Pixels[y][c] = medio;
               }
            // ky = (Bitmap1->Canvas->Pixels[x][height])/2;
           // ValorMedio.push_back((bitmap->Canvas->Pixels[x][height/2]));
           ky = 0;
           ValorMedio.empty();

        }






}
//------------------------------------------------------------------------







void __fastcall TMainForm::MedialAxis1Click(TObject *Sender)
{

/*TMDIChild* Child = (TMDIChild *)ActiveMDIChild;
Screen->Cursor = crHourGlass;
if(Child!=NULL){
        Graphics::TBitmap *Bitmap_Eje = new Graphics::TBitmap();
        Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
        pBitmap->Assign(Child->ActiveBitmap());

        //  __EjeMedio( Child->Image->Picture->Bitmap, pBitmap);
        __EjeMedio( pBitmap);
        String name=ExtractFilePath(Child->FileName)+"\Eje Medio="+ExtractFileName(Child->FileName);
        CreateMDIChild(name,pBitmap);
        pBitmap->FreeImage();
        delete pBitmap;
}
Screen->Cursor = crDefault;*/




Medial_Axis->Show();


}

//---------------------Funciones Ruido-------------------------
void __fastcall TMainForm::UniformNoiseRandom1Click(TObject *Sender)
{
      Noise->Show();
      return;
}
//---------------------------------------------------------------------------

 /*
 void AplicarRuido(Graphics::TBitmap *bitmap, int v) {

    int width = bitmap->Width;
    int height = bitmap->Height;
    int r;
        srand(time(0));
    // Bucle externo que recorre las filas de la imagen
    for (int y = 0; y < height; y++) {
        // Bucle interno que recorre las columnas de la imagen
        for (int x = 0; x < width; x++) {
            // r = rand()%2;


                int ran = rand()%2;

                if(ran == 0){
                       bitmap->Canvas->Pixels[x][y] =  0;
                       }
                else{
                       bitmap->Canvas->Pixels[x][y] =  RGB(255,255,255);
                       }





        }
    }
}


*/


void __fastcall TMainForm::SaltPepperNoiseRandom1Click(TObject *Sender)
{
/*
       //SaltnPepper->Show();
        TMDIChild* Child = (TMDIChild *)ActiveMDIChild;
Screen->Cursor = crHourGlass;
if(Child!=NULL){
Graphics::TBitmap *Bitmap_Eje = new Graphics::TBitmap();
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
pBitmap->Assign(Child->ActiveBitmap());


String name=ExtractFilePath(Child->FileName)+"\SalyPimienta="+ExtractFileName(Child->FileName);
CreateMDIChild(name,pBitmap);
pBitmap->FreeImage();
delete pBitmap;
}
Screen->Cursor = crDefault;
                           */
        SaltnPepper->Show();
        return;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExponencialNoiseRandom1Click(TObject *Sender)
{
     Exponencial->Show();
     return;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pseudocolor1Click(TObject *Sender)
{
        Background->Show();

        return;
}
//---------------------------------------------------------------------------


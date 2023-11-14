//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ChildWin.h"
#include "AboutWin.h"
#include "Main.h"
#include "HistogramWin.h"
#include "Operaciones_Log.h"
#include <math.h>
#include "Normalizar.h"
#include "Zoom.h"
#include "ZoomNe.h"
#include "Resolution.h"
#include "Resolution1.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIChild *MDIChild;
//TForm* actual;
//---------------------------------------------------------------------------
__fastcall TMDIChild::TMDIChild(TComponent* Owner)
        : TForm(Owner)
{
    ReportProcessedImageChild = new TRichEdit(this);
    ReportProcessedImageChild->Parent=this;
    ReportProcessedImageChild->Visible=false;
    ReportProcessedImageChild->WordWrap=false;
    ReportProcessedImageChild->Clear();
    FondoImage->Canvas->Brush->Bitmap = ImageFondo->Picture->Bitmap;
    Tope_temporal=0;
    Bandera_Undo=0;
    MAX=20;
    Tope=0;
    index=0;
    indexFormas=0;

    for(int i=0; i<256; i++)
    {
        LUT[i]=i;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
MainForm->StatusBar->Panels->Items[1]->Text="";
MainForm->StatusBar->Panels->Items[3]->Text="";
MainForm->StatusBar->Panels->Items[5]->Text="";
MainForm->StatusBar->Panels->Items[7]->Text="";
MainForm->StatusBar->Panels->Items[9]->Text="";
MainForm->StatusBar->Canvas->Brush->Color=clBtnFace;
MainForm->StatusBar->Canvas->Rectangle(330,1,364,18);
MainForm->StatusBar->Panels->Items[13]->Text ="";
if (MainForm->Histo){
        if(HistogramForm->pChild==this){
        HistogramForm->pChild=NULL;
        }
}
/*if (MainForm->Graphics){
        if(Form7->pChild==this){
        Form7->pChild=NULL;
        }
} */
/*if (MainForm->AdaptiveForm){
        if(FormThresholdAdaptive->pChild==this){
        FormThresholdAdaptive->pChild=NULL;
        }
} */

for(int i=0; i<indexFormas; i++)
{
Ligadas[i]->Close();
}
Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::ImageMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
PixelXMove=X;
PixelYMove=Y;
PixelRMove=GetRValue(Image->Picture->Bitmap->Canvas->Pixels[X][Y]);
PixelGMove=GetGValue(Image->Picture->Bitmap->Canvas->Pixels[X][Y]);
PixelBMove=GetBValue(Image->Picture->Bitmap->Canvas->Pixels[X][Y]);

if(ImagePegarSeleccion->Tag!=0){
Cursor = TCursor(crSize);
PegarSeleccionComo(X,Y);
}
else{
/*if(MainForm->ToolButtonSelection->Down==true){
Cursor = TCursor(crCross);
}
else{Cursor = TCursor(crDefault);}  */
}



if((X>=0&&X<=Image->Width)&&(Y>=0&&Y<=Image->Height)){
if (Shift.Contains(ssLeft)&& !Shift.Contains(ssDouble)){
/*if (Form1NewMask->FormaEstaAbierta==true && Form1NewMask->CheckBoxOnlyToSelect->Checked==true && Form1NewMask->CheckBoxFreezeValues->Checked==false){
        if(Form1NewMask->RadioButtonRectangle->Checked==true){
        DrawShapeRec(X, Y);
        }
        else if(Form1NewMask->RadioButtonSquare->Checked==true){
        DrawShapeSqu(X, Y);
        }
        else if(Form1NewMask->RadioButtonCircle->Checked==true){
        DrawShapeCir(X, Y);
        }
}*/

//if (MainForm->ToolButtonSelection->Down==true){
//DrawShapeRec(X, Y); }
}
}
//Form1NewMask->ValorXV->Caption=IntToStr(X);
//Form1NewMask->ValorYV->Caption=IntToStr(Y);
TColor C;

MainForm->StatusBar->Panels->Items[1]->Text=IntToStr(X);
MainForm->StatusBar->Panels->Items[3]->Text=IntToStr(Y);
C=Image->Canvas->Pixels[X][Y];
MainForm->StatusBar->Panels->Items[5]->Text=IntToStr(GetRValue(C));
MainForm->StatusBar->Panels->Items[7]->Text=IntToStr(GetGValue(C));
MainForm->StatusBar->Panels->Items[9]->Text=IntToStr(GetBValue(C));
MainForm->StatusBar->Canvas->Brush->Color=C;
MainForm->StatusBar->Canvas->Rectangle(330,1,364,18);
MainForm->StatusBar->Panels->Items[13]->Text = MainForm->getType(Image->Picture->Bitmap);

}
//---------------------------------------------------------------------------

//---- Funcion que crea el histograma de cualquier imagen
void TMDIChild::CrearHistograma()
{
    Screen->Cursor = crHourGlass;
    for(int i=0; i<256; i++)                       // Inicializa la estructura del Histograma
    {
        Histo.R[i]=0; Histo.G[i]=0; Histo.B[i]=0;
    }
    Histo.medianaR=0;Histo.medianaG=0;Histo.medianaB=0;
    Histo.PixelsL=0;Histo.PixelsR=0;Histo.PixelsG=0;Histo.PixelsB=0;
    Graphics::TBitmap *tmpImage;
    int h =Image->Picture->Bitmap->Height;
    int w =Image->Picture->Bitmap->Width;

    tmpImage=Image->Picture->Bitmap;
    BYTE *p0;

    float Total;
    for (int y=0;  y<h; y++)
    {
        p0=(BYTE *)tmpImage->ScanLine[y];
        for (int x=0; x<w; x++)
        {
            Histo.B[p0[x*3]]++;    // Modifica el valor de Azul con la LUT
            Histo.G[p0[x*3+1]]++;// Modifica el valor de Verde con la LUT
            Histo.R[p0[x*3+2]]++;// Modifica el valor de Rojo con la LUT
        }
    }
    for(int i=0; i<256; i++)
    {
        Histo.L[i]=(Histo.R[i]+Histo.G[i]+Histo.B[i])/3; // Se calcula la luminosidad
        Histo.PixelsL+=Histo.L[i];
        Histo.PixelsR+=Histo.R[i];
        Histo.PixelsG+=Histo.G[i];
        Histo.PixelsB+=Histo.B[i];
    }
    Histo.media_ponderadaL=Histo.PixelsL/256; // Se calcula la media ponderada de la luminosidad
    Histo.media_ponderadaR=Histo.PixelsR/256; // Se calcula la media ponderada del Rojo
    Histo.media_ponderadaG=Histo.PixelsG/256; // Se calcula la media ponderada del Verde
    Histo.media_ponderadaB=Histo.PixelsB/256; // Se calcula la media ponderada del Azul
    Total=0;
    for(int i=0; i<256; i++)
    {
        Total+=Histo.L[i];
        if(((Total/Histo.PixelsL)*100)>=50)
        {
            Histo.medianaL=i;
            break;
        }
    }
    Total=0;
    for(int i=0; i<256; i++)
    {
        Total+=Histo.R[i];
        if(((Total/Histo.PixelsR)*100)>=50)
        {
            Histo.medianaR=i;
            break;
        }
    }
    Total=0;
    for(int i=0; i<256; i++)
    {
        Total+=Histo.G[i];
        if(((Total/Histo.PixelsG)*100)>=50)
        {
            Histo.medianaG=i;
            break;
        }
    }
    Total=0;
    for(int i=0; i<256; i++)
    {
        Total+=Histo.B[i];
        if(((Total/Histo.PixelsB)*100)>=50)
        {
            Histo.medianaB=i;
            break;
        }
    }

    Screen->Cursor = crDefault;
}

//----------------------------------------------
// Funcion para almacenar el buffer las imagenes
bool TMDIChild::cImage(Graphics::TBitmap *clip)
{
    if(index<20)
    {
        matrizFileName[index]=FileName;
        matriz[index]= MainForm->nombrecomando;
        Arr[index]=new Graphics::TBitmap();
        Arr[index]->PixelFormat=pf24bit;
        Arr[index]->Assign(clip);
        Image->Picture->Bitmap->Assign(Arr[index++]);
        Arr[index-1]->PixelFormat=pf24bit;
        if (Bandera_Undo==0)
        {Tope++;}
        else {
        Tope=Tope_temporal;
        Bandera_Undo = 0;}
        return true;
    }
    else
        return false;
}
//----------------------------------------------
// Funcion para rehacer la ultima accion
bool TMDIChild::cImageUndo()
{

}
bool TMDIChild::cImageRedo() // Funcion para rehacer la ultima accion
{

}

bool TMDIChild::isDo()
{
        if (index>1)
                return true;
return false;
}
bool TMDIChild::isRedo()
{
        if (index<Tope_temporal && Tope_temporal <= Tope)
                return true;
return false;

}

Graphics::TBitmap * TMDIChild::ActiveBitmap()
{
return Image->Picture->Bitmap;
}

void TMDIChild::cImageRefresh()
{
        //TODO: Add your source code here
int y,x;
PByteArray p0;
Graphics::TBitmap *tmpImage=new Graphics::TBitmap();
tmpImage->Assign(Arr[index-1]);

Screen->Cursor = crHourGlass;

for (y=0;  y<tmpImage->Height; y++)
        {
            p0=(PByteArray)tmpImage->ScanLine[y];
            for (x=0; x<tmpImage->Width; x++)
                {
                      p0[x*3]=LUT[p0[x*3]];    // Modifica el valor de Azul con la LUT
                      p0[x*3+1]=LUT[p0[x*3+1]];// Modifica el valor de Verde con la LUT
                      p0[x*3+2]=LUT[p0[x*3+2]];// Modifica el valor de Rojo con la LUT
                }
        }
this->Image->Picture->Bitmap->Assign(tmpImage);
tmpImage->FreeImage();
delete tmpImage;
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::CIHistogramClick(TObject *Sender)
{
//HistogramForm= new THistogramForm(Application);
HistogramForm->pChild=this;
HistogramForm->Show();

}
//---------------------------------------------------------------------------

void TMDIChild::SetForma(TForm *name)
{
    Ligadas[indexFormas++]=name;
}

//---------------------------------------------------------------------------

void __fastcall TMDIChild::ImageClick(TObject *Sender)
{
//Almacena los valores del pixel al que se le dio Click
if(!(MainForm->StatusBar->Panels->Items[1]->Text==""&&
   MainForm->StatusBar->Panels->Items[3]->Text=="")){
  PixelX=StrToInt(MainForm->StatusBar->Panels->Items[1]->Text);
  PixelY=StrToInt(MainForm->StatusBar->Panels->Items[3]->Text);
}
else{
  PixelX=0;
  PixelY=0;
}
PixelR=GetRValue(Image->Picture->Bitmap->Canvas->Pixels[PixelX][PixelY]);
PixelG=GetGValue(Image->Picture->Bitmap->Canvas->Pixels[PixelX][PixelY]);
PixelB=GetBValue(Image->Picture->Bitmap->Canvas->Pixels[PixelX][PixelY]);

if (MainForm->Histo){
        HistogramForm->pChild=this;
        HistogramForm->NuevoHist();
}





MainForm->pms->Clear();

MainForm->pms->Position = 0;

           
MainForm->StatusBar->Panels->Items[13]->Text ="";
for(int i = MainForm->MDIChildCount-1; i >= 0; i--)
    {if(!MainForm->MDIChildren[i]->Active)
    {MainForm->MDIChildren[i]->Refresh();
    MainForm->MDIChildren[i]->Cursor= TCursor(crDefault);}}

TMDIChild *hijo=(TMDIChild*)MainForm->ActiveMDIChild;
String name="Search Pixel="+ExtractFileName(hijo->FileName);
//FormSearchPixel->Caption=name;
name="Filters="+ExtractFileName(hijo->FileName);

name="New mask of the image="+ExtractFileName(hijo->FileName);


MainForm->StatusBar->Panels->Items[11]->Text = MainForm->getType(Image->Picture->Bitmap);




TListItem * lstItem;
char *R;
char *G;
char *B;

}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::FormClick(TObject *Sender)
{
MainForm->StatusBar->Panels->Items[11]->Text = MainForm->getType(Image->Picture->Bitmap);
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*if(MainForm->ToolButtonSelection->Down==true){
if((X>=0&&X<=Image->Width)&&(Y>=0&&Y<=Image->Height)){
if (Button == mbLeft){
        InitialX = X;
        InitialY = Y;
        }
}
} */

}
//---------------------------------------------------------------------------

/*void TMDIChild::cargaDireccion(TCountColors *dir)
{
        formDatos = dir;
}   */
//---------------------------------------------------------------------------






void __fastcall TMDIChild::DrawShapeRec(int X, int Y)
{
 if((X>=0&&X<=Image->Width)&&(Y>=0&&Y<=Image->Height)){
 
         if (X < InitialX)
        {
                bounds.Left = X;
                bounds.Right = InitialX;
        }
        else
        {
                bounds.Left = InitialX;
                bounds.Right = X;
        }
        if (Y < InitialY)
        {
                bounds.Top = Y;
                bounds.Bottom = InitialY;
        }
        else
        {
                bounds.Top = InitialY;
                bounds.Bottom = Y;
        }
         /*
        if (Form1NewMask->FormaEstaAbierta==true && Form1NewMask->CheckBoxOnlyToSelect->Checked==true && Form1NewMask->CheckBoxFreezeValues->Checked==false){
        Form1NewMask->LabelValorSuperiorCornerX->Caption = IntToStr(bounds.Left);
        Form1NewMask->LabelValorSuperiorCornerY->Caption = IntToStr(bounds.Top);
        Form1NewMask->LabelValorInferiorCornerX->Caption = IntToStr(bounds.Right);
        Form1NewMask->LabelValorInferiorCornerY->Caption = IntToStr(bounds.Bottom);
        }
        if (Form1NewMask->FormaEstaAbierta==true && Form1NewMask->CheckBoxOnlyToSelect->Checked==true && Form1NewMask->CheckBoxFreezeValues->Checked==false){
        Form1NewMask->LabelValorSuperiorCornerX->Caption = IntToStr(bounds.Left);
        Form1NewMask->LabelValorSuperiorCornerY->Caption = IntToStr(bounds.Top);
        Form1NewMask->LabelValorInferiorCornerX->Caption = IntToStr(bounds.Right);
        Form1NewMask->LabelValorInferiorCornerY->Caption = IntToStr(bounds.Bottom);
        }  */
        boundsSelection.Right=bounds.Right;
        boundsSelection.Left=bounds.Left;
        boundsSelection.Top=bounds.Top;
        boundsSelection.Bottom=bounds.Bottom;
        bounds.Right = bounds.Right+Image->Left;
        bounds.Left = bounds.Left+Image->Left;
        bounds.Top = bounds.Top+Image->Top;
        bounds.Bottom = bounds.Bottom+Image->Top;
        Refresh();
        Canvas->Pen->Style = psDot;
        Canvas->Pen->Mode = pmNot;
        Canvas->Brush->Style = bsClear;
        Canvas->Rectangle(bounds);

 }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::DrawShapeSqu(int X, int Y)
{
 TRect bounds;
        if (X < InitialX)
        {
                bounds.Left = X;
                bounds.Right = InitialX;
        }
        else
        {
        bounds.Right = X;
        bounds.Left = InitialX;
        }
        if (Y < InitialY)
        {
                bounds.Bottom = InitialY;
                bounds.Top = Y;
        }
        else
        {
                bounds.Bottom = Y;
                bounds.Top = InitialY;
        }
//        Form1NewMask->LabelValorSuperiorCornerX->Caption = IntToStr(bounds.Left);
//        Form1NewMask->LabelValorSuperiorCornerY->Caption = IntToStr(bounds.Top);
//        Form1NewMask->LabelValorInferiorCornerX->Caption = IntToStr(bounds.Right);
//        Form1NewMask->LabelValorInferiorCornerY->Caption = IntToStr(bounds.Bottom);
        this->Image->Refresh();
        this->Canvas->Pen->Style = psDot;
        this->Canvas->Pen->Mode = pmNot;
        this->Canvas->Brush->Style = bsClear;
        this->Canvas->Rectangle(bounds);
        //this->Image->Canvas->RoundRect(InitialX, InitialY, X, Y, X, Y);

}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::DrawShapeCir(int X, int Y)
{
 TRect bounds;
        if (X < InitialX)
        {
                bounds.Left = X;
                bounds.Right = InitialX;
        }
        else
        {
        bounds.Right = X;
        bounds.Left = InitialX;
        }
        if (Y < InitialY)
        {
                bounds.Bottom = InitialY;
                bounds.Top = Y;
        }
        else
        {
                bounds.Bottom = Y;
                bounds.Top = InitialY;
        }
//        Form1NewMask->LabelValorSuperiorCornerX->Caption = IntToStr(bounds.Left);
//        Form1NewMask->LabelValorSuperiorCornerY->Caption = IntToStr(bounds.Top);
//        Form1NewMask->LabelValorInferiorCornerX->Caption = IntToStr(bounds.Right);
//        Form1NewMask->LabelValorInferiorCornerY->Caption = IntToStr(bounds.Bottom);
        this->Image->Refresh();
        this->Canvas->Pen->Style = psDot;
        this->Canvas->Pen->Mode = pmNot;
        this->Canvas->Brush->Style = bsClear;
        this->Canvas->Arc(InitialX, InitialY, X, Y, X, Y, X, Y);

}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::CFSaveasClick(TObject *Sender)
{
MainForm->FileSaveAsExecute(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TMDIChild::FormResize(TObject *Sender)
{
        if(ClientHeight>=Image->Height)
        {
            Image->Top = (ClientHeight - Image->Height) /2;
            ImageSearchPixel->Top = (ClientHeight - Image->Height) /2;
            FondoImage->Height = ClientHeight;
            FondoImage->Picture->Bitmap->Height = ClientHeight;
        }
        else{
            Image->Top = 0;
            ImageSearchPixel->Top = 0;
            }

        if(ClientWidth>=Image->Width)
        {
            Image->Left = (ClientWidth - Image->Width) /2;
            ImageSearchPixel->Left = (ClientWidth - Image->Width) /2;
            FondoImage->Width = ClientWidth;
            FondoImage->Picture->Bitmap->Width = ClientWidth;
        }
        else{
            Image->Left = 0;
            ImageSearchPixel->Left = 0;
            }
        Refresh();
        FondoImage->Canvas->FillRect(TRect(0, 0, FondoImage->Width, FondoImage->Height));
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::CVReportoftheprocessedimageClick(TObject *Sender)
{

MainForm->pms->Clear();

MainForm->pms->Position = 0;

}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::FormKeyPress(TObject *Sender, char &Key)
{
if(Key==0x1B && ImagePegarSeleccion->Tag!=0){
ImagePegarSeleccion->Tag=0;
Cursor = TCursor(crDefault);
TPoint pos;
GetCursorPos(&pos);
SetCursorPos(pos.x,pos.y);
Image->Canvas->Draw(0,0,ImageRespaldo->Picture->Bitmap);
ImageSearchPixel->Picture->Bitmap->Assign(Image->Picture->Bitmap);
}
else if((Key=='D' || (Key=='d')) && D==0 && ImagePegarSeleccion->Tag!=0){
D=1;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='D' || (Key=='d')) && D==1 && ImagePegarSeleccion->Tag!=0){
D=0;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='T' || (Key=='t')) && T==0 && ImagePegarSeleccion->Tag!=0){
T=1;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='T' || (Key=='t')) && T==1 && ImagePegarSeleccion->Tag!=0){
T=0;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='R' || Key=='r') && ImagePegarSeleccion->Tag!=0){
R=1;
grados=grados+1;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='L' || Key=='l') && ImagePegarSeleccion->Tag!=0){
R=2;
grados=grados-1;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if((Key=='O' || Key=='o') && ImagePegarSeleccion->Tag!=0){
R=0;
grados=0;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
}
//---------------------------------------------------------------------------
void TMDIChild::PegarSeleccionComo(int PixelXMove,int PixelYMove)
{

}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::FondoImageMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
if(ImagePegarSeleccion->Tag!=0){
Cursor = TCursor(crSize);
PixelXMove=X-Image->Left;
PixelYMove=Y-Image->Top;
PegarSeleccionComo(PixelXMove,PixelYMove);
}
else if(ImagePegarSeleccion->Tag==0){Cursor = TCursor(crDefault);}
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::FondoImageDblClick(TObject *Sender)
{
if(ImagePegarSeleccion->Tag!=0){
ImagePegarSeleccion->Tag=0;
Cursor = TCursor(crDefault);
}
}
//---------------------------------------------------------------------------






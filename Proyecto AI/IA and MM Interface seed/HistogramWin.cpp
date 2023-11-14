//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HistogramWin.h"
#include "ChildWin.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "CGAUGES"

//#pragma link "SUIImagePanel"

#pragma resource "*.dfm"
THistogramForm *HistogramForm;
//---------------------------------------------------------------------------
__fastcall THistogramForm::THistogramForm(TComponent* Owner)
        : TForm(Owner)
{
   // pChild=MDIChildp;

//Muestra imagen
}

//---------------------------------------------------------------------------

// Funcion que convierte la una coordena de planos a coordenadas de pantalla
void THistogramForm::conver(float x, float y, float a,            float b,        float ymax,     float ymin,      int *xpc,   int *ypc    )
                  //              |        |        |                   |                  |               |              |          |
                   //           pos X   pos Y    limite izquierdo    limite derecho  limite superior limite inferior  pos de PC-X pos de PC-Y
{
    if(!(b-a)==0 && !(ymax-ymin)==0){
    *xpc=(int)(0 -((x-a)/(b-a)*(0-(0+Grafica->Width))));
    *ypc=(int)((Grafica->Height)-((y-ymin)/(ymax-ymin))*(Grafica->Height)); }
}

//---------------------------------------------------------------------------

void THistogramForm::deconver(int *x,int *y, float a,            float b,        float ymax,     float ymin,      int xpc,   int ypc    )
{
*x=(int)(xpc*255)/(Grafica->Width);
//*y=(int)(ypc*ymax)/(Grafica->Height);
}
//---------------------------------------------------------------------------


// Funcion que dibuja los histogramas
void THistogramForm::Dibuja()
{
int xpc,ypc;
unsigned int vmax=0;
Grafica->Canvas->Brush->Color=clLtGray;
Grafica->Canvas->FillRect(Rect(0,0,Grafica->Width,Grafica->Height));
old.x=-1;
old.y=-1;
if(Red->State==cbChecked)
        vmax=(vmax<vmaxR)?vmaxR:vmax;
if(Green->State==cbChecked)
        vmax=(vmax<vmaxG)?vmaxG:vmax;
if(Blue->State==cbChecked)
        vmax=(vmax<vmaxB)?vmaxB:vmax;
if(Luminosity->State==cbChecked)
        vmax=(vmax<vmaxL)?vmaxL:vmax;


vmax=((vmax*100)/StrToInt(Zoom->Text));
Grafica->Canvas->Pen->Mode=oldPenMode;
/********RETICULA****************************/
if(vmax!=0)
{
        Grafica->Canvas->Pen->Color=clWhite;
        Grafica->Canvas->Pen->Style=psDot;
        float r;
        for(int i=1; i<256; i++)
        {
        r=i%10;
         if(r==0)
         {
          Grafica->Canvas->MoveTo((i*2)+1,0);
          Grafica->Canvas->LineTo((i*2)+1,Grafica->Height);
         }
        }
          conver(0,((vmax*4)/4),0,256,vmax,0,&xpc,&ypc);
          Grafica->Canvas->MoveTo(0,ypc);
          Grafica->Canvas->LineTo(Grafica->Width,ypc);
          LV44->Caption=IntToStr(vmax);
          conver(0,((vmax*3)/4),0,256,vmax,0,&xpc,&ypc);
          Grafica->Canvas->MoveTo(0,ypc);
          Grafica->Canvas->LineTo(Grafica->Width,ypc);
          LV34->Caption=IntToStr((vmax*3)/4);
          conver(0,((vmax*2)/4),0,256,vmax,0,&xpc,&ypc);
          Grafica->Canvas->MoveTo(0,ypc);
          Grafica->Canvas->LineTo(Grafica->Width,ypc);
          LV24->Caption=IntToStr((vmax*2)/4);
          conver(0,((vmax*1)/4),0,256,vmax,0,&xpc,&ypc);
          Grafica->Canvas->MoveTo(0,ypc);
          Grafica->Canvas->LineTo(Grafica->Width,ypc);
          LV14->Caption=IntToStr((vmax*1)/4);
Grafica->Canvas->Pen->Style=psSolid;
}
/*************************************************/


///***************  Dibuja el Histograma para Rojo
if(Red->State==cbChecked){
 conver(0,0,0,256,vmax,0,&xpc,&ypc);
 Grafica->Canvas->MoveTo(xpc,ypc);
 Grafica->Canvas->Pen->Color=clRed;

  for(int i=0; i<256; i++)
  {
   conver(i,pChild->Histo.R[i],0,256,vmax,0,&xpc,&ypc);
   Grafica->Canvas->LineTo(xpc,ypc);
   Grafica->Canvas->LineTo(xpc+1,ypc);
  }

 VMaxR->Caption=IntToStr(vmaxR);
 MedianR->Caption=IntToStr(pChild->Histo.medianaR);
 WAR->Caption = FloatToStrF(pChild->Histo.media_ponderadaR,(TFloatFormat)2,5,2);
 PixelsB->Caption=IntToStr(pChild->Histo.PixelsB);
 LRed->Visible=true;
 CountR->Visible=true;
 CGaugeR->Visible=true;
 PerRed->Visible=true;
 CGaugeR->MaxValue=(float)pChild->Histo.PixelsR;

 //PerRed->Caption = FloatToStrF(pChild->Histo.PixelsR,2,5,2);

}
else
{
 VMaxR->Caption="";
 MedianR->Caption="";
 WAR->Caption = "";
 PixelsB->Caption=IntToStr(pChild->Histo.PixelsB);
 LRed->Visible=false;
 CountR->Visible=false;
 CGaugeR->Visible=false;
 PerRed->Visible=false;

}

///***************  Dibuja el Histograma para Verde
if(Green->State==cbChecked){
 conver(0,0,0,256,vmax,0,&xpc,&ypc);
 Grafica->Canvas->MoveTo(xpc,ypc);
 Grafica->Canvas->Pen->Color=clGreen;
  for(int i=0; i<256; i++)
  {
   conver(i,pChild->Histo.G[i],0,256,vmax,0,&xpc,&ypc);
   Grafica->Canvas->LineTo(xpc,ypc);
   Grafica->Canvas->LineTo(xpc+1,ypc);
  }
 VMaxG->Caption=IntToStr(vmaxG);
 MedianG->Caption=IntToStr(pChild->Histo.medianaG);
 WAG->Caption = FloatToStrF(pChild->Histo.media_ponderadaG,(TFloatFormat)2,5,2);
 PixelsB->Caption=IntToStr(pChild->Histo.PixelsB);
 LGreen->Visible=true;
 CountG->Visible=true;
 CGaugeG->Visible=true;
 PerGreen->Visible=true;
 CGaugeG->MaxValue=(float)pChild->Histo.PixelsG;

}
else
{
 VMaxG->Caption="";
 MedianG->Caption="";
 WAG->Caption = "";
 LGreen->Visible=false;
 CountG->Visible=false;
 CGaugeG->Visible=false;
 PerGreen->Visible=false;
}
///***************  Dibuja el Histograma para Azul
if(Blue->State==cbChecked){
 conver(0,0,0,256,vmax,0,&xpc,&ypc);
 Grafica->Canvas->MoveTo(xpc,ypc);
 Grafica->Canvas->Pen->Color=clBlue;
  for(int i=0; i<256; i++)
  {
   conver(i,pChild->Histo.B[i],0,256,vmax,0,&xpc,&ypc);
   Grafica->Canvas->LineTo(xpc,ypc);
   Grafica->Canvas->LineTo(xpc+1,ypc);
  }
 VMaxB->Caption=IntToStr(vmaxB);
 MedianB->Caption=IntToStr(pChild->Histo.medianaB);
     WAB->Caption = FloatToStrF(pChild->Histo.media_ponderadaB,(TFloatFormat)2,5,2);
 PixelsB->Caption=IntToStr(pChild->Histo.PixelsB);
 LBlue->Visible=true;
 CountB->Visible=true;
 CGaugeB->Visible=true;
 PerBlue->Visible=true;
 CGaugeB->MaxValue=(float)pChild->Histo.PixelsB;

}
else
{
 VMaxB->Caption="";
 MedianB->Caption="";
   WAB->Caption = "";
 //PixelsB->Caption="";
 LBlue->Visible=false;
 CountB->Visible=false;
 CGaugeB->Visible=false;
 PerBlue->Visible=false;
}

///***************  Dibuja el Histograma para Luminancia
if(Luminosity->State==cbChecked){
 conver(0,0,0,256,vmax,0,&xpc,&ypc);
 Grafica->Canvas->MoveTo(xpc,ypc);
 Grafica->Canvas->Pen->Color=clBlack;
  for(int i=0; i<256; i++)
  {
   conver(i,pChild->Histo.L[i],0,256,vmax,0,&xpc,&ypc);
   Grafica->Canvas->LineTo(xpc,ypc);
   Grafica->Canvas->LineTo(xpc+1,ypc);
  }
 VMaxL->Caption=IntToStr(vmaxL);
 MedianL->Caption=IntToStr(pChild->Histo.medianaL);
 StdDevL->Caption=IntToStr(pChild->Histo.media_ponderadaL);
 WAL->Caption = FloatToStrF(pChild->Histo.media_ponderadaL,(TFloatFormat)2,5,2);
 PixelsB->Caption=IntToStr(pChild->Histo.PixelsB);
 LLuminosity->Visible=true;
 //LevelL->Visible=true;
 CountL->Visible=true;
 //ImageL->Visible=true;
 CGaugeL->Visible=true;
 PerL->Visible=true;
 CGaugeL->MaxValue=pChild->Histo.PixelsL;

}
else
{
 VMaxL->Caption="";
 MedianL->Caption="";
 WAL->Caption = "";
 LLuminosity->Visible=false;
 CountL->Visible=false;
 CGaugeL->Visible=false;
 PerL->Visible=false;
}










}
// ***** Funcion que dibuja los datos cuando se mueve el mouse
void THistogramForm::DibujaDatos(int X,int Y)
{
int x;
float sumR=0,sumG=0,sumB=0,sumL=0;
deconver(&x,NULL,0,256,0,0,X+1,0);
LevelL->Caption=IntToStr(x);

CountL->Caption=IntToStr(pChild->Histo.L[x]);
CountR->Caption=IntToStr(pChild->Histo.R[x]);
CountG->Caption=IntToStr(pChild->Histo.G[x]);
CountB->Caption=IntToStr(pChild->Histo.B[x]);

ImageL->Canvas->Brush->Color=(TColor)RGB(x,x,x);
ImageL->Canvas->FillRect(Rect(0,0,ImageL->Width,ImageL->Height));
Grafica->Canvas->Pen->Color=clBlack;
Grafica->Canvas->Pen->Mode=pmNotXor;
Grafica->Canvas->MoveTo(old.x,0);
Grafica->Canvas->LineTo(old.x,Grafica->Height);
Grafica->Canvas->MoveTo(0,old.y);
Grafica->Canvas->LineTo(Grafica->Width,old.y);
Grafica->Canvas->Pen->Mode=pmNotXor;
old.x=X;
old.y=Y;
Grafica->Canvas->MoveTo(X,0);
Grafica->Canvas->LineTo(X,Grafica->Height);
Grafica->Canvas->MoveTo(0,Y);
Grafica->Canvas->LineTo(Grafica->Width,Y);

for(int i=0; i<=x; i++)
{
sumR=sumR+pChild->Histo.R[i];
sumG=sumG+pChild->Histo.G[i];
sumB=sumB+pChild->Histo.B[i];
sumL=sumL+pChild->Histo.L[i];
}
CGaugeR->Progress= (float)sumR;
PerRed->Caption = FloatToStrF(100*(sumR/CGaugeR->MaxValue),(TFloatFormat)2,5,4);
CGaugeG->Progress=(float)sumG;
PerGreen->Caption = FloatToStrF(100*(sumG/CGaugeG->MaxValue),(TFloatFormat)2,5,4);
CGaugeB->Progress=(float)sumB;
PerBlue->Caption = FloatToStrF(100*(sumB/CGaugeB->MaxValue),(TFloatFormat)2,5,4);
CGaugeL->Progress=(float)sumL;
PerL->Caption = FloatToStrF(100*(sumL/CGaugeL->MaxValue),(TFloatFormat)2,5,4);

}

void __fastcall THistogramForm::RedClick(TObject *Sender)
{
Dibuja();
}
//---------------------------------------------------------------------------

void __fastcall THistogramForm::GraficaMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
if(pChild!=NULL){
DibujaDatos(X,Y);
}
}
//---------------------------------------------------------------------------

void __fastcall THistogramForm::ZoomChange(TObject *Sender)
{
if(pChild!=NULL){
Dibuja();
}
}
//---------------------------------------------------------------------------
void __fastcall THistogramForm::ImageHistoClick(TObject *Sender)
{
ImageHisto->Picture->Bitmap;
}
//---------------------------------------------------------------------------


void __fastcall THistogramForm::OnDestroy(TObject *Sender)
{
MainForm->Histo = false;
}

//---------------------------------------------------------------------------

void THistogramForm::NuevoHist()
{
    old.x = -1;
    old.y = -1;
    oldPenMode=Grafica->Canvas->Pen->Mode;

    pChild->CrearHistograma();

    CountR->Caption="";CountG->Caption="";CountB->Caption="";CountL->Caption="";
    vmaxL=0;vmaxR=0;vmaxG=0;vmaxB=0;
    for(int i=0; i<256; i++)  {
        if(vmaxL<pChild->Histo.L[i]) vmaxL=pChild->Histo.L[i];
        if(vmaxR<pChild->Histo.R[i]) vmaxR=pChild->Histo.R[i];
        if(vmaxG<pChild->Histo.G[i]) vmaxG=pChild->Histo.G[i];
        if(vmaxB<pChild->Histo.B[i]) vmaxB=pChild->Histo.B[i];
    }
    vminL=0;vminR=0;vminG=0;vminB=0;
    for(int i=0; i<256; i++)  {
        vminL=((pChild->Histo.L[i]<pChild->Histo.L[i+1]))?pChild->Histo.L[i]:vminL;
    }
    //Zoom->ItemIndex=2;
    Dibuja();
//Dibuja la imagen activa en el histograma
    TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
    String name="Histogram="+ExtractFileName(Child->FileName);
    HistogramForm->Caption=name;
    //ImageHisto->Picture->Bitmap=MainForm->ImgPrinc->Picture->Bitmap;
    //Propie();
    ImageHisto->Picture->Bitmap->Assign(Child->Image->Picture->Bitmap);
    height->Caption=Child->Image->Picture->Bitmap->Height; // Image->Name;
    width->Caption=Child->Image->Picture->Bitmap->Width;
    pixelformat->Caption= IntToStr(Child->Image->Picture->Bitmap->PixelFormat * 4) + " Bits/Pixel";
   // ImageHisto->Hint=Child->FileName;
   if(MainForm->getType(Child->ActiveBitmap())=="Gray"){
    ImagenGris();
   }
   else{ImagenNoGris();}
}
//---------------------------------------------------------------------------
void THistogramForm::ImagenGris()
{



}
//---------------------------------------------------------------------------
void THistogramForm::ImagenNoGris()
{


}
//---------------------------------------------------------------------------
void __fastcall THistogramForm::GraficaClick(TObject *Sender)
{
if(pChild!=NULL){
Zoom->SetFocus();
A=StrToInt(LevelL->Caption);
B=StrToInt(LevelL->Caption);
}
}
//---------------------------------------------------------------------------



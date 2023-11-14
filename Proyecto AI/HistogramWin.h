//---------------------------------------------------------------------------

#ifndef HistogramWinH
#define HistogramWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <math.h>
#include <conio.h>
#include <Grids.hpp>
#include "ChildWin.h"
#include "CGAUGES.h"
#include "Main.h"
#include <Menus.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>

//#include "SUIImagePanel.hpp"

//---------------------------------------------------------------------------
class THistogramForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *CountR;
        TLabel *VMaxR;
        TLabel *MedianR;
        TLabel *CountG;
        TLabel *VMaxG;
        TLabel *MedianG;
        TLabel *CountB;
        TLabel *VMaxB;
        TLabel *MedianB;
        TLabel *CountL;
        TLabel *VMaxL;
        TLabel *MedianL;
        TLabel *LRed;
        TLabel *Label10;
        TLabel *LGreen;
        TLabel *LBlue;
        TLabel *LLuminosity;
        TGroupBox *GroupBox3;
        TCheckBox *Red;
        TCheckBox *Green;
        TCheckBox *Blue;
        TCheckBox *Luminosity;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TImage *Grafica;
        TLabel *LV44;
        TLabel *LV24;
        TLabel *LV34;
        TLabel *LV14;
        TComboBox *Zoom;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label4;
        TCGauge *CGaugeR;
        TCGauge *CGaugeG;
        TCGauge *CGaugeB;
        TCGauge *CGaugeL;
        TImage *ImageHisto;
        TPopupMenu *PopupMenu1;
        TMenuItem *ImageProp;
        TPanel *Propiedades;
        TLabel *width;
        TLabel *height;
        TLabel *pixelformat;
        TLabel *Width_;
        TLabel *Height_;
        TLabel *Pixel_Format_;
        TGroupBox *GroupBox2;
        TLabel *Label40;
        TLabel *Label1;
        TLabel *LevelL;
        TImage *ImageL;
        TLabel *Label6;
        TLabel *StdDevL;
        TLabel *PixelsB;
        TLabel *Label7;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *WAR;
        TLabel *WAG;
        TLabel *WAB;
        TLabel *WAL;
        TLabel *PerRed;
        TLabel *PerGreen;
        TLabel *PerBlue;
        TLabel *PerL;
        void __fastcall RedClick(TObject *Sender);
        void __fastcall GraficaMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall ZoomChange(TObject *Sender);
        void __fastcall ImageHistoClick(TObject *Sender);
        void __fastcall OnDestroy(TObject *Sender);
        void __fastcall GraficaClick(TObject *Sender);
private:
public:
        TMDIChild *pChild;
        long unsigned vmaxL ;		// User declarations
        long unsigned vmaxR ;
        long unsigned vmaxG ;
        long unsigned vmaxB ;
        long unsigned vminL ;
        long unsigned vminR ;
        long unsigned vminG ;
        long unsigned vminB ;
        TPoint old;
        TPenMode oldPenMode;
        __fastcall THistogramForm(TComponent* Owner);
        void conver(float x, float y, float a,float b,float ymax,float ymin,int *xpc,int *ypc);
        void deconver(int *x,int *y, float a,float b, float ymax,float ymin,int  xpc,int  ypc);
        void Dibuja();
        void DibujaDatos(int X,int Y);
        void NuevoHist();
        void ImagenGris();
        void ImagenNoGris();
        int A;
        int B;

protected:
};
//---------------------------------------------------------------------------
extern PACKAGE THistogramForm *HistogramForm;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <math.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <jpeg.hpp>
#include <Inifiles.hpp>
#include <clipbrd.hpp>
#include <stdio.h>
#include <Graphics.hpp>
#include <vcl\Graphics.hpp>
#include "ChildWin.h"
#include "ProcImg.h"
#include "Outlook_2K_SRVR.h"
#define XDIM 2048
#define YDIM 2048

//---------------------------------------------------------------------------
//TForm* actual;
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MenuPrincipal;
        TMenuItem *MFile;
        TMenuItem *MFOpen;
        TMenuItem *MFSaveAs;
        TMenuItem *MFExit;
        TMenuItem *MEdit;
        TMenuItem *MTools;
        TMenuItem *MWindow;
        TMenuItem *MWCascade;
        TMenuItem *MWTileVertically;
        TMenuItem *MHelp;
        TMenuItem *MHAbout;
        TImageList *ImageList1;
        TStatusBar *StatusBar;
        TOpenPictureDialog *OpenDialog;
        TMenuItem *MWTileHorizontally;
        TActionList *ActualizaORepetir;
        TAction *FileNew;
        TAction *FileOpen;
        TWindowClose *FileClose;
        TAction *FileSave;
        TAction *FileSaveAs;
        TAction *FileExit;
        TEditCut *EditCut;
        TWindowCascade *WindowCascade;
        TWindowTileHorizontal *WindowTileHorizontal;
        TWindowTileVertical *WindowTileVertical;
        TAction *FileSaveAll;
        TAction *FileCloseAll;
        TAction *EditUndo;
        TAction *EditRedo;
        TAction *FilePrint;
        TSavePictureDialog *SaveDialog;
        TMenuItem *MImage;
        TMenuItem *MView;
        TAction *Brightness;
        TMenuItem *MIHistogram;
        TAction *Histogram;
        TAction *SplitRGB;
        TAction *InvertUmbral;
        TAction *RevertUmbral;
        TAction *InvertStatic;
        TAction *RevertStatic;
        TAction *SplitBlueGreen;
        TToolBar *TBFile;
        TToolButton *ToolButtonOpen;
        TToolButton *ToolButtonSave;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonCascade;
        TToolButton *ToolButtonHorizontally;
        TToolButton *ToolButtonVertically;
        TToolButton *ToolButtonHistogramView;
        TMenuItem *MWDuplicate;
        TAction *DuplicaImage;
        TAction *Properties;
        TMenuItem *MIArthmeticOperations;
        TMenuItem *MILogicalOperations;
        TAction *SplitGray;
        TMenuItem *MCGAveraged;
        TMenuItem *MCGrayscale;
        TAction *SplitG2;
        TMenuItem *MIResolution;
        TMenuItem *MIRSpace;
        TMenuItem *MIRColor;
        TMenuItem *MCNegative;
        TToolButton *ToolButtonCloseAll;
        TMenuItem *MColor;
        TMenuItem *MCHStretching;
        TMenuItem *MFReopen;
        TMenuItem *MFClose;
        TMenuItem *MFCloseAll;
        TMenuItem *MFCloseNoActive;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *MVNormalize;
        TToolButton *ToolButton19;
        TMenuItem *N14;
        TMenuItem *MCHistogramFunctions;
        TMenuItem *MWCloseAll;
        TMenuItem *N19;
        TMenuItem *MMorphology;
        TMenuItem *MMStructureElement;
        TMenuItem *N7;
        TMenuItem *MMBasicOperators;
        TMenuItem *MMFilters;
        TMenuItem *MMContrastEnhancement;
        TMenuItem *MMBODilation;
        TMenuItem *MMBOErosion;
        TMenuItem *N20;
        TMenuItem *MMBOOpening;
        TMenuItem *MMBOClosing;
        TMenuItem *N22;
        TMenuItem *MMBOTopHat;
        TMenuItem *MMBOBotHat;
        TMenuItem *MMFInternalBoundary;
        TMenuItem *MMFExternalBoundary;
        TMenuItem *MMFMorphologicalGradient;
        TMenuItem *N23;
        TMenuItem *MMFOpenClose;
        TMenuItem *MMFCloseOpen;
        TMenuItem *MMFOpenCloseOpen;
        TMenuItem *MMFCloseOpenClose;
        TMenuItem *MMGeodesic;
        TMenuItem *MMGErosion;
        TMenuItem *MMGDilation;
        TMenuItem *MMReconstruction;
        TMenuItem *MMRDilation;
        TMenuItem *MMRErosion;
        TAction *FilePageSetup;
        TAction *FilePrintPreview;
        TAction *CommandHistory;
        TAction *FileSaveCopyAs;
        TAction *Clear;
        TAction *EmptyClipboard;
        TAction *AsNewImage;
        TMenuItem *MVZoom;
        TMenuItem *N30;
        TMenuItem *MMROpening;
        TMenuItem *MMRClosing;
        TMenuItem *N32;
        TMenuItem *MMRWhiteTopHat;
        TMenuItem *MMRBlackTopHat;
        TToolButton *ToolButton1;
        TAction *FileCloseNoActive;
        TAction *EditCopy;
        TToolButton *ToolButton5;
        TAction *AsaNewSelection;
        TAction *AsTransparentSelection;
        TAction *AsDimSelection;
        TMenuItem *Weighted21;
        void __fastcall MHAboutClick(TObject *Sender);
        void __fastcall FileOpenExecute(TObject *Sender);
        void __fastcall FileExitExecute(TObject *Sender);
        void __fastcall FileCloseAllExecute(TObject *Sender);
        void __fastcall FileCloseAllUpdate(TObject *Sender);
        void __fastcall FileSaveAsExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ReopenFile(TObject * Sender);
        void __fastcall HistogramExecute(TObject *Sender);
        void __fastcall DuplicateExecute(TObject *Sender);
        void __fastcall SplitGrayExecute(TObject *Sender);
        void __fastcall MIRSpaceClick(TObject *Sender);
        void __fastcall MIRColorClick(TObject *Sender);
        void __fastcall MVNormalizeClick(TObject *Sender);
        void __fastcall MMStructureElementClick(TObject *Sender);
        void __fastcall MMBODilationClick(TObject *Sender);
        void __fastcall MMBOErosionClick(TObject *Sender);
        void __fastcall MMBOOpeningClick(TObject *Sender);
        void __fastcall MMBOClosingClick(TObject *Sender);
        void __fastcall MMBOTopHatClick(TObject *Sender);
        void __fastcall MMBOBotHatClick(TObject *Sender);
        void __fastcall MMContrastEnhancementClick(TObject *Sender);
        void __fastcall MMGErosionClick(TObject *Sender);
        void __fastcall MMGDilationClick(TObject *Sender);
        void __fastcall MMRDilationClick(TObject *Sender);
        void __fastcall MMRErosionClick(TObject *Sender);
        void __fastcall ZoomIn1Click(TObject *Sender);
        void __fastcall MMROpeningClick(TObject *Sender);
        void __fastcall MMRClosingClick(TObject *Sender);
        void __fastcall MMRWhiteTopHatClick(TObject *Sender);
        void __fastcall MMRBlackTopHatClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall MCNegativeClick(TObject *Sender);
        void __fastcall MCHStretchingClick(TObject *Sender);
        void __fastcall FileCloseNoActiveExecute(TObject *Sender);
        void __fastcall MILogicalOperationsClick(TObject *Sender);
        void __fastcall MIArthmeticOperationsClick(TObject *Sender);
        void __fastcall ActualizarMainFormUpdate(TObject *Sender);
        void __fastcall ToolButtonGlassesClick(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormDblClick(TObject *Sender);
        void __fastcall MCGWeightedClick(TObject *Sender);
        void __fastcall Weighted21Click(TObject *Sender);
private:
        String dirApplication;
        MyLUT Original[256];
       // AssingImage4(bmp);
public:
        void FunSequentialThinning();
        int ImageForPage;
//        Imagen *imagenx;
        Variant nombrecomando;
        Variant arregloUndoRedo[20];
        void Undo();
        void Redo();
        void UndoUpdate();
        void RedoUpdate();
        int PrinterSelect;
        Graphics::TBitmap *Bitmap;
        RECT margenes;
        int ancho;
        int alto;
        AnsiString CurrentFile;
        bool Histo;
        bool Graphics;
        bool AdaptiveForm;
        TProcImg *Pdi;


  TMDIChild *hija;
  Graphics::TBitmap* entrada;
  Graphics::TBitmap* auxiliar;
  Graphics::TBitmap* param1;
  Graphics::TBitmap* param2;
  Graphics::TBitmap* auxiliar2;
  Graphics::TBitmap* bmpAux;
  Graphics::TBitmap* previo;
  Graphics::TBitmap* actual2;
  Graphics::TBitmap* resta;
  int venthM;
  int venthm;
         TMDIChild* Plano[8];
         void SaveFile(String name);
         TMDIChild* CreateMDIChild(String Name,Graphics::TBitmap *pBitmap);
         // Para la normalizacion
         void histoR(Graphics::TBitmap*imag,float res[256]);
         Graphics::TBitmap* greenPlane(Graphics::TBitmap* input);
         Graphics::TBitmap* redPlane(Graphics::TBitmap* input);
         Graphics::TBitmap* bluePlane(Graphics::TBitmap* input);
         int Redondea (float r);
         int RedondeaPositivos(double numero);
         __fastcall TMainForm(TComponent* Owner);
         AnsiString getType(Graphics::TBitmap* bit);
        // void Thresholding(TObject *Sender);
         void OKLabeling();
         void UpdateLabeling();
         TMemoryStream* pms;
         void AgregarAnalisisReporte(TMDIChild *Child,TMDIChild *Child2,String proceso);
         TColor TransparentColorA;
         TColor TransparentColorB;
         String TransparentRango;
         void EqualizacionHistograma(TMDIChild *Child,Graphics::TBitmap* pBitmap);
         void ObtenerMediaDesvEst(Graphics::TBitmap  *Bitmap,int mediaA, int mediaV, int mediaR,
                                        Extended DesvEstA, Extended DesvEstV, Extended DesvEstR );
};

//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
extern TMDIChild *__fastcall MDIChildCreate(void);
//---------------------------------------------------------------------------
#endif

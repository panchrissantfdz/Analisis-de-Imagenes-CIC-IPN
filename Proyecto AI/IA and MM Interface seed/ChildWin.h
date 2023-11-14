//---------------------------------------------------------------------------

#ifndef ChildWinH
#define ChildWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>

#include <string.h>
#include <Graphics.hpp>
struct Histograma{
         long unsigned R[256]; // Pixeles Rojos
         long unsigned G[256]; // Pixeles Verdes
         long unsigned B[256]; // Pixeles Azules
         long unsigned L[256]; // Pixeles de Luminosidad
         int medianaR;       // Media Rojo
         int media_ponderadaR; //Media Ponderada Rojo
         int medianaG;       // Media Rojo
         int media_ponderadaG; //Media Ponderada Rojo
         int medianaB;       // Media Rojo
         int media_ponderadaB; //Media Ponderada Rojo
         int medianaL;       // Media Rojo
         int media_ponderadaL; //Media Ponderada Rojo
         long unsigned PixelsL;
         long unsigned PixelsR;
         long unsigned PixelsG;
         long unsigned PixelsB;
        };
typedef int MyLUT;

//---------------------------------------------------------------------------
class TMDIChild : public TForm
{
__published:	// IDE-managed Components
        TImage *Image;
        TPopupMenu *PopupMenu1;
        TMenuItem *CIHistogram;
        TMenuItem *CEdit;
        TMenuItem *CImage;
        TMenuItem *CIDuplicate;
        TMenuItem *CFile;
        TMenuItem *CFSaveas;
        TImage *ImageSearchPixel;
        TImage *FondoImage;
        TImage *ImageFondo;
        TImage *ImagePegarSeleccion;
        TImage *ImageRespaldo;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ImageMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall CIHistogramClick(TObject *Sender);
        void __fastcall ImageClick(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall ImageMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall CFSaveasClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall CVReportoftheprocessedimageClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FondoImageMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall FondoImageDblClick(TObject *Sender);
private:	// User declarations
        int Tope_temporal;
        int Bandera_Undo;
        int MAX;
        Graphics::TBitmap *Arr[20]; // Buffer para guardar las acciones sobre la imagen MAXIMO DE 20
        TForm *Ligadas[20];
        int indexFormas;
        void __fastcall DrawShapeRec(int X, int Y);
        void __fastcall DrawShapeSqu(int X, int Y);
        void __fastcall DrawShapeCir(int X, int Y);
        TImage *TmpImage;
        int InitialX;
        int InitialY;

public:
        TRect bounds;
        TRect boundsSelection;
        int Tope;
        int index;                  // Indice de la accion de la imagen
        String PixelFormatDepthColor;
        String FileName;
        String NombreComando;
        int ConteoProcesos;
        TRichEdit *ReportProcessedImageChild;
        AnsiString Tipo;
        int LUT[256];
        Histograma Histo;
        TPicture *dibujo;
//        TCountColors *formDatos;

         int left, right, top, bottom;
     __fastcall TMDIChild(TComponent* Owner);
        bool cImage(Graphics::TBitmap *clip);
        bool cImageUndo();
        bool cImageRedo();
        bool isDo();
        bool isRedo();
        Graphics::TBitmap * ActiveBitmap();
        void cImageRefresh();
        void CrearHistograma();
        void SetForma(TForm *name);
        Variant matriz[20];
        Variant matrizFileName[20];

        int X0,Y0,X1,Y1;
         bool mouseDown;
        bool DrawSelectRegion;
        bool RegionDib;
        bool boton;
        bool closing;
        int oX,oY,iX,iY;
        int downX,downY;
//        void cargaDireccion(TCountColors *dir);
        int PixelX;
        int PixelY;
        int PixelR;
        int PixelG;
        int PixelB;
        int PixelXMove;
        int PixelYMove;
        int PixelRMove;
        int PixelGMove;
        int PixelBMove;
        float grados;
        int D;
        int T;
        int R;
        void PegarSeleccionComo(int PixelXMove,int PixelYMove);
};


//---------------------------------------------------------------------------
extern PACKAGE TMDIChild *MDIChild;
//---------------------------------------------------------------------------
#endif


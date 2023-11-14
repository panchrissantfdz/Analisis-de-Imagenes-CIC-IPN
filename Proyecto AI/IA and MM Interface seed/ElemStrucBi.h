//---------------------------------------------------------------------------

#ifndef ElemStrucBiH
#define ElemStrucBiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>

#include "Morpho.h"
#include "StrucEE.h"
//---------------------------------------------------------------------------
//enum EEType {Sq, Rec, Cir, Ar, Sec, Rg, Ell, Diam, Cros, Equi, Poly, Irre} ;

class TFSEB : public TForm
{
__published:	// IDE-managed Components
        TImage *Imagec;
        TSaveDialog *GuardaEE;
        TImage *ImageB;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *lblcx;
        TLabel *lblcy;
        TLabel *lblSizeEE;
        TLabel *lblx;
        TLabel *lbly;
        TLabel *lblAncho;
        TLabel *lblAlto;
        TLabel *lblGrosor;
        TSpeedButton *SBLoad;
        TSpeedButton *SBSave;
        TCheckBox *chkInv;
        TLabel *Label1;
        TLabel *lblevel;
        TImage *ImgLevel;
        TButton *cmdCleanL;
        TLabel *LblRote;
        TLabel *LblStart;
        TLabel *LblEnd;
        TImage *ImgNLevel;
        TCheckBox *ChbLevel;
        TLabel *Label4;
        TLabel *lblvertice;
        TEdit *Tamval;
        TUpDown *UpDownT;
        TEdit *EditX;
        TUpDown *UpDownX;
        TEdit *EditY;
        TUpDown *UpDownY;
        TEdit *EditW;
        TUpDown *UpDownW;
        TEdit *EditH;
        TUpDown *UpDownH;
        TEdit *EditG;
        TUpDown *UpDownG;
        TEdit *EditVert;
        TUpDown *UpDownV;
        TEdit *EditS;
        TUpDown *UpDownS;
        TEdit *EditE;
        TUpDown *UpDownE;
        TEdit *EditR;
        TUpDown *UpDownR;
        TOpenDialog *Abre;
        TBevel *Bevel1;
        TSpeedButton *SBCreate;
        TSpeedButton *SBClean;
        TSpeedButton *SBFDG;
        TLabel *Label8;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TBitBtn *BitBtnOK;
        TCheckBox *CheckBoxCompositeSE;
        TRadioGroup *RadioGroupSkeletons;
        TRadioGroup *RadioGroupPruning;
        TRadioGroup *RadioGroupInsolatedpoints;
        TRadioGroup *RadioGroupCustomize;
        TLabel *LabelBackground;
        TLabel *LabelForeground;
        TGroupBox *GroupBox2;
        TRadioButton *Cuadro;
        TRadioButton *Rectangulo;
        TRadioButton *Circulo;
        TRadioButton *RadioButtonBackground;
        TRadioButton *RadioButtonForeground;
        TRadioGroup *RadioGroupEndpoints;
        TCheckBox *CheckBoxAllplanes;
        TCheckBox *CheckBoxComplement;
        void __fastcall CuadroClick(TObject *Sender);
        void __fastcall RomboClick(TObject *Sender);
        void __fastcall CruzClick(TObject *Sender);
        void __fastcall CirculoClick(TObject *Sender);
        void __fastcall AnilloClick(TObject *Sender);
        void __fastcall ElipseClick(TObject *Sender);
        void __fastcall RectanguloClick(TObject *Sender);
        void __fastcall IrregularesClick(TObject *Sender);
        void __fastcall ImageBMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall ImageBMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SBLoadClick(TObject *Sender);
        void __fastcall SBSaveClick(TObject *Sender);
        void __fastcall EquisClick(TObject *Sender);
        void __fastcall ArcoClick(TObject *Sender);
        void __fastcall SectorClick(TObject *Sender);
        void __fastcall PoligonoClick(TObject *Sender);
        void __fastcall UpDownTClick(TObject *Sender, TUDBtnType Button);
        void __fastcall TamvalChange(TObject *Sender);
        void __fastcall EditXChange(TObject *Sender);
        void __fastcall EditYChange(TObject *Sender);
        void __fastcall UpDownXClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownYClick(TObject *Sender, TUDBtnType Button);
        void __fastcall EditWChange(TObject *Sender);
        void __fastcall EditHChange(TObject *Sender);
        void __fastcall EditGChange(TObject *Sender);
        void __fastcall EditVertChange(TObject *Sender);
        void __fastcall EditSChange(TObject *Sender);
        void __fastcall EditEChange(TObject *Sender);
        void __fastcall EditRChange(TObject *Sender);
        void __fastcall UpDownWClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownHClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownVClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownGClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownSClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownEClick(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownRClick(TObject *Sender, TUDBtnType Button);
        void __fastcall ImagecMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormClickAction(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SBCreateClick(TObject *Sender);
        void __fastcall SBCleanClick(TObject *Sender);
        void __fastcall SBFDGClick(TObject *Sender);
        void __fastcall BitBtnOKClick(TObject *Sender);
        void __fastcall CheckBoxCompositeSEClick(TObject *Sender);
        void __fastcall RadioGroupSkeletonsClick(TObject *Sender);
        void __fastcall RadioGroupPruningClick(TObject *Sender);
        void __fastcall RadioGroupInsolatedpointsClick(TObject *Sender);
        void __fastcall RadioGroupCustomizeClick(TObject *Sender);
        void __fastcall RadioGroupEndpointsClick(TObject *Sender);
        void __fastcall CheckBoxAllplanesClick(TObject *Sender);
        void __fastcall CheckBoxComplementClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFSEB(TComponent* Owner);

        TMorpho *Morpho; // crea la clase morpho
        TStrEE StrEE; //crea la clase EE

        int tam,ox,oy, G, ctam,x,y,xx,yy, i, j, tamX, tamY;
        //int XX,YY; //tamaño de elipse
        int SaveX, SaveY, Start, End;
        int r,g,b;
        int cc, tamLevel, tamXX, tamYY, tamXY;
        int Grados, XX, YY;
        int stX, stY, endX, endY;
        float sX, sY, eX, eY;
        int vx,vy;
        int gx,gy; //guarda las coordenadas para la tabla de niveles de gris
        int numver,pver;//num. de vertices.
        bool f;
        int WX,HY; // el valor de altura y anchura del EE que cargamos.
        int Grado, W,H; //para la rotación
        TPoint points[8];// poly[8]; // para los poligonos

        TColor vc[15], vcc[15];//para guardar los niveles de gris

        Graphics::TBitmap *EE; // imagen que uso como EE
        Graphics::TBitmap *EEC; // imagen que uso como EE
        Graphics::TBitmap *AUXEE;
        Graphics::TBitmap *PixEEP;
        Graphics::TBitmap *PixEE;
        Graphics::TBitmap *PixEEC;
        Graphics::TBitmap * GetElem();
        void GetOri(int *, int *);
        void DrawBi(void);//DECLARACION
        void DrawBiCompositeSE(void);//DECLARACION
        void DesactivaPropiedadesEE(void);
        void ActivaPropiedadesEEC(void);
        void DrawBiDi();
        void DrawGray(void);
        void DrawGrayDi(int YY, int XX);
        void InvGray(int loop);
        void CargarEE(void);
        void Muestra();
        void RotaEE(void);
        void RotationEE(void);
        int max2(int a,int b);
        int min(int c,int d);
        int getPlane();
        int getTam();
        int getWidth();
        int getHeight();
        void DibujaEEenlasImagenes(void);
        void ComplementodeEEenlasImagenes(void);

       TPanel * panels[16][16];//tabla de niveles de gris
       inline byte Red   (TColor value){return (Byte) (value & 0xFF) ;} ;
       inline byte Blue  (TColor value){return (Byte) ((value >> 8) & 0xFF) ;} ;
       inline byte Green (TColor value){return (Byte) ((value >> 16) & 0xFF) ;} ;

       TColor currentColor ;//color actual

       AnsiString datType();
       AnsiString datH();
       AnsiString datW();
       AnsiString EEType;
};

//---------------------------------------------------------------------------
extern PACKAGE TFSEB *FSEB;
#define PI 3.1415926535897932385
//---------------------------------------------------------------------------
#endif

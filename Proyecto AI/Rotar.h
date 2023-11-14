//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include "ChildWin.h"
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <AppEvnts.hpp>
#include <ExtDlgs.hpp>
#define XDIM 2048
#define YDIM 2048
#define NValues 256 // para los valores de etiquetas 2 exp 8
#define Pmin 50 // define el número de puntos que debe tener una imagen como mínimo


/*typedef unsigned char uchar;
typedef struct tagRGBQUA
{
	 BYTE    rgbBlue;  //
	 BYTE    rgbGreen;
	 BYTE    rgbRed;
	 BYTE    rgbReserved;    // 4 * 16 = 64    118
} RGBQUA;*/

#define FAC_AMPL 8  //Factos de amplificación filtros Pasa alta y Pasa baja
				//**********************************************
				//****************  CLASE MASCARA **************
				//**********************************************
//----------------------------------------------------------------------------
class mascara
{
 private:
  int **Gx ;        //Matriz que contiene la mascara cargada
  int sx , sy ;		//sx = Size X, sy = Size Y,  de la máscara de tamaño XxY

 public:
 //CONSTRUCTORES
  mascara( int USRDEF) ;              	// MASCARA creada por el usuario
  mascara( int , int , ... ) ;  // Recibe 2 enteros del tamaño de la máscara
                                // recibe la propia máscara como lista de parámetros
 //FUNCIONALIDADES
  int filtra( int XPix , int YPix, int SegundaDerivada ) ;  //filtra recibe la posición del pixel a filtrar
  int Dilata( int XPix , int YPix ) ;  //filtra recibe la posición del pixel a filtrar
  int Erosiona( int XPix , int YPix ) ;  //filtra recibe la posición del pixel a filtrar
  mascara& operator =(const mascara &Masc);


  friend class TFormaPrincipal ;
  //friend class TFUsrDefFiltro  ;
} ;


//----------------------------------------------------------------------------
class TFormaPrincipal : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TMenuItem *WindowMinimizeItem;
        TStatusBar *StatusBar;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TImageList *ImageList1;
  TSplitter *Splitter1;
  TMenuItem *Resolusionespacial1;
  TMenuItem *Resoluciondeniveles1;
  TMenuItem *N7bits1;
  TMenuItem *N6bits1;
  TMenuItem *N5bits1;
  TMenuItem *N4bits1;
  TMenuItem *N3bits1;
  TMenuItem *N2bits1;
  TMenuItem *N1bit1;
  TMenuItem *Aumentar1;
  TMenuItem *Disminuir1;
  TMenuItem *N121;
  TMenuItem *N141;
  TMenuItem *N181;
  TMenuItem *N211;
  TMenuItem *N411;
  TMenuItem *N811;
  TSaveDialog *SaveDialog1;
  TMenuItem *Herramientas1;
  TMenuItem *Histograma1;
  TMenuItem *Ensancharhistograma1;
  TMenuItem *FileSaveItem;
  TMenuItem *Zoom1;
  TMenuItem *Interpolacionbilineal1;
  TMenuItem *Interpolacionbicubica1;
  TMenuItem *Reconocimientodecaracteres1;
  TMenuItem *Correlacion1;
  TMenuItem *N122;
  TMenuItem *N142;
  TMenuItem *N123;
  TMenuItem *N143;
  TMenuItem *CorrelacionMedia1;
  TMenuItem *Aumentar2;
  TMenuItem *Disminueir1;
  TMenuItem *Aumentar3;
  TMenuItem *Disminuir2;
  TMenuItem *N182;
  TMenuItem *N183;
  TMenuItem *Convertiranivelesdegris1;
  TMenuItem *Mejoramiento1;
  TMenuItem *Binarizacion1;
  TMenuItem *Manual1;
  TMenuItem *Automatica1;
  TMenuItem *Histograma2;
  TMenuItem *Ensanchar1;
  TMenuItem *Equalizacion1;
  TMenuItem *Operacionesaritmeticas1;
  TMenuItem *Adicion1;
  TMenuItem *Substraccion1;
  TMenuItem *Operacioneslogicas1;
  TMenuItem *And1;
  TMenuItem *Or1;
  TMenuItem *Xor1;
  TMenuItem *Not1;
  TToolButton *ToolButton2;
  TMenuItem *DescomponerentresplanosRGB1;
  TMenuItem *N212;
  TMenuItem *N412;
  TMenuItem *N812;
  TMenuItem *N21;
  TMenuItem *N413;
  TMenuItem *N813;
  TMenuItem *MejoramientoEspacial1;
  TMenuItem *Media1;
  TMenuItem *Suavizantes1;
  TMenuItem *Realzantes1;
  TMenuItem *PasaBajas1;
  TMenuItem *N2;
  TMenuItem *Gausiano1;
  TMenuItem *LaPlaciano1;
  TMenuItem *LaplacianodelGausiano1;
  TMenuItem *PasaAltas1;
  TMenuItem *HighBoots1;
  TMenuItem *N3;
  TMenuItem *OperadorRobers1;
  TMenuItem *OperadorSobel1;
  TMenuItem *OperadorPrewitt1;
  TMenuItem *N4;
  TMenuItem *Conteodeobjetos1;
  TMenuItem *Histogramaimagenesencolor1;
  TMenuItem *Normalizar1;
  TMenuItem *GenerarMascara1;
  TMenuItem *DefinirMascara1;
  TMenuItem *AplicarMascara1;
  TMenuItem *OperacionesMorfologicas1;
  TMenuItem *Dilatacion1;
  TMenuItem *Erosion1;
  TMenuItem *Apertura1;
  TMenuItem *Cierre1;
  TMenuItem *Invertir1;
  TMenuItem *FiltrosAlternantes1;
  TMenuItem *FiltrosAlternantesSecuenciales1;
  TMenuItem *AF11;
  TMenuItem *AF21;
  TMenuItem *AF31;
  TMenuItem *AF41;
  TMenuItem *ASF11;
  TMenuItem *ASF21;
  TMenuItem *ASF31;
  TMenuItem *ASF41;
  TMenuItem *ASF51;
  TMenuItem *ASF61;
  TMenuItem *ASF71;
  TMenuItem *ASF81;
  TMenuItem *RotarImagen1;
  TMenuItem *FiltrosdeCombinacionesIterativas1;
  TMenuItem *Cierre2;
  TMenuItem *C11;
  TMenuItem *AC1;
  TMenuItem *CA1;
  TMenuItem *ACA1;
  TMenuItem *CAC1;
  TOpenPictureDialog *OpenDialog;
        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileOpen1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
  void __fastcall N1bit1Click(TObject *Sender);
  void __fastcall N2bits1Click(TObject *Sender);
  void __fastcall N3bits1Click(TObject *Sender);
  void __fastcall N4bits1Click(TObject *Sender);
  void __fastcall N5bits1Click(TObject *Sender);
  void __fastcall N6bits1Click(TObject *Sender);
  void __fastcall N7bits1Click(TObject *Sender);
  void __fastcall N121Click(TObject *Sender);
  void __fastcall N141Click(TObject *Sender);
  void __fastcall N181Click(TObject *Sender);
  void __fastcall N211Click(TObject *Sender);
  void __fastcall N411Click(TObject *Sender);
  void __fastcall N811Click(TObject *Sender);
  void __fastcall Histograma1Click(TObject *Sender);
  void __fastcall Ensancharhistograma1Click(TObject *Sender);
  void __fastcall Correlacion1Click(TObject *Sender);
  void __fastcall N122Click(TObject *Sender);
  void __fastcall N142Click(TObject *Sender);
  void __fastcall N123Click(TObject *Sender);
  void __fastcall N143Click(TObject *Sender);
  void __fastcall CorrelacionMedia1Click(TObject *Sender);
  void __fastcall Comparacion1Click(TObject *Sender);
  void __fastcall N182Click(TObject *Sender);
  void __fastcall N183Click(TObject *Sender);
  void __fastcall Convertiranivelesdegris1Click(TObject *Sender);
  void __fastcall Manual1Click(TObject *Sender);
  void __fastcall Automatica1Click(TObject *Sender);
  void __fastcall Ensanchar1Click(TObject *Sender);
  void __fastcall Equalizacion1Click(TObject *Sender);
  void __fastcall Adicion1Click(TObject *Sender);
  void __fastcall Substraccion1Click(TObject *Sender);
  void __fastcall And1Click(TObject *Sender);
  void __fastcall Or1Click(TObject *Sender);
  void __fastcall Xor1Click(TObject *Sender);
 	void __fastcall UpdateMenuItems(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FileSave1Execute(TObject *Sender);
  void __fastcall DescomponerentresplanosRGB1Click(TObject *Sender);
  void __fastcall N212Click(TObject *Sender);
  void __fastcall N412Click(TObject *Sender);
  void __fastcall N812Click(TObject *Sender);
  void __fastcall N21Click(TObject *Sender);
  void __fastcall N413Click(TObject *Sender);
  void __fastcall N813Click(TObject *Sender);
  void __fastcall Not1Click(TObject *Sender);
  void __fastcall Media1Click(TObject *Sender);
  void __fastcall PasaBajas1Click(TObject *Sender);
  void __fastcall Gausiano1Click(TObject *Sender);
  void __fastcall LaPlaciano1Click(TObject *Sender);
  void __fastcall LaplacianodelGausiano1Click(TObject *Sender);
  void __fastcall PasaAltas1Click(TObject *Sender);
  void __fastcall HighBoots1Click(TObject *Sender);
  void __fastcall OperadorRobers1Click(TObject *Sender);
  void __fastcall OperadorSobel1Click(TObject *Sender);
  void __fastcall OperadorPrewitt1Click(TObject *Sender);
  void __fastcall Conteodeobjetos1Click(TObject *Sender);
  void __fastcall Histogramaimagenesencolor1Click(TObject *Sender);
  void __fastcall Normalizar1Click(TObject *Sender);
  void __fastcall DefinirMascara1Click(TObject *Sender);
  void __fastcall AplicarMascara1Click(TObject *Sender);
  void __fastcall Dilatacion1Click(TObject *Sender);
  void __fastcall Invertir1Click(TObject *Sender);
  void __fastcall Erosion1Click(TObject *Sender);
  void __fastcall Apertura1Click(TObject *Sender);
  void __fastcall Cierre1Click(TObject *Sender);
  void __fastcall AF11Click(TObject *Sender);
  void __fastcall AF21Click(TObject *Sender);
  void __fastcall AF31Click(TObject *Sender);
  void __fastcall AF41Click(TObject *Sender);
  void __fastcall ASF11Click(TObject *Sender);
  void __fastcall ASF21Click(TObject *Sender);
  void __fastcall ASF31Click(TObject *Sender);
  void __fastcall ASF41Click(TObject *Sender);
  void __fastcall ASF51Click(TObject *Sender);
  void __fastcall ASF61Click(TObject *Sender);
  void __fastcall ASF71Click(TObject *Sender);
  void __fastcall ASF81Click(TObject *Sender);
  void __fastcall RotarImagen1Click(TObject *Sender);
  void __fastcall Cierre2Click(TObject *Sender);
  void __fastcall C11Click(TObject *Sender);
  void __fastcall AC1Click(TObject *Sender);
  void __fastcall CA1Click(TObject *Sender);
  void __fastcall ACA1Click(TObject *Sender);
  void __fastcall CAC1Click(TObject *Sender);
private:
	void __fastcall CreateMDIChild(const String Name);
  byte interpola(double x, double y, byte **R);
  double C0(double f);
  double C1(double f);
      double C2(double f);
        double C3(double f);
int Etiquetas[NValues][2]; // para los valores de las etiquetas utilizadas
int Rfin; // para el número de regiones encontradas
 int n;
  public:
//uchar imgbmp[XDIM][YDIM];
uchar imgbmpr[XDIM][YDIM];



//Objetos gráficos en memoria
TPicture  *IMGBMP;//
TPicture  *IMGBMPRS;//
   byte **imgbmp;

   byte **getR(TPicture  *BMP);
   byte **getG(TPicture  *BMP);
   byte **getB(TPicture  *BMP);
   void pinta(byte **R,byte **G,byte **B,int w,int h);
   void MostrarImagen(byte **R,byte **G,byte **B,int w,int h,String Name);
   void ConvertirColorGris();

   double a;

  void AbrirImagen2();

	virtual __fastcall TFormaPrincipal(TComponent *Owner);
  void  __fastcall AjustaChild(TMDIChild *Child);
  byte ConvertirValor(byte valor,int bit);
  void ResolucionBits(int bits);

  int Bilineal(float i, float j);
  void Neiboor(double zoom);
  void InterpolacionBilineal(double zoom);
  void Bicubica(double zoom);

  void DescomponerRGB();

  void __fastcall _filtra (mascara *pG );
  void __fastcall _filtra (mascara *pX ,mascara *pY);
  void __fastcall _filtraLoG (mascara *pL ,mascara *pG);

  int __fastcall EtiquetarImagen(int ancho, int alto);
  void __fastcall EliminarFalsosObjetos(int ancho, int alto, int pmin);
  void __fastcall SeleccionarNIteraciones(void);
void __fastcall TipoImagen();
  bool esColor,esBinary,esGrayscale;

};
//----------------------------------------------------------------------------
extern TFormaPrincipal *FormaPrincipal;
extern TMDIChild *__fastcall MDIChildCreate(void);
//----------------------------------------------------------------------------
 #endif

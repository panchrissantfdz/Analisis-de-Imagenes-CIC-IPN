//---------------------------------------------------------------------------
#ifndef ProcImgH
#define ProcImgH
 //#include <algorithm.h>
//---------------------------------------------------------------------------

#include <math.h>
//#include "MaskF.h"
#include "ElemStrucBi.h"
//#include "ldd.h"

/********************************
 Clase Procesamiento de imágenes
********************************/
class TProcImg{

public:

int coordX, coordY;

//Zoom Interpolacion bilineal
void InterpolacionBilineal(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto);
void InterpolacionBicubic(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto);
double C0(double f);
double C1(double f);
double C2(double f);
double C3(double f);
byte interpola(double x, double y, byte **R,int ancho, int alto);
byte **getR(Graphics::TBitmap* BMP);
byte **getG(Graphics::TBitmap* BMP);
byte **getB(Graphics::TBitmap* BMP);
//Zoom Primeros vecinos
void NearestNeighborZoom(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float ancho,float alto);

Graphics::TBitmap * GrayLevel(Graphics::TBitmap *bmpE);
Graphics::TBitmap * Invertir(Graphics::TBitmap *bmpE);

Graphics::TBitmap * RedPlane(Graphics::TBitmap *bmpE);
Graphics::TBitmap * RedPlaneNG(Graphics::TBitmap *bmpE);
Graphics::TBitmap * GreenPlane(Graphics::TBitmap *bmpE);
Graphics::TBitmap * GreenPlaneNG(Graphics::TBitmap *bmpE);
Graphics::TBitmap * BluePlane(Graphics::TBitmap *bmpE);
Graphics::TBitmap * BluePlaneNG(Graphics::TBitmap *bmpE);

Graphics::TBitmap * Umbral(Graphics::TBitmap *bmpE,AnsiString Thres);
Graphics::TBitmap * UmbralX(int Umbral,int Resto,Graphics::TBitmap *bmpE,AnsiString Thres);
Graphics::TBitmap * UmbralBiX(int Umbral,int Resto,Graphics::TBitmap *bmpE, int T1, int T2);
Graphics::TBitmap * UmbralI(int Umbral,int Resto,Graphics::TBitmap *bmpE,AnsiString Thres);
Graphics::TBitmap * UmbralBi(Graphics::TBitmap *bmpE, int T1, int T2);
Graphics::TBitmap * UmbralBiInv(Graphics::TBitmap *bmpE, int T1, int T2);
Graphics::TBitmap * UmbralGS(Graphics::TBitmap *bmpE, int T1, int T2);
Graphics::TBitmap * UmbralGSInv(Graphics::TBitmap *bmpE, int T1, int T2);

Graphics::TBitmap * Centroide(Graphics::TBitmap *bmpE);
int Area(Graphics::TBitmap *img);

Graphics::TBitmap * Extension(Graphics::TBitmap *bmpE, int T1, int T2);

Graphics::TBitmap * Resta(Graphics::TBitmap *bmpA, Graphics::TBitmap *bmpB);
Graphics::TBitmap * Suma(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB);
Graphics::TBitmap * Multiplica(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB);
Graphics::TBitmap * Divide(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB);
Graphics::TBitmap * Intersecta(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB);
Graphics::TBitmap * Union(Graphics::TBitmap *imgA, Graphics::TBitmap *imgB);

int Scan(Graphics::TBitmap *imgF);

Graphics::TBitmap * Statistic(Graphics::TBitmap *img);

Graphics::TBitmap * LoG(Graphics::TBitmap *img);

//Graphics::TBitmap * Convolution(Graphics::TBitmap *imgO,TMaskFilter * mask);
//Graphics::TBitmap * ConvolAverage(Graphics::TBitmap *imgO,TMaskFilter * mask);

Graphics::TBitmap * Gaussian(Graphics::TBitmap *img, int size, double desv);
Graphics::TBitmap * Average(Graphics::TBitmap *img, int sizek);

Graphics::TBitmap * BrigthR(Graphics::TBitmap *bmpE, int val);
Graphics::TBitmap * BrigthS(Graphics::TBitmap *bmpE, int val);

int * Histogram(Graphics::TBitmap *bmp);
double * NormalizaHistograma(int *Hist,int W, int H);
int ThresholdOtsu(Graphics::TBitmap *bmp,double eps);

Graphics::TBitmap * Etiqueta(Graphics::TBitmap *bmp);

int** BmpToMtx(Graphics::TBitmap *bmpO); // convierte una bmp a una matriz de enteros
Graphics::TBitmap * MtxToBmp(int **bmp, Graphics::TBitmap *bmpO); // convierte una matriz de entero en una bmp

//int Bilinear(int **Image, float i, float j);

int MRThres(int *Hist);// MINIMO RELATIVO PARA OBJETOS NEGROS
int MRThresW(int *Hist); // MINIMOS RELATIVO PARA OBJETOS BLANCOS

//AnsiString CountOA(Graphics::TBitmap *imgO);
void CountOA(Graphics::TBitmap *imgO);

Graphics::TBitmap * CleanCurve(Graphics::TBitmap *imgO);

Graphics::TBitmap * MetBilinear(Graphics::TBitmap *imgO, double zoom);
int interpola(double x, double y, int **Canal, int w, int h );
int** BmpToMtxRed(Graphics::TBitmap *bmpO); // de bitmap a matriz de enteros rojos
int** BmpToMtxGreen(Graphics::TBitmap *bmpO); // de bitmap a matriz de enteros verde
int** BmpToMtxBlue(Graphics::TBitmap *bmpO); // de bitmap a matriz de enteros azul
int max1(int a,int b);
int min1(int a,int b);

//Funciones para hmin y hmax

    Graphics::TBitmap* Resh(Graphics::TBitmap*, int);
    Graphics::TBitmap* Sumh(Graphics::TBitmap*, int);
    Graphics::TBitmap* Mulh(Graphics::TBitmap*, int);
    Graphics::TBitmap* Divh(Graphics::TBitmap*, int);
    Graphics::TBitmap* RecGD(Graphics::TBitmap*, Graphics::TBitmap*);
    Graphics::TBitmap* RecGE(Graphics::TBitmap*, Graphics::TBitmap*);
    Graphics::TBitmap* Maxh(Graphics::TBitmap*, int);
    Graphics::TBitmap* Minh(Graphics::TBitmap*, int);
    Graphics::TBitmap* NGG(Graphics::TBitmap*);
    void Hist(Graphics::TBitmap*, int*, int);
    int nivMax(int*, int);
    int nivMin(int*, int);
    int* MaxR(int*, int, int);
    int* MinR(int*, int, int);
    Graphics::TBitmap* Rmax(Graphics::TBitmap*);
    Graphics::TBitmap* Rmin(Graphics::TBitmap*);
    Graphics::TBitmap* subImgs(Graphics::TBitmap*, Graphics::TBitmap*);
    Graphics::TBitmap* Emax(Graphics::TBitmap*, int);
    Graphics::TBitmap* Emin(Graphics::TBitmap*, int);
    Graphics::TBitmap* hconvex(Graphics::TBitmap*, int);
    Graphics::TBitmap* hconcave(Graphics::TBitmap*, int);
    Graphics::TBitmap* Impmin(Graphics::TBitmap*);
    Graphics::TBitmap* Impmax(Graphics::TBitmap*);
    Graphics::TBitmap* Fillhole(Graphics::TBitmap*);
    Graphics::TBitmap* QuitarObjetosBorde(Graphics::TBitmap*, int, int, int);
    Graphics::TBitmap* etiquetar(Graphics::TBitmap*, int, int, int, int&);
    int** etiquetasBorde(Graphics::TBitmap*, int, int, int);
    int** etiquetas(Graphics::TBitmap*, int, int, int);
    int objs(int**, int, int, int);
    long cantcolor(Graphics::TBitmap*, int);
    int mmax(int*, int*, int);
    int* ordena(int*, int);
    double omega(int, int, int*);
    double miu(int, int, double, int*);
    int nivotsu(Graphics::TBitmap*);
    int numtotpix(int*, int);
    void EscalarImagen(TImage *ImageEscalada,int ancho,int alto,int Top,int Left,int AnchoAltoImageForm,TBevel *BevelImagen);
    void ZoomImagen(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,float escalaAncho,float escalaAlto);
    void IgualarImagen(Graphics::TBitmap* BitmapZoom,Graphics::TBitmap* BitmapOriginal,int ancho,int alto);
    void PromedioOIntensidadImagen(Graphics::TBitmap* BitmapPoI);
    void Saturacion(Graphics::TBitmap* BitmapPoI);
    void Matiz(Graphics::TBitmap* BitmapPoI);
    void BitPlane(int plane,Graphics::TBitmap* BitmapPlano);
    void GrayScaleWeighted(Graphics::TBitmap* BitmapGrayScale);
    void CanalRojo(Graphics::TBitmap* BitmapGrayScale);
    void CanalVerde(Graphics::TBitmap* BitmapGrayScale);
    void CanalAzul(Graphics::TBitmap* BitmapGrayScale);
    void CanalRojoGris(Graphics::TBitmap* BitmapGrayScale);
    void CanalVerdeGris(Graphics::TBitmap* BitmapGrayScale);
    void CanalAzulGris(Graphics::TBitmap* BitmapGrayScale);
    void CanalesRG(Graphics::TBitmap* BitmapRG);
    void CanalesRB(Graphics::TBitmap* BitmapRB);
    void CanalesGB(Graphics::TBitmap* BitmapGB);
    void OperacionLogica(char operacion,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe);
    void OperacionArtimetica(char operacion,char opcion,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe);
    void Superimpose(TColor ExceptPixel,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe);
    void Negado(Graphics::TBitmap* Bitmap);
    void CombiningRGB(Graphics::TBitmap* BitmapR,Graphics::TBitmap* BitmapG,Graphics::TBitmap* BitmapB,Graphics::TBitmap* BitmapRGB);
    void CombiningHSIRGB(Graphics::TBitmap* BitmapH,Graphics::TBitmap* BitmapS,Graphics::TBitmap* BitmapI,Graphics::TBitmap* BitmapRGB);
    void ObtenerBordeImagen(Graphics::TBitmap* Bitmap,int PixelsEdge,TColor ColorEdge,int PixelsRest,TColor ColorRest);
    void ColorearObjetos(Graphics::TBitmap* Bitmap,String Rango,TColor PixelsA,TColor PixelsB,TColor Color);
    void ColocaMatricesRGBenBitmap(byte **R,byte **G,byte **B,Graphics::TBitmap* BitmapResultado);
    void Rotar(float grados,float angle,Graphics::TBitmap* pBitmap,TColor Fondo);
    void Difuminado(TColor Fondo,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe);
    void TransparentColors(TColor TransparentColorA,TColor TransparentColorB,String TransparentRango,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* Bitmap2,Graphics::TBitmap* BitmapOpe);
    void RemoveLinesColumnsConstantColor(TColor Fonfo,Graphics::TBitmap* Bitmap1,Graphics::TBitmap* BitmapOpe);
    void RemoveRowsColumnsSimilarEdges(Graphics::TBitmap* Bitmap,Graphics::TBitmap* BitmapOpe);
    int umbralados(int indice,Graphics::TBitmap* Bitmap);
    void DecreaseColor8bit(Graphics::TBitmap* bmp);
    void DecreaseColorXbit(Graphics::TBitmap* bmp,int XColor,TColor ColorList[]);
    void FiltroAverage(Graphics::TBitmap* img,float **masc,Graphics::TBitmap* sal,int dim);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif

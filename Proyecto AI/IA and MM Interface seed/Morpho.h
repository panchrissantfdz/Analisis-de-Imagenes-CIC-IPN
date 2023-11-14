//---------------------------------------------------------------------------

#ifndef MorphoH
#define MorphoH

//---------------------------------------------------------------------------

//#include "ProcImg.h"

/*****************************
 Clase Morfología Matemática
******************************/

class TMorpho{
public:
//TProcImg *Pdi; //para la clase proc. de imágenes

//Graphics::TBitmap *imgD;
//Graphics::TBitmap *imgSE;
bool Reescalar;

Graphics::TBitmap * erodeB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * dilateB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * openingB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * closingB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * bextB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * bintB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * gradmB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * topHatB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * botHatB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);

int minimo(int a, int b, int c);
int maximo(int a, int b, int c);
Graphics::TBitmap * FunDist(Graphics::TBitmap *imgO);

int Max(Graphics::TBitmap *img);
int Min(Graphics::TBitmap *img);
Graphics::TBitmap * formula(int min, int Max, Graphics::TBitmap *Fxy);

int MaxiGray(int **bmp, int col, int ren);
int MiniGray(int **bmp, int col, int ren);

int rango(Graphics::TBitmap* img, int i, int j);
int _fastcall D8(int x1,int y1,int x2,int y2);
int _fastcall D4(int x1,int y1,int x2,int y2);
double _fastcall Deuc(int x1,int y1,int x2,int y2);
Graphics::TBitmap * erodeG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * dilateG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * dilateG2(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * openingG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * closingG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * bextG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * bintG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * gradmG(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * topHat(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * botHat(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * eroGeo(Graphics::TBitmap *imgMsk, Graphics::TBitmap *imgMrk);
Graphics::TBitmap * dilGeo(Graphics::TBitmap *imgMsk, Graphics::TBitmap *imgMrk);
Graphics::TBitmap * dilRec(Graphics::TBitmap *imgMrk,Graphics::TBitmap *imgMsk);
Graphics::TBitmap * eroRec(Graphics::TBitmap *imgMrk,Graphics::TBitmap *imgMsk );
Graphics::TBitmap * dualRec(Graphics::TBitmap *imgRe,Graphics::TBitmap *imgRd,Graphics::TBitmap *imgOri);
Graphics::TBitmap * ChessBoardDistanceMap(Graphics::TBitmap *entrada);
Graphics::TBitmap * CityBlock(Graphics::TBitmap* input);
Graphics::TBitmap * Euclidean(Graphics::TBitmap * input);
Graphics::TBitmap * SequentialThinningB(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy, int Iteracion,int rotationCSE);
Graphics::TBitmap * HitOrMiss(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * Prune(Graphics::TBitmap *imgO, Graphics::TBitmap *EE, int ox, int oy);
Graphics::TBitmap * RotaEEC(int angulo, int tam,Graphics::TBitmap *EER, int ox, int oy);

  int min(int a,int b);
  int max1(int c,int d);
};


//---------------------------------------------------------------------------

#endif

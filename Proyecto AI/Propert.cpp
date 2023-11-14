//---------------------------------------------------------------------------

#include <vcl.h>
#include <wingdi.h>
#pragma hdrstop

#include "Propert.h"
#include "ChildWin.h"
#include "HistogramWin.h"
#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPropertiesForm *PropertiesForm;
//---------------------------------------------------------------------------
__fastcall TPropertiesForm::TPropertiesForm(TComponent* Owner)
        : TForm(Owner)
{
/*
String Depth;
String Colors;
//int RGBC;
TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
String nom=Child->FileName;
//Propiedades de la imagen, Pagina Image
ImagPro->Picture->Bitmap=MainForm->ImgPrinc->Picture->Bitmap; //Imagen miniatura
Image1->Picture->Bitmap=MainForm->ImgPrinc->Picture->Bitmap;
//AnsiString nom = MainForm->OpenDialog->FileName;
//ShowMessage(nom);
Caption = " Properties="+ExtractFileName(nom);
Name->Caption= ExtractFileName(nom); //Nombre de la imagen
if(ExtractFileExt(nom) == ".jpg" || ExtractFileExt(nom) == ".jpeg" || ExtractFileExt(nom) == ".JPEG" || ExtractFileExt(nom) == ".JPG")
{Type->Caption = "JPEG";
LabelExtension->Caption="jpeg";}
else if (ExtractFileExt(nom) == ".bmp" || ExtractFileExt(nom) == ".BMP")
{Type->Caption = "Windows bitmap";
LabelExtension->Caption="bmp";}
else
Type->Caption = "Unknown";
path->Caption = ExtractFilePath(nom);
//RGBC=(MainForm->ImgPrinc->Picture->Bitmap->Height)*(MainForm->ImgPrinc->Picture->Bitmap->Width);//Calculo de Pixeles

        unsigned int headerSize;
        unsigned int imageSize;

        BITMAPINFOHEADER header;
        char* image;
        GetDIBSizes(Child->Image->Picture->Bitmap->Handle,headerSize,imageSize);
        image =(char*)malloc(imageSize);
        GetDIB(Child->Image->Picture->Bitmap->Handle, Child->Image->Picture->Bitmap->Palette,&header,image);






PixelesPerInches->Caption= Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch; //Pixeles por pulgada
dimpix->Caption = IntToStr(MainForm->ImgPrinc->Picture->Width) + " X " + IntToStr(MainForm->ImgPrinc->Picture->Height) + " Pixels";
dimin->Caption = FloatToStrF((float)MainForm->ImgPrinc->Picture->Width/ (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch,(TFloatFormat)2,8,2) + " X " +
                                FloatToStrF((float)MainForm->ImgPrinc->Picture->Height / (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch,(TFloatFormat)2,8,2) + " Inches";
dimcm->Caption = FloatToStrF(((float)MainForm->ImgPrinc->Picture->Width/ (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch)*2.54,(TFloatFormat)2,8,2) + " X " +
                                FloatToStrF(((float)MainForm->ImgPrinc->Picture->Height / (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch)*2.54,(TFloatFormat)2,8,2) + " cm";

switch(Child->Image->Picture->Bitmap->PixelFormat){
 case 1:
        Depth="1";
        Colors="2";
        break;
 case 2:
        Depth="4";
        Colors="16";
        break;
 case 3:
        Depth="8";
        Colors="256";
        break;
 case 6:
        Depth="24";
        Colors="16 Million";
        break;
 default :
        Depth="Unknown";
        Colors="Unknown";
}

PixelDepth->Caption=Depth+" Bit Per Pixel";
PixelColors->Caption=Colors+" Colors";

long tamano=header.biSizeImage;
tamano=tamano+54;

LabelSize->Caption=AnsiString(tamano)+" bytes";
//Propiedades de la imagen, Pagina Applied Functions
LabelListOfFunctions->Caption=ExtractFileName(nom);//Nombre del Archivo

 */
}
//---------------------------------------------------------------------------
void TPropertiesForm::Propiedades()
{
String Depth;
String Colors;
//int RGBC;
TMDIChild *Child =(TMDIChild *)MainForm->ActiveMDIChild;
String nom=Child->FileName;
Child->SetForma(this);
Graphics::TBitmap *pBitmap = new Graphics::TBitmap();
pBitmap->Assign(Child->ActiveBitmap());
//Propiedades de la imagen, Pagina Image
ImagPro->Picture->Bitmap=pBitmap; //Imagen miniatura
Image1->Picture->Bitmap=pBitmap;
//AnsiString nom = MainForm->OpenDialog->FileName;
//ShowMessage(nom);
Caption = " Properties="+ExtractFileName(nom);
Name->Caption= ExtractFileName(nom); //Nombre de la imagen
if(ExtractFileExt(nom) == ".jpg" || ExtractFileExt(nom) == ".jpeg" || ExtractFileExt(nom) == ".JPEG" || ExtractFileExt(nom) == ".JPG")
{Type->Caption = "JPEG";
LabelExtension->Caption="jpeg";}
else if (ExtractFileExt(nom) == ".bmp" || ExtractFileExt(nom) == ".BMP")
{Type->Caption = "Windows bitmap";
LabelExtension->Caption="bmp";}
else
Type->Caption = "Unknown";
path->Caption = ExtractFilePath(nom);
//RGBC=(MainForm->ImgPrinc->Picture->Bitmap->Height)*(MainForm->ImgPrinc->Picture->Bitmap->Width);//Calculo de Pixeles

        unsigned int headerSize;
        unsigned int imageSize;

        BITMAPINFOHEADER header;
        char* image;
        GetDIBSizes(Child->Image->Picture->Bitmap->Handle,headerSize,imageSize);
        image =(char*)malloc(imageSize);
        GetDIB(Child->Image->Picture->Bitmap->Handle, Child->Image->Picture->Bitmap->Palette,&header,image);






PixelesPerInches->Caption= Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch; //Pixeles por pulgada
dimpix->Caption = IntToStr(pBitmap->Width) + " X " + IntToStr(pBitmap->Height) + " Pixels";
dimin->Caption = FloatToStrF((float)pBitmap->Width/ (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch,(TFloatFormat)2,8,2) + " X " +
                                FloatToStrF((float)pBitmap->Height / (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch,(TFloatFormat)2,8,2) + " Inches";
dimcm->Caption = FloatToStrF(((float)pBitmap->Width/ (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch)*2.54,(TFloatFormat)2,8,2) + " X " +
                                FloatToStrF(((float)pBitmap->Height / (float)Child->Image->Picture->Bitmap->Canvas->Font->PixelsPerInch)*2.54,(TFloatFormat)2,8,2) + " cm";

switch(Child->Image->Picture->Bitmap->PixelFormat){
 case 1:
        Depth="1";
        Colors="2";
        break;
 case 2:
        Depth="4";
        Colors="16";
        break;
 case 3:
        Depth="8";
        Colors="256";
        break;
 case 6:
        Depth="24";
        Colors="16 Million";
        break;
 default :
        Depth="Unknown";
        Colors="Unknown";
}

PixelDepth->Caption=Depth+" Bit Per Pixel";
PixelColors->Caption=Colors+" Colors";

long tamano=header.biSizeImage;
tamano=tamano+54;

LabelSize->Caption=AnsiString(tamano)+" bytes";
//Propiedades de la imagen, Pagina Applied Functions
LabelListOfFunctions->Caption=ExtractFileName(nom);//Nombre del Archivo



}
//---------------------------------------------------------------------------
void __fastcall TPropertiesForm::FormCreate(TObject *Sender)
{
Propiedades();
}
//---------------------------------------------------------------------------


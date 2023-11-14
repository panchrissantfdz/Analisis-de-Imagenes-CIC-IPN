#ifndef __RGBPIEXL_H
#define __RGBPIEXL_H

class RGBPixel
{
    public:
        int rr;
        int gg;
        int bb;
        RGBPixel();
        RGBPixel(int r, int g, int b);
        RGBPixel(const RGBPixel *pixel);
};
//---------------------------------------------------------------------------
//***Implmentacion de los metodos***
//---------------------------------------------------------------------------
//Contrucotres por default y de copia
RGBPixel::RGBPixel()
{
    rr = gg = bb = 0;
}
//---------------------------------------------------------------------------
RGBPixel::RGBPixel(int r, int g, int b)
{
    rr = r;
    gg = g;
    bb = b;
}
//---------------------------------------------------------------------------
RGBPixel::RGBPixel(const RGBPixel *pixel)
{
    rr = pixel->rr;
    gg = pixel->gg;
    bb = pixel->bb;
}
//---------------------------------------------------------------------------
#endif //__RGBPIEXL_H
 



 
#ifndef __ELEMESTRUCT_H
#define __ELEMESTRUCT_H

class ElemEstruct {
    private:
        int cx;
        int cy;
        int alto;
        int ancho;
    public:
        int **elemento;
        ElemEstruct();
        ElemEstruct(int alto, int ancho, int cx, int cy);
        ElemEstruct(int alto, int ancho, int cx, int cy, int **val);
        ElemEstruct(const ElemEstruct &elem);
        ElemEstruct & operator= (const ElemEstruct &elem);
        ~ElemEstruct();
        void SetSize(int alto, int ancho);
        int  GetAlto();
        int  GetAncho();
        int  value(int x, int y);
        void SetCenter(int cx, int cy);
        int  GetCx();
        int  GetCy();
        void SetValues(int **val);
        void SetValues(int **val,int cx,int cy);
        void refleja();
};
//---------------------------------------------------------------------------
ElemEstruct::ElemEstruct()
{
    alto = ancho = 0;
    cx = cy = 0;
    SetSize(1, 1);
    alto = ancho = 1;
    elemento[0][0]=0;
}
//---------------------------------------------------------------------------
ElemEstruct::ElemEstruct(int alto, int ancho, int cx, int cy)
{
    SetSize(alto, ancho);
    SetCenter(cx, cy);
}
//---------------------------------------------------------------------------
ElemEstruct::ElemEstruct(int alto, int ancho, int cx, int cy, int **val)
{
    this->alto = this->ancho = 0;
    SetSize(alto, ancho);
    SetCenter(cx, cy);
    SetValues(val);
}
//---------------------------------------------------------------------------
ElemEstruct::ElemEstruct(const ElemEstruct &e)
{
    SetSize(e.alto, e.ancho);
    SetCenter(e.cx, e.cy);

    //copiamos los datos del elemento
    for(int y=0; y<alto; y++)
        for(int x=0; x<ancho; x++)
            elemento[y][x] = e.elemento[y][x];
}
//---------------------------------------------------------------------------
ElemEstruct & ElemEstruct::operator= (const ElemEstruct &elem)
{
    if(this == &elem) return *this;

        if(alto >0 && ancho > 0)
    {
        for(int y=0; y<alto; y++)
            delete [] elemento[y];
        delete []elemento;
    }

    SetSize(elem.alto, elem.ancho);
    SetCenter(elem.cx, elem.cy);

    //copiamos los datos del elemento
    for(int y=0; y<alto; y++)
        for(int x=0; x<ancho; x++)
            elemento[y][x] = elem.elemento[y][x];

    return *this;
}
//---------------------------------------------------------------------------
void ElemEstruct::SetSize(int Alto, int Ancho)
{
    //valor valido pedido
    if(Alto <= 0 || Ancho <= 0) return;
/*
    //si habia memoria anterior eliminamos
    if(alto > 0 && ancho > 0)
    {
        for(int i=0; i<alto; i++)
            delete [] elemento[i];
        delete [] elemento;
    }
*/
    //nuevo valor de memoria
    alto = Alto;
    ancho = Ancho;

    elemento = new int*[alto];
    for(int i=0; i<alto; i++)
        elemento[i] = new int[ancho];

    for(int i=0; i<alto; i++)
        for(int j=0; j<ancho; j++)
        elemento[i][j] = 0;
}
//---------------------------------------------------------------------------
int ElemEstruct::GetAlto()
{
    return alto;
}
//---------------------------------------------------------------------------
int ElemEstruct::GetAncho()
{
    return ancho;
}
//---------------------------------------------------------------------------
int ElemEstruct::value(int x, int y)
{
    return elemento[y][x];
}
//---------------------------------------------------------------------------
void ElemEstruct::SetCenter(int cx, int cy)
{
    //si el centro no esta dentro del espacio pedido
    if(0 <= cy && cy < alto && 0 <= cx && cx < ancho)
    {
        this->cx = cx;
        this->cy = cy;
    }
}
//---------------------------------------------------------------------------
int ElemEstruct::GetCx()
{
    return cx;
}
//---------------------------------------------------------------------------
int ElemEstruct::GetCy()
{
    return cy;
}
//---------------------------------------------------------------------------
void ElemEstruct::SetValues(int **val)
{
    for(int y=0; y<alto; y++)
        for(int x=0; x<ancho; x++)
            elemento[y][x] = val[y][x];
}
//---------------------------------------------------------------------------
void ElemEstruct::SetValues(int **val,int cx,int cy)
{
    for(int y=0; y<alto; y++)
        for(int x=0; x<ancho; x++)
            elemento[y][x] = val[y][x];
    SetCenter(cx,cy);
}
//---------------------------------------------------------------------------
void ElemEstruct::refleja()
{
    ElemEstruct *e = new ElemEstruct(*this);

    for(int y=0, i=alto-1; y<alto; y++,i--)
        for(int x=0, j=ancho-1; x<ancho; x++,j--)
            elemento[y][x] = e->elemento[i][j];
    delete e;
}
//---------------------------------------------------------------------------

ElemEstruct::~ElemEstruct()
{
    if(alto >0 && ancho > 0)
    {
        for(int y=0; y<alto; y++)
            delete [] elemento[y];
        delete []elemento;
    }
}
//---------------------------------------------------------------------------
#endif //__ELEMESTRUCT_H




 
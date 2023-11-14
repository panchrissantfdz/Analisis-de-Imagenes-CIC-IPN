//---------------------------------------------------------------------------

#ifndef StrucEEH
#define StrucEEH
//---------------------------------------------------------------------------
/*****************************
 Clase Elemento de Estructura
******************************/

struct TStrEE{
//   AnsiString tipo;
   int x,y;   //Origen
   int yren, xcol;//alto y ancho del EE
   int **bmp;

TStrEE();
void guarda(char *path);
void carga(char *path);

};


#endif

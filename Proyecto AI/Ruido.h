//---------------------------------------------------------------------------

#ifndef RuidoH
#define RuidoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TNoise : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TEdit *Valor;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNoise(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNoise *Noise;
//---------------------------------------------------------------------------
#endif

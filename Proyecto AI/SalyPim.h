//---------------------------------------------------------------------------

#ifndef SalyPimH
#define SalyPimH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSaltnPepper : public TForm
{
__published:	// IDE-managed Components
        TLabel *Completado;
        TButton *OK;
        void __fastcall OKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSaltnPepper(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSaltnPepper *SaltnPepper;
//---------------------------------------------------------------------------
#endif

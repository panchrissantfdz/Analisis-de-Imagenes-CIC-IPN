//---------------------------------------------------------------------------

#ifndef NormalizarH
#define NormalizarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TNormalizeForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *GetNormalize;
        TLabel *Label1;
        TBitBtn *BitBtnOK;
        void __fastcall BitBtnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNormalizeForm(TComponent* Owner);
        
};
//---------------------------------------------------------------------------
extern PACKAGE TNormalizeForm *NormalizeForm;
//---------------------------------------------------------------------------
#endif

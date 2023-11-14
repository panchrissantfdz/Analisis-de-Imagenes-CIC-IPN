//---------------------------------------------------------------------------

#ifndef BicubicFormH
#define BicubicFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormBicubic : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormBicubic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBicubic *FormBicubic;
//---------------------------------------------------------------------------
#endif

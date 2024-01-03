//---------------------------------------------------------------------------

#ifndef MedialAxisH
#define MedialAxisH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMedial_Axis : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *OK;
        TRadioButton *Vertical;
        TRadioButton *RadioButton2;
        void __fastcall OKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMedial_Axis(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMedial_Axis *Medial_Axis;
//---------------------------------------------------------------------------
#endif

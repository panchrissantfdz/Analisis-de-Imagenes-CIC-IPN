//---------------------------------------------------------------------------

#ifndef ZoomNeH
#define ZoomNeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TZoomN : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);
private:
	// User declarations
public:		// User declarations
        __fastcall TZoomN(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TZoomN *ZoomN;
//---------------------------------------------------------------------------
#endif

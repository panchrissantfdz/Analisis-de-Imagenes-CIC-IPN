//---------------------------------------------------------------------------

#ifndef ZoomH
#define ZoomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TBilineal : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);


private:	// User declarations

public:		// User declarations
        __fastcall TBilineal(TComponent* Owner);
        
};
//---------------------------------------------------------------------------
extern PACKAGE TBilineal *Bilineal;
//---------------------------------------------------------------------------
#endif

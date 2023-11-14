//---------------------------------------------------------------------------

#ifndef ZoomInFormH
#define ZoomInFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormZoom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TBitBtn *BitBtnOK;
        void __fastcall BitBtnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormZoom(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormZoom *FormZoom;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef ResolutionH
#define ResolutionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmRes : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox1;
        TUpDown *UpDown1;
        TEdit *Edit1;
        TBitBtn *BitBtnOK;
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall BitBtnOKClick(TObject *Sender);
private:

public:
        void ResolucionEspacial(Graphics::TBitmap *, int);
        __fastcall TFrmRes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRes *FrmRes;
//---------------------------------------------------------------------------
#endif

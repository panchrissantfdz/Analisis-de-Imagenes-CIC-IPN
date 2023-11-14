//---------------------------------------------------------------------------

#ifndef Resolution1H
#define Resolution1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmRes1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TBitBtn *BitBtnOK;
        TUpDown *UpDown1;
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TRadioButton *RadioButtonA;
        TRadioButton *RadioButtonW;
        TRadioButton *RadioButtonRGBG;
        TCheckBox *CheckBoxR;
        TCheckBox *CheckBoxG;
        TCheckBox *CheckBoxB;
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall BitBtnOKClick(TObject *Sender);
        void __fastcall RadioButtonRGBGClick(TObject *Sender);
        void __fastcall RadioButtonWClick(TObject *Sender);
        void __fastcall RadioButtonAClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:

public:
        void ResolucionColor(Graphics::TBitmap *, int);
        int ValidaFormato(Graphics::TBitmap *);
        void ResolucionEspacial(Graphics::TBitmap *, int);
        __fastcall TFrmRes1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRes1 *FrmRes1;
//---------------------------------------------------------------------------
#endif

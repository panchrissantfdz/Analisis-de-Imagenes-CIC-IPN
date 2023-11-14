//---------------------------------------------------------------------------

#ifndef Operaciones_LogH
#define Operaciones_LogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TOperacionesLog : public TForm
{
__published:	// IDE-managed Components
        TButton *AND;
        TButton *OR;
        TButton *XOR;
        TButton *NOT;
        TGroupBox *GroupBox1;
        TBevel *Bevel1;
        TImage *Image1;
        TBitBtn *BitBtnI1;
        TImage *Image2;
        TBevel *Bevel2;
        TBitBtn *BitBtnI2;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBoxFitSizeImage;
        TRadioButton *RadioButtonImage1;
        TRadioButton *RadioButtonImage2;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButtonImageNot1;
        TRadioButton *RadioButtonImageNot2;
        void __fastcall ANDClick(TObject *Sender);
        void __fastcall XORClick(TObject *Sender);
        void __fastcall NOTClick(TObject *Sender);
        void __fastcall ORClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtnI1Click(TObject *Sender);
        void __fastcall BitBtnI2Click(TObject *Sender);
        void __fastcall CheckBoxFitSizeImageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOperacionesLog(TComponent* Owner);
        String Image1Name;
        String Image2Name;
};
//---------------------------------------------------------------------------
extern PACKAGE TOperacionesLog *OperacionesLog;
//---------------------------------------------------------------------------
#endif

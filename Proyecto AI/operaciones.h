//---------------------------------------------------------------------------

#ifndef operacionesH
#define operacionesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//#include "ProcImg.h"
//#include "Morpho.h"
//---------------------------------------------------------------------------
class TFormArithmeticOperations : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *RadioButtonLimited;
        TRadioButton *RadioButtonCyclic;
        TRadioButton *RadioButtonScaled;
        TBevel *Bevel2;
        TBevel *Bevel1;
        TImage *Image1;
        TImage *Image2;
        TBitBtn *BitBtnI1;
        TBitBtn *BitBtnI2;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBoxFitSizeImage;
        TRadioButton *RadioButtonImage1;
        TRadioButton *RadioButtonImage2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TRadioButton *RadioButtonBlack;
        TRadioButton *RadioButtonWhite;
        TButton *ButtonSuperimpose;
        TButton *ButtonAdd;
        TButton *ButtonSubtract;
        TButton *ButtonMultiplication;
        TButton *ButtonDivision;
        TRadioButton *RadioButtonOtherColor;
        TColorDialog *ColorDialogSuperimpose;
        TBitBtn *BitBtnChooseColor;
        TPanel *PanelColor;
        void __fastcall ButtonAddClick(TObject *Sender);
        void __fastcall ButtonSubtractClick(TObject *Sender);
        void __fastcall ButtonDivisionClick(TObject *Sender);
        void __fastcall ButtonMultiplicationClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnI1Click(TObject *Sender);
        void __fastcall BitBtnI2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CheckBoxFitSizeImageClick(TObject *Sender);
        void __fastcall ButtonSuperimposeClick(TObject *Sender);
        void __fastcall BitBtnChooseColorClick(TObject *Sender);
        void __fastcall RadioButtonOtherColorClick(TObject *Sender);
        void __fastcall RadioButtonBlackClick(TObject *Sender);
        void __fastcall RadioButtonWhiteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormArithmeticOperations(TComponent* Owner);
        //int maximo(char in[],int largo);
        String Image1Name;
        String Image2Name;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormArithmeticOperations *FormArithmeticOperations;
//---------------------------------------------------------------------------
#endif

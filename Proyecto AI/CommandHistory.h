//---------------------------------------------------------------------------

#ifndef CommandHistoryH
#define CommandHistoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TCommandHistoryForm : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBoxCommandHistory;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *UndoRedoButton;
        TButton *CancelButton;
        TButton *HelpButton;
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall ListBoxCommandHistoryClick(TObject *Sender);
        void __fastcall UndoRedoButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int UndoSuperior;
        int UndoInferior;
        int RedoSuperior;
        int RedoInferior;
        int Bandera_Selec_Item;
        __fastcall TCommandHistoryForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCommandHistoryForm *CommandHistoryForm;
//---------------------------------------------------------------------------
#endif

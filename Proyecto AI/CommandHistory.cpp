//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CommandHistory.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCommandHistoryForm *CommandHistoryForm;
//---------------------------------------------------------------------------
__fastcall TCommandHistoryForm::TCommandHistoryForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCommandHistoryForm::CancelButtonClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TCommandHistoryForm::ListBoxCommandHistoryClick(
      TObject *Sender)
{
Bandera_Selec_Item=1;
ListBoxCommandHistory->MultiSelect=true;
String obteneritemlista = ListBoxCommandHistory->Items->Strings[ListBoxCommandHistory->ItemIndex];
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.Delete(1,2);
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.SubString(1,4);
obteneritemlista = obteneritemlista.TrimRight();
if (obteneritemlista=="Undo"){
        UndoSuperior=ListBoxCommandHistory->ItemIndex;
        while(obteneritemlista=="Undo" && ListBoxCommandHistory->ItemIndex!=0){
                ListBoxCommandHistory->ItemIndex--;
                obteneritemlista = ListBoxCommandHistory->Items->
                        Strings[ListBoxCommandHistory->ItemIndex];
                obteneritemlista = obteneritemlista.TrimLeft();
                obteneritemlista = obteneritemlista.Delete(1,2);
                obteneritemlista = obteneritemlista.TrimLeft();
                obteneritemlista = obteneritemlista.SubString(1,4);
                obteneritemlista = obteneritemlista.TrimRight();
                if (obteneritemlista!="Undo"){ListBoxCommandHistory->ItemIndex++;}
                }
        UndoInferior=ListBoxCommandHistory->ItemIndex;
        }
else if (obteneritemlista=="Redo"){
        RedoInferior=ListBoxCommandHistory->ItemIndex;
        while(obteneritemlista=="Redo" &&
                ListBoxCommandHistory->ItemIndex<ListBoxCommandHistory->Items->Count-1){
                ListBoxCommandHistory->ItemIndex++;
                obteneritemlista = ListBoxCommandHistory->Items->
                        Strings[ListBoxCommandHistory->ItemIndex];
                obteneritemlista = obteneritemlista.TrimLeft();
                obteneritemlista = obteneritemlista.Delete(1,2);
                obteneritemlista = obteneritemlista.TrimLeft();
                obteneritemlista = obteneritemlista.SubString(1,4);
                obteneritemlista = obteneritemlista.TrimRight();
                if (obteneritemlista!="Redo"){ListBoxCommandHistory->ItemIndex--;}
                }
        RedoSuperior=ListBoxCommandHistory->ItemIndex;
        }
obteneritemlista = ListBoxCommandHistory->Items->
        Strings[ListBoxCommandHistory->ItemIndex];
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.Delete(1,2);
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.SubString(1,4);
obteneritemlista = obteneritemlista.TrimRight();
UndoRedoButton->Caption = obteneritemlista;
        
}
//---------------------------------------------------------------------------

void __fastcall TCommandHistoryForm::UndoRedoButtonClick(TObject *Sender)
{
if(Bandera_Selec_Item==0){
UndoSuperior=ListBoxCommandHistory->ItemIndex;
UndoInferior=ListBoxCommandHistory->ItemIndex;
RedoSuperior=ListBoxCommandHistory->ItemIndex;
RedoInferior=ListBoxCommandHistory->ItemIndex;}
String obteneritemlista = ListBoxCommandHistory->Items->Strings[ListBoxCommandHistory->ItemIndex];
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.Delete(1,2);
obteneritemlista = obteneritemlista.TrimLeft();
obteneritemlista = obteneritemlista.SubString(1,4);
if (obteneritemlista=="Undo"){
       for ( int i=UndoInferior ; i<=UndoSuperior ; i++ ) {
       MainForm->Undo();
       MainForm->UndoUpdate(); }
        Close();}
else if (obteneritemlista=="Redo"){
        for ( int i=RedoSuperior ; i>=RedoInferior ; i-- ) {
       MainForm->Redo();
       MainForm->RedoUpdate();}
        Close();}
Bandera_Selec_Item=0;        
}
//---------------------------------------------------------------------------


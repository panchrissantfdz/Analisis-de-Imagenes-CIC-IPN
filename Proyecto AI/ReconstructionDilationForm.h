//---------------------------------------------------------------------------

#ifndef ReconstructionDilationFormH
#define ReconstructionDilationFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormReconstructionDilation : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel2;
        TBevel *Bevel1;
        TImage *ImageMarker;
        TImage *ImageMask;
        TBitBtn *BitBtnMarker;
        TBitBtn *BitBtnMask;
        TBitBtn *BitBtnOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnMarkerClick(TObject *Sender);
        void __fastcall BitBtnMaskClick(TObject *Sender);
        void __fastcall BitBtnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormReconstructionDilation(TComponent* Owner);
        String ImageMarkerName;
        String ImageMaskName;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReconstructionDilation *FormReconstructionDilation;
//---------------------------------------------------------------------------
#endif

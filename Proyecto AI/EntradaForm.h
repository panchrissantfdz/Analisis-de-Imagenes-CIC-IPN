//---------------------------------------------------------------------------

#ifndef EntradaFormH
#define EntradaFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormEntrada : public TForm
{
__published:	// IDE-managed Components
        TImage *ImageEntrada;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormEntrada(TComponent* Owner);
        void __fastcall WmEraseBkgnd(TWMEraseBkgnd& msg);
        BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(WM_ERASEBKGND, TWMEraseBkgnd, WmEraseBkgnd)
        END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEntrada *FormEntrada;
//---------------------------------------------------------------------------
#endif

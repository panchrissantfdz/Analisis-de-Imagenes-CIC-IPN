//---------------------------------------------------------------------------

#ifndef PropertH
#define PropertH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <TabNotBk.hpp>
#include <Tabs.hpp>
#include <string.h>
//---------------------------------------------------------------------------
class TPropertiesForm : public TForm
{
__published:	// IDE-managed Components
        TTabbedNotebook *Propierties_page;
        TLabel *NameSyst;
        TImage *Image1;
        TImage *ImagPro;
        TLabel *LabelListOfFunctions;
        TGroupBox *GroupBox1;
        TLabel *Name;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Type;
        TGroupBox *GroupBox2;
        TLabel *PixelesPerInches;
        TLabel *LPixels;
        TLabel *Label3;
        TLabel *dimpix;
        TLabel *dimin;
        TLabel *Label4;
        TLabel *PixelDepth;
        TLabel *Label7;
        TLabel *PixelColors;
        TLabel *Label6;
        TLabel *dimcm;
        TLabel *path;
        TLabel *Size;
        TLabel *LabelSize;
        TLabel *Extension;
        TLabel *LabelExtension;
        void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TPropertiesForm(TComponent* Owner);
        void Propiedades();
};
//---------------------------------------------------------------------------
extern PACKAGE TPropertiesForm *PropertiesForm;
//---------------------------------------------------------------------------
#endif

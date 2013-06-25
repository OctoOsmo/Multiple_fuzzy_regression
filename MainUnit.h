// ---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DockTabSet.hpp>
#include <Vcl.Tabs.hpp>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>



// ---------------------------------------------------------------------------
class TMainForm : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *NFile;
	TMenuItem *NQuit;
	TMenuItem *NProrerties;
	TMenuItem *NHelp;
	TPageControl *PageControl;
	TTabSheet *TabSheetRegMatrix;
	TStringGrid *SGXTX;
	TTabSheet *TabSheetDiverse;
	TStringGrid *SGDiverse;
	TTabSheet *TabSheetGraph;
	TImage *ImageGraph;
	TStringGrid *SGRXTX;
	TStringGrid *SGReg;
	TStringGrid *SGCoef;
	TMenuItem *NRegression;
	TMenuItem *NGraph;
	TMenuItem *NDepGrad;
	TStringGrid *SGYP;
	TStringGrid *SGY;
	TStringGrid *SGX;
	TLabel *LabelXTX;
	TLabel *LabelRXTX;
	TLabel *LabelCoef;
	TLabel *LabelReg;
	void __fastcall NQuitClick(TObject *Sender);
	void __fastcall NRegressionClick(TObject *Sender);
	void __fastcall NGraphClick(TObject *Sender);
	void __fastcall NDepGradClick(TObject *Sender);


private: // User declarations
		public : // User declarations
	__fastcall TMainForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

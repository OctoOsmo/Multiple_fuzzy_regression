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
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>



// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TStringGrid *SGX;
	TButton *Button1;
	TStringGrid *SGXTX;
	TStringGrid *SGY;
	TStringGrid *SGRXTX;
	TStringGrid *SGReg;
	TStringGrid *SGYP;
	TStringGrid *StringGrid7;
	TImage *ImageGraph;
	TButton *ButtonGraph;
	TButton *Draw;
	TStringGrid *StringGrid8;
	TStringGrid *StringGrid9;
	TStringGrid *SGCoef;
	TMainMenu *MainMenu1;
	TMenuItem *NFile;
	TMenuItem *NQuit;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonGraphClick(TObject *Sender);
	void __fastcall DrawClick(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif

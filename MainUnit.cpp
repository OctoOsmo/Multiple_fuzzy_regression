// ---------------------------------------------------------------------------

#include <vcl.h>
#include "MatrixOperations.h"
#include "Regression.h"
#include "DrawRegression.h"
#pragma hdrstop

#include "MainUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
// void DrawRegressionf(double xmin, double xmax, FuzzyNumber a, FuzzyNumber b) {
// Form1->ImageGraph->Canvas->MoveTo(xmin, a.m*xmin + b.m);
// Form1->ImageGraph->Canvas->LineTo(xmax, a.m*xmax + b.m);
//
// }

// ---------------------------------------------------------------------------

void __fastcall TMainForm::NQuitClick(TObject *Sender) {
	MainForm->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::NRegressionClick(TObject *Sender) {
	Regression reg;
	reg.OpenSampleFile("sample.txt");
	reg.CreateRegressionMatrix();
	MatrixOperations::PrintMatrix(reg.GetX(), MainForm->SGX);
	MatrixOperations::PrintMatrix(reg.GetXTX(), MainForm->SGXTX);
	MatrixOperations::PrintMatrix(reg.GetRXTX(), MainForm->SGRXTX);
	MatrixOperations::PrintMatrix(reg.GetReg(), MainForm->SGReg);
	MatrixOperations::PrintMatrix(reg.GetDepVector(), MainForm->SGY);
	MatrixOperations::PrintMatrix(reg.GetCoefficientsVector(),
		MainForm->SGCoef);
	MatrixOperations::PrintMatrix(reg.GetPredDepVector(), MainForm->SGYP);
	MatrixOperations::PrintMatrix(reg.GetDiverse(), MainForm->SGDiverse);
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::NGraphClick(TObject *Sender) {
	DrawRegression dr(500, 500, 10., 10.);
	Regression regr;
	// double pos = 4.;
	double step = dr.GetStep();
	MainForm->ImageGraph->Picture = NULL;
	for (double i = 0; i < 10; i += step) {
		FuzzyNumber fn = regr.GetModelValue(i);
		dr.DrawFuzzyNumber(fn, i, MainForm->ImageGraph);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::NDepGradClick(TObject *Sender) {
	Graphics::TBitmap *Gradient = new Graphics::TBitmap();
	Gradient->Height = 500;
	Gradient->Width = 500;
	int h = Gradient->Height;
	int w = Gradient->Height;

	struct tRGB {
		int R, G, B;
	};

	tRGB Color1, Color2;

	Color1.R = 214;
	Color1.G = 50;
	Color1.B = 50;

	Color2.R = 92;
	Color2.G = 44;
	Color2.B = 220;

	double Rg = (Color2.R - Color1.R);
	double Gg = (Color2.G - Color1.G);
	double Bg = (Color2.B - Color1.B);
	Rg /= w;
	Gg /= w;
	Bg /= w;

	for (int i = 0; i < w + 1; i++)
		for (int i2 = h / 2; i2 < h + 1; i2++) {
			Gradient->Canvas->Pixels[i][i2] =
				TColor(RGB(Color1.R + Rg * (i2 - h / 2),
				Color1.G + Gg * (i2 - h / 2), Color1.B + Bg * (i2 - h / 2)));
		}
	MainForm->ImageGraph->Canvas->Draw(0, 0, Gradient);
	MainForm->ImageGraph->Canvas->MoveTo(0, 0);
	MainForm->ImageGraph->Canvas->LineTo(w / 3, h / 2);
	// Form1->Canvas->Draw(0, 0, Gradient);

	delete Gradient;
}
// ---------------------------------------------------------------------------



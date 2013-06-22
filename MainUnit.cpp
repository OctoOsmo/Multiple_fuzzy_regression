// ---------------------------------------------------------------------------

#include <vcl.h>
#include "MatrixOperations.h"
#include "Regression.h"
#pragma hdrstop

#include "MainUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	MatrixOperations matrix;
	std::vector<std::vector<double> >x, x1, e, m, in1, in2, ind, tr, xtx, rev,
		rxtx, y;
	Regression reg;
	reg.OpenSampleFile("sample.txt");
	x = reg.GetIndepVector();
	matrix.PrintMatrix(x, Form1->StringGrid1);
	tr = matrix.Transp(x);
	matrix.PrintMatrix(tr, Form1->StringGrid2);
	xtx = matrix.MatrixMultiplication(tr, x);
	matrix.PrintMatrix(xtx, Form1->StringGrid3);
	rev = matrix.Reverse(xtx);
	matrix.PrintMatrix(rev, Form1->StringGrid4);
	rxtx = matrix.MatrixMultiplication(rev, tr);
	matrix.PrintMatrix(rxtx, Form1->StringGrid5);
	y = reg.GetDepm();
	y = matrix.Transp(y);
	matrix.PrintMatrix(y, Form1->StringGrid6);
	matrix.PrintMatrix(m, Form1->StringGrid7);
	m = matrix.MatrixMultiplication(rxtx, y);
	// e = matrix.CreateIdentityMatrix(3);
	// matrix.OpenMatrix("in.txt", x);
	// matrix.OpenMatrix("in.txt", x1);
	// // matrix.OpenMatrix("in1.txt", in1);
	// // matrix.OpenMatrix("in2.txt", in2);
	// matrix.PrintMatrix(x, Form1->StringGrid1);
	// matrix.GaussJordan(x, e);
	// matrix.PrintMatrix(x, Form1->StringGrid2);
	// rev = matrix.Reverse(x1);
	// matrix.PrintMatrix(rev, Form1->StringGrid3);
	// m = matrix.MatrixMultiplication(x1, rev);
	// // m = matrix.Transp(m);
	// matrix.PrintMatrix(m, Form1->StringGrid4);
	// Regression reg;
	// reg.OpenSampleFile("sample.txt");
	// ind = reg.GetIndepVector();
	// reg.SaveFuzzyVecToFile("fuzzy.txt");
	// //ind = matrix.Transp(ind);
	// matrix.PrintMatrix(ind, Form1->StringGrid5);
	// tr = matrix.Transp(ind);
	// xtx = matrix.MatrixMultiplication(tr, ind);
	// //rxtx = matrix.Reverse(xtx);
	// //rxtx = matrix.MatrixMultiplication(rxtx, tr);
	// y = reg.GetDepm();
	// y = matrix.Transp(y);
	// //rxtx = matrix.MatrixMultiplication(rxtx, y);
	// double det = matrix.det(rxtx);
	// Form1->Caption = FloatToStr(det);
	// matrix.PrintMatrix(xtx, Form1->StringGrid6);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ButtonGraphClick(TObject *Sender) {
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
	Form1->ImageGraph->Canvas->Draw(0, 0, Gradient);
	Form1->ImageGraph->Canvas->MoveTo(0, 0);
	Form1->ImageGraph->Canvas->LineTo(w / 3, h / 2);
	// Form1->Canvas->Draw(0, 0, Gradient);

	delete Gradient;
}

// ---------------------------------------------------------------------------
void DrawRegression(double xmin, double xmax, FuzzyNumber a, FuzzyNumber b) {
	Form1->ImageGraph->Canvas->MoveTo(xmin, a*xmin + b);
	Form1->ImageGraph->Canvas->LineTo(xmax, a*xmax + b);

}
// ---------------------------------------------------------------------------

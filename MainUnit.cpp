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
	std::vector<std::vector<double> >x, x1, e, m, in1, in2, ind;
	e = matrix.CreateIdentityMatrix(6);
	matrix.OpenMatrix("in.txt", x);
	matrix.OpenMatrix("in.txt", x1);
	// matrix.OpenMatrix("in1.txt", in1);
	// matrix.OpenMatrix("in2.txt", in2);
	matrix.PrintMatrix(x, Form1->StringGrid1);
	matrix.GaussJordan(x, e);
	m = matrix.MatrixMultiplication(x1, e);
	matrix.PrintMatrix(x, Form1->StringGrid2);
	matrix.PrintMatrix(e, Form1->StringGrid3);
	matrix.Transp(m);
	matrix.PrintMatrix(m, Form1->StringGrid4);
	Regression reg;
	reg.OpenSampleFile("sample.txt");
	ind = reg.GetIndepVector();
	reg.SaveFuzzyVecToFile("fuzzy.txt");
	matrix.PrintMatrix(ind, Form1->StringGrid5);
}
// ---------------------------------------------------------------------------


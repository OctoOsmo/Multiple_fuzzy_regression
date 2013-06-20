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

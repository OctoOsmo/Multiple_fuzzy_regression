//---------------------------------------------------------------------------

#include <vcl.h>
#include "MatrixOperations.h"
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
MatrixOperations matrix;
std::vector<std::vector<double> > x, e;
e = matrix.CreateIdentityMatrix(3);
matrix.OpenMatrix("in.txt", x);
matrix.PrintMatrix(x, Form1->StringGrid1);
matrix.GaussJordan(x, e);
matrix.PrintMatrix(x, Form1->StringGrid2);
matrix.PrintMatrix(e, Form1->StringGrid3);
}
//---------------------------------------------------------------------------


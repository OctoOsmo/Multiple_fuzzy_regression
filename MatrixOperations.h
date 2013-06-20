#include "MainUnit.h"
// ---------------------------------------------------------------------------

#ifndef MatrixOperationsH
#define MatrixOperationsH
// ---------------------------------------------------------------------------

class MatrixOperations {
private:
	double RowXCol(std::vector<double> &a, std::vector<double> &b);

	// multiplicate row and column
	double round10(double &s) {
		s *= 100;
		s = (s - floor(s) < 0.5) ? floor(s) : ceil(s);
		s /= 100;
		return s;
	}

public:
	std::vector<std::vector<double> >Transp
		(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x,
		std::vector<std::vector<double> > &e);
	double det(std::vector<std::vector<double> > &x); // calculating determinant
	std::vector<std::vector<double> >Cross(std::vector<std::vector<double> > &x,
		int a, int b);
	std::vector<std::vector<double> >CreateAdjMatrix
		(std::vector<std::vector<double> > &x); // Adjugate matrix
	std::vector<std::vector<double> >Reverse
		(std::vector<std::vector<double> > &x); // Reverse matrix x^-1
	int OpenMatrix(char *file_name, std::vector<std::vector<double> > &x);
	int PrintMatrix(std::vector<std::vector<double> > &x, TStringGrid *SG);
	std::vector<std::vector<double> >CreateIdentityMatrix(int size);
	std::vector<std::vector<double> >MatrixMultiplication
		(std::vector<std::vector<double> >&a,
		std::vector<std::vector<double> >&b);
};
#endif /* #ifndef class MatrixOperations */

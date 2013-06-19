#include "MainUnit.h"
// ---------------------------------------------------------------------------

#ifndef MatrixOperationsH
#define MatrixOperationsH
// ---------------------------------------------------------------------------

class MatrixOperations {
private:
	double RowXCol(std::vector<double> &a, std::vector<double> &b);
	// multiplicate row and column

public:
	int Transp(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x,
		std::vector<std::vector<double> > &e);
	int OpenMatrix(char *file_name, std::vector<std::vector<double> > &x);
	int PrintMatrix(std::vector<std::vector<double> > &x, TStringGrid *SG);
	std::vector<std::vector<double> >CreateIdentityMatrix(int size);
	std::vector<std::vector<double> >MatrixMultiplication
		(std::vector<std::vector<double> >&a,
		std::vector<std::vector<double> >&b);
};
#endif /* #ifndef class MatrixOperations */

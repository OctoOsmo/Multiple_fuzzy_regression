#include "MainUnit.h"
// ---------------------------------------------------------------------------

#ifndef MatrixOperationsH
#define MatrixOperationsH
// ---------------------------------------------------------------------------

class MatrixOperations {
	// void Transp (
public:
	int GaussJordan(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x, std::vector<std::vector<double> > &e);
	int OpenMatrix(char *file_name, std::vector<std::vector<double> > &x);
	int PrintMatrix(std::vector<std::vector<double> > &x, TStringGrid *SG);
	std::vector<std::vector<double> > CreateIdentityMatrix(int size);
};
#endif /* #ifndef class MatrixOperations */

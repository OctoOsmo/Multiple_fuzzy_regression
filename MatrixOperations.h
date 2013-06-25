#include "MainUnit.h"
#include "FuzzyNumber.h"
// ---------------------------------------------------------------------------

#ifndef MatrixOperationsH
#define MatrixOperationsH
// ---------------------------------------------------------------------------

class MatrixOperations {
private:
	//////////////////////////////////////
	// @brief multiplicate row and column
	// a and b - inputs vectors to multiplicate
	double RowXCol(std::vector<double> &a, std::vector<double> &b);

	//////////////////////////////////////
	// @brief round to integer
	// s - number for rounding
	double round(double s) {
		// s *= 10;
		s = (s - floor(s) < 0.5) ? floor(s) : ceil(s);
		// s /= 10;
		return s;
	}

public:

	//////////////////////////////////////
	// @brief round to hundreth
	// s - number for rounding
	static double round10(double s) {

		s *= 100;
		s = (s - floor(s) < 0.5) ? floor(s) : ceil(s);
		s /= 100;
		return s;
	}

	//////////////////////////////////////
	// @brief transpose input matrix, keep input matrix untouched
	// x - input matrix
	static std::vector<std::vector<double> >Transp
		(std::vector<std::vector<double> > &x);

	//////////////////////////////////////
	// @brief round input matrix, keep input matrix untouched
	// x - input matrix
	std::vector<std::vector<double> >Round
		(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x);
	int GaussJordan(std::vector<std::vector<double> > &x,
		std::vector<std::vector<double> > &e);

	//////////////////////////////////////
	// @brief calculete determinant of matrix
	// x - input matrix
	static double det(std::vector<std::vector<double> > &x);

	//////////////////////////////////////
	// @brief replace two columns in matrix, keep input matrix untouched
	// x - input matrix, a and b - number of columns to replace
	static std::vector<std::vector<double> >Cross
		(std::vector<std::vector<double> > &x, int a, int b);

	//////////////////////////////////////
	// @brief create Adjugate matrix
	// x - original matrix
	static std::vector<std::vector<double> >CreateAdjMatrix
		(std::vector<std::vector<double> > &x);

	//////////////////////////////////////
	// @brief calculate reverse matrix
	// x - original matrix x^-1
	static std::vector<std::vector<double> >Reverse
		(std::vector<std::vector<double> > &x);

	//////////////////////////////////////
	// @brief open input matrix
	// file_name - name of input file, x - input matix to fill
	int OpenMatrix(char *file_name, std::vector<std::vector<double> > &x);

	//////////////////////////////////////
	// @brief Printig matrix to DrawGrid
	static int PrintMatrix(std::vector<std::vector<double> >x, TStringGrid *SG);

	//////////////////////////////////////
	// @brief Printig matrix to DrawGrid
	static int PrintMatrix(std::vector<FuzzyNumber>x, TStringGrid *SG);

	//////////////////////////////////////
	// @brief Create Identity matrix
	// size - size of desired matrix
	static std::vector<std::vector<double> >CreateIdentityMatrix(int size);

	//////////////////////////////////////
	// @brief calculate Multiplication of matrix,  keep input matrix untouched
	static std::vector<std::vector<double> >MatrixMultiplication
		(std::vector<std::vector<double> >&a,
		std::vector<std::vector<double> >&b);
};
#endif /* #ifndef class MatrixOperations */

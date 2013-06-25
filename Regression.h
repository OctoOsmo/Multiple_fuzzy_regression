// ---------------------------------------------------------------------------

#ifndef RegressionH
#define RegressionH
#include "FuzzyNumber.h"
#include "MainUnit.h"
#include "MatrixOperations.h"

// ---------------------------------------------------------------------------
class Regression {
private:
	std::vector<std::vector<double> >x;
	// initial sample independent variables vector
	std::vector<std::vector<double> >xt;
	// transpose initial sample independent variables vector
	std::vector<std::vector<double> >xtx; // xt*x
	std::vector<std::vector<double> >rxtx; // reverse of xtx
	std::vector<std::vector<double> >reg; // rxtx*xt, regression matrix
	std::vector<FuzzyNumber>y; // initial sample dependent variables vector
	std::vector<FuzzyNumber>coef; // regression coefficients vector
	std::vector<FuzzyNumber>yp; // predicted dependent variables values vector
	std::vector<std::vector<double> >m; // middles reggression coefficients
	std::vector<std::vector<double> >a;
	// left parts of reggression coefficients
	std::vector<std::vector<double> >b;
	// right parts of reggression coefficients
	std::vector<double>em; // m diverse
	std::vector<double>ea; // a diverse
	std::vector<double>eb; // b diverse
	std::vector<double>sem; // normalize m diverse
	std::vector<double>sea; // normalize a diverse
	std::vector<double>seb; // normalize b diverse

public:
	//////////////////////////////////////
	// @brief read initial sample from file
	int OpenSampleFile(char* file_name);

	//////////////////////////////////////
	// @brief create matrix ((xt*x)^-1)*xt
	// fill xt, xtx, rxtx, reg
	int CreateRegressionMatrix();

	//////////////////////////////////////
	// @brief returns diverse vector
	std::vector<std::vector<double> >GetDiverse();

	//////////////////////////////////////
	// @brief x getter
	std::vector<std::vector<double> >GetX() {
		return x;
	}

	//////////////////////////////////////
	// @brief xt getter
	std::vector<std::vector<double> >GetXT() {
		return xt;
	}

	//////////////////////////////////////
	// @brief xtx getter
	std::vector<std::vector<double> >GetXTX() {
		return xtx;
	}

	//////////////////////////////////////
	// @brief rxtx getter
	std::vector<std::vector<double> >GetRXTX() {
		return rxtx;
	}

	//////////////////////////////////////
	// @brief reg getter
	std::vector<std::vector<double> >GetReg() {
		return reg;
	}

	//////////////////////////////////////
	// @brief save vector of FuzzzyNumber to file
	// file_name - name of file, to be saved input vector
	// fuz - vector to save
	int SaveFuzzyVecToFile(char* file_name, std::vector<FuzzyNumber> &fuz);

	//////////////////////////////////////
	// @brief save vector of FuzzzyNumber to file
	// file_name - name of file, to be saved x vector
	// uses x private variable
	// save vector of FuzzzyNumber to file overload
	int SaveFuzzyVecToFile(char* file_name);

	//////////////////////////////////////
	// @brief triangle fuzzy number set structure
	// a, b, c - left, middle and right values
	FuzzyNumber GetModelValue(double x); // get model value at point

	//////////////////////////////////////
	// @brief get initial sample independent vector
	std::vector<std::vector<double> >GetIndepVector() {
		return x;
	}

	//////////////////////////////////////
	// @brief get predicted coefficients vector
	std::vector<FuzzyNumber>GetCoefficientsVector() {
		return coef;
	}

	//////////////////////////////////////
	// @brief get predicted dependent vector
	std::vector<FuzzyNumber>GetPredDepVector() {
		return yp;
	}

	//////////////////////////////////////
	// @brief get initial sample dependent vector
	std::vector<FuzzyNumber>GetDepVector() {
		return y;
	}

	//////////////////////////////////////
	// @brief get middle values of depended variableas vector
	std::vector<std::vector<double> >GetDepm() {
		std::vector<std::vector<double> >m;
		m.resize(1);
		for (unsigned int i = 0; i < y.size(); ++i)
			m[0].push_back(y[i].m);
		return m;
	}

	//////////////////////////////////////
	// @brief get left values of depended variableas vector
	std::vector<std::vector<double> >GetDepa() {
		std::vector<std::vector<double> >a;
		a.resize(1);
		for (unsigned int i = 0; i < y.size(); ++i)
			a[0].push_back(y[i].a);
		return a;
	}

	//////////////////////////////////////
	// @brief get left values of depended variableas vector
	std::vector<std::vector<double> >GetDepb() {
		std::vector<std::vector<double> >b;
		b.resize(1);
		for (unsigned int i = 0; i < y.size(); ++i)
			b[0].push_back(y[i].b);
		return b;
	}
};
#endif

// ---------------------------------------------------------------------------

#ifndef RegressionH
#define RegressionH
#include "FuzzyNumber.h"
#include "MainUnit.h"

// ---------------------------------------------------------------------------
class Regression {
private:
	std::vector<std::vector<double> >x;
	// initial sample independent variables vector
	std::vector<FuzzyNumber>y; // initial sample dependent variables vector
	std::vector<FuzzyNumber>yp; // predicted dependent variables values vector

public:
	int OpenSampleFile(char* file_name); // read initial sample from file
	int SaveFuzzyVecToFile(char* file_name, std::vector<FuzzyNumber> &fuz);
	// save vector of FuzzzyNumber to file
	int SaveFuzzyVecToFile(char* file_name);
	// save vector of FuzzzyNumber to file overload

	std::vector<std::vector<double> >GetIndepVector()
		// get initial sample independent vector
	{
		return x;
	}

	std::vector<FuzzyNumber>GetDepVector()
		// get initial sample dependent vector
	{
		return y;
	}
};
#endif

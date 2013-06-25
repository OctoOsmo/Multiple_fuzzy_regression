// ---------------------------------------------------------------------------

#ifndef FuzzyNumberH
#define FuzzyNumberH
#include "MainUnit.h"

// ---------------------------------------------------------------------------
//////////////////////////////////////
// @brief triangle fuzzy number set class
// m, a, b - left, middle and right values
class FuzzyNumber {
private:
	char* append_file_name;
	// name of file which will be used to save fuzzy nubers
	// FILE *append; // file to save fuzzy numbers

public:
	double m, a, b; // left, middle and right values

	//////////////////////////////////////
	// @brief write current values of fuzzy number to file
	// uses append_file_name variable
	int AppendNumberToFile();

	//////////////////////////////////////
	// @brief constructor, sets default file name of append file, which used to save fuzzy numbers
	FuzzyNumber() : append_file_name("FuzzyNumbers") {
	}

	friend FuzzyNumber operator +(FuzzyNumber a, FuzzyNumber b) {
		FuzzyNumber c;
		c.m = a.m + b.m;
		c.a = a.a + b.a;
		c.b = a.b + b.b;
		return c;
	}

	friend FuzzyNumber operator *(double a, FuzzyNumber b) {
		FuzzyNumber c;
		if (a >= 0) {
			c.m = a * b.m;
			c.a = a * b.a;
			c.b = a * b.b;
			return c;
		}
		if (a < 0) {
			c.m = a * b.m;
			c.a = -a * b.a;
			c.b = -a * b.b;
			return c;
		}
	}

	friend FuzzyNumber operator *(FuzzyNumber b, double a) {
		FuzzyNumber c;
		if (a >= 0) {
			c.m = a * b.m;
			c.a = a * b.a;
			c.b = a * b.b;
			return c;
		}
		if (a < 0) {
			c.m = a * b.m;
			c.a = -a * b.a;
			c.b = -a * b.b;
			return c;
		}
	}
};

#endif

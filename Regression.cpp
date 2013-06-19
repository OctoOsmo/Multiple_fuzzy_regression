// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Regression.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int Regression::OpenSampleFile(char* file_name) {
	FILE *in;
	if ((in = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Cannot open sample file.\n");
		return 0;
	}
	int size;
	fscanf(in, "%d", &size); // read count of independent variables
	x.clear(); // clear initial sample independent variables vector
	y.clear(); // clear initial sample dependent variables vector
	double tmpx;
	FuzzyNumber tmpy;
	std::vector<double>tmpv;
	while (fscanf(in, "%lf", &tmpx) != EOF) {
		// read initial sample independent variables
		tmpv.push_back(1); 
		tmpv.push_back(tmpx);
		for (int i = 1; i < size; ++i) {
			fscanf(in, "%lf", &tmpx);
			tmpv.push_back(tmpx);
		}
		x.push_back(tmpv);
		tmpv.clear();
		// read initial sample dependent variables
		fscanf(in, "%lf", &tmpy.m);
		fscanf(in, "%lf", &tmpy.a);
		fscanf(in, "%lf", &tmpy.b);
		y.push_back(tmpy);
	}
	fclose(in);
	return 1;
}

int Regression::SaveFuzzyVecToFile(char* file_name,
	std::vector<FuzzyNumber> &fuz)
	// predicted dependent variables values vector
{
	FILE *out;
	if ((out = fopen(file_name, "w")) == NULL) {
		fprintf(stderr, "Cannot create output file.\n");
		return 0;
	}
	for (unsigned int i = 0; i < fuz.size(); ++i) {
		fprintf(out, "%lf %lf %lf\n", fuz[i].m, fuz[i].a, fuz[i].b);
	}
	fclose(out);
	return 1;
}

int Regression::SaveFuzzyVecToFile(char* file_name)
	// predicted dependent variables values vector overload
{
	FILE *out;
	if ((out = fopen(file_name, "w")) == NULL) {
		fprintf(stderr, "Cannot create output file.\n");
		return 0;
	}
	for (unsigned int i = 0; i < y.size(); ++i) {
		fprintf(out, "%lf %lf %lf\n", y[i].m, y[i].a, y[i].b);
	}
	fclose(out);
	return 1;
}

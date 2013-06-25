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

FuzzyNumber Regression::GetModelValue(double x) {
	FuzzyNumber ret;
	ret.m = x / 2.1 + 3;
	ret.a = ret.b = ret.m / 16;
	return ret;
}

int Regression::CreateRegressionMatrix() {
	// calculating matrix
	xt = MatrixOperations::Transp(x);
	xtx = MatrixOperations::MatrixMultiplication(xt, x);
	rxtx = MatrixOperations::Reverse(xtx);
	reg = MatrixOperations::MatrixMultiplication(rxtx, xt);
	// calculating regression coefficients
	m = GetDepm();
	m = MatrixOperations::Transp(m);
	a = GetDepa();
	a = MatrixOperations::Transp(a);
	b = GetDepb();
	b = MatrixOperations::Transp(b);
	m = MatrixOperations::MatrixMultiplication(reg, m);
	a = MatrixOperations::MatrixMultiplication(reg, a);
	b = MatrixOperations::MatrixMultiplication(reg, b);
	coef.resize(m.size());
	for (unsigned int i = 0; i < m.size(); ++i) {
		coef[i].m = m[i][0];
		coef[i].a = a[i][0];
		coef[i].b = b[i][0];
	}
	// coef[0]=coef[0]+coef[0];
	// coef[0] = 4 * coef[0];
	// calculating regression result
	yp.resize(y.size());
	for (unsigned int i = 0; i < y.size(); i++)
		for (unsigned int j = 0; j < x[i].size(); j++)
			yp[i] = yp[i] + coef[j] * x[i][j];
	// calculating diverse
	for (unsigned int i = 0; i < y.size(); i++) {
		em.push_back(y[i].m - yp[i].m);
		ea.push_back(y[i].a - yp[i].a);
		eb.push_back(y[i].b - yp[i].b);
		sem.push_back(1 - fabs(em[i] / y[i].m));
		sea.push_back(1 - fabs(ea[i] / y[i].b));
		seb.push_back(1 - fabs(eb[i] / y[i].b));
	}
	return 1;
}

std::vector<std::vector<double> >Regression::GetDiverse() {
	std::vector<std::vector<double> >res;
	res.push_back(em);
	res.push_back(ea);
	res.push_back(eb);
	res.push_back(sem);
	res.push_back(sea);
	res.push_back(seb);
	return MatrixOperations::Transp(res);
}

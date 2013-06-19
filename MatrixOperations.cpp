// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrixOperations.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int MatrixOperations::GaussJordan(std::vector<std::vector<double> > &x) {
	if ((x.size() == 0) || (x.size() != x[0].size()))
		return 0;
	int size = x.size();
	// make upper triangular matrix
	// int m; // current first row
	for (int m = 0; m < size; ++m) {
		for (int i = size - 1; i >= m; --i) // first row
				x[m][i] /= x[m][m];
		for (int i = size - 1; i > m; --i) // rows
			for (int j = size - 1; j >= m; --j) // columns
					x[i][j] -= x[i][m] * x[m][j];
	}
	// last step
	for (int m = size - 1; m > 0; --m) {
		for (int i = m - 1; i >= 0; --i) {
			double k = x[i][m];
			for (int j = m; j >= 0; --j)
				x[i][j] -= k * x[m][j];
		}
	}
	return 1;
}

int MatrixOperations::GaussJordan(std::vector<std::vector<double> > &x,
	std::vector<std::vector<double> > &e) {
	if ((x.size() == 0) || (x.size() != x[0].size()))
		return 0;
	int size = x.size();
	// make upper triangular matrix
	// int m; // current first row
	for (int m = 0; m < size; ++m) {
		for (int i = size - 1; i >= m; --i) // first row
		{
			x[m][i] /= x[m][m];
			e[m][i] /= e[m][m];
		}
		for (int i = size - 1; i > m; --i) // rows
			for (int j = size - 1; j >= m; --j) // columns
			{
				x[i][j] -= x[i][m] * x[m][j];
				e[i][j] -= e[i][m] * e[m][j];
			}
	}
	// last step
	for (int m = size - 1; m > 0; --m) {
		for (int i = m - 1; i >= 0; --i) {
			double k = x[i][m];
			double ke = e[i][m];
			for (int j = m; j >= 0; --j) {
				x[i][j] -= k * x[m][j];
				e[i][j] -= ke * e[m][j];
			}
		}
	}
	return 1;
}

int MatrixOperations::OpenMatrix(char *file_name,
	std::vector<std::vector<double> > &x) {
	FILE *in;
	if ((in = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Cannot open weights file.\n");
		return 0;
	}
	int size;
	fscanf(in, "%d", &size);
	x.clear();
	x.resize(size);
	for (int i = 0; i < size; ++i) {
		x[i].resize(size);
		for (int j = 0; j < size; ++j)
			fscanf(in, "%lf", &x[i][j]);
	}
	fclose(in);
	return 1;
}

int MatrixOperations::PrintMatrix(std::vector<std::vector<double> > &x,
	TStringGrid *SG) {
	int sizex = x.size();
	if (sizex == 0)
		return 0;
	int sizey = x[0].size();
	if (sizey == 0)
		return 0;
	int cell_size = 30;
	SG->DefaultColWidth = cell_size;
	SG->DefaultRowHeight = cell_size;
	SG->ColCount = sizey;
	SG->RowCount = sizex;
	SG->Width = (cell_size + 2) * sizey;
	SG->Height = (cell_size + 2) * sizex;
	for (int i = 0; i < sizex; ++i)
		for (int j = 0; j < sizey; ++j)
			SG->Cells[j][i] = x[i][j];
	return 1;
}

std::vector<std::vector<double> >MatrixOperations::CreateIdentityMatrix
	(int size) {
	std::vector<std::vector<double> >x;
	x.resize(size);
	for (int i = 0; i < size; ++i)
		x[i].resize(size, 0);
	for (int i = 0; i < size; ++i)
		x[i][i] = 1;
	return x;
}

std::vector<std::vector<double> >MatrixOperations::MatrixMultiplication
	(std::vector<std::vector<double> >&a, std::vector<std::vector<double> >&b) {
	std::vector<std::vector<double> >mul;
	mul.resize(1);
	mul[0].resize(1, 0);
	if ((a.size() == 0) || (b.size() == 0) || (a[0].size() == 0) ||
		(a.size() != b[0].size()))
		return mul;
	mul.clear();
	int m = a.size();
	int n = a[0].size();
	int k = b[0].size();
	double rxc;
	std::vector<double>tmp;
	for (int i = 0; i < m; ++i) {
		tmp.clear();
		for (int j = 0; j < k; ++j) {
			// tmp.push_back(RowXCol(a[i], b[j]));
			rxc = 0;
			for (int p = 0; p < k; ++p) {
				rxc += a[i][p] * b[p][j];
			}
			tmp.push_back(rxc);
		}
		mul.push_back(tmp);
	}
	// m.resize(size);
	// for (int i = 0; i < size; ++i) {
	// m[i].resize(size, 0);
	// for (int j = 0; j < size; ++j)
	// for (int k = 0; k < size; ++k)
	// m[i][j] += a[i][k] * b[k][j];
	// }
	return mul;
}

double MatrixOperations::RowXCol(std::vector<double> &a, std::vector<double> &b)
{
	int size = a.size();
	if (b.size() != size)
		return 0;
	double sum = 0;
	for (int i = 0; i < size; ++i)
		sum += a[i] * b[i];
	return sum;
}

int MatrixOperations::Transp(std::vector<std::vector<double> > &x) {
	int size = x.size();
	if ((size == 0) || (size != x[0].size())) {
		return 0;
	}
	double tmp;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < i; ++j) {
			// if (i != j) {
			tmp = x[i][j];
			x[i][j] = x[j][i];
			x[j][i] = tmp;
		}
	// }
	return 1;
}

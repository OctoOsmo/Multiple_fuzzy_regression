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
				e[i][j] -= k * e[m][j];
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
	int size = x.size();
	int cell_size = 30;
	SG->DefaultColWidth = cell_size;
	SG->DefaultRowHeight = cell_size;
	SG->ColCount = size;
	SG->RowCount = size;
	SG->Width = (cell_size + 2) * size;
	SG->Height = (cell_size + 2) * size;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			SG->Cells[j][i] = x[i][j];
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

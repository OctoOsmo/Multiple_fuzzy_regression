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
	int m = 0; // current first row
	for (int m = 0; m < size; ++m) {
		for (int i = size - 1; i >= m; --i) // first row
		{
			x[m][i] /= x[m][m];
			e[m][i] /= x[m][m];
		}
		for (int i = size - 1; i > m; --i) // rows
			for (int j = size - 1; j >= m; --j) // columns
			{
				x[i][j] -= x[i][m] * x[m][j];
				e[i][j] -= x[i][m] * x[m][j];
			}
	}
	// last step
	for (int m = size - 1; m > 0; --m) {
		for (int i = m - 1; i >= 0; --i) {
			double k = x[i][m];
			double ke = e[i][m];
			for (int j = m; j >= 0; --j) {
				x[i][j] -= k * x[m][j];
				e[i][j] -= k * x[m][j];
			}
		}
	}
	return 1;
}

double MatrixOperations::det(std::vector<std::vector<double> > &x)
	// calculate determinant of matrix
{
	int size = x.size();
	if (size == 0)
		return 0;
	if (size != (int)x[0].size())
		return 0;
	if (size == 1)
		return x[0][0];
	double d = 0;
	// int sign;
	std::vector<std::vector<double> >xcross;
	for (int i = 0; i < size; ++i) {
		// xcross.clear();
		// xcross.resize(size - 1);
		// for (int j = 1; j < size; ++j)
		// for (int k = 0; k < size; ++k) {
		// if (k != i)
		// xcross[j - 1].push_back(x[j][k]);
		// }
		xcross = Cross(x, 0, i);
		if (i % 2 == 0)
			// sign = 1;
				d += x[0][i] * det(xcross);
		else
			// sign = -1;
				d -= x[0][i] * det(xcross);

		// d += sign * x[0][i] * d * det(xcross);
	}
	return d;
}

std::vector<std::vector<double> >MatrixOperations::CreateAdjMatrix
	(std::vector<std::vector<double> > &x) // Adjugate matrix
{
	int size = x.size();
	std::vector<std::vector<double> >Adj;
	std::vector<std::vector<double> >xcross;
	Adj.resize(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			if ((i + j + 2) % 2) {
				xcross = Cross(x, i, j);
				Adj[i].push_back(-det(xcross));
			}
			else {
				xcross = Cross(x, i, j);
				Adj[i].push_back(det(xcross));
			}
		}
	return Adj;
}

std::vector<std::vector<double> >MatrixOperations::Reverse
	(std::vector<std::vector<double> > &x) // Reverse matrix x^-1
{
	double d = det(x);
	std::vector<std::vector<double> >rev;
	rev = CreateAdjMatrix(x);
	rev = Transp(rev);
	for (unsigned int i = 0; i < rev.size(); ++i)
		for (unsigned int j = 0; j < rev[i].size(); ++j)
			rev[i][j] /= d;
	return rev;
}

std::vector<std::vector<double> >MatrixOperations::Cross
	(std::vector<std::vector<double> > &x, int a, int b) {
	std::vector<std::vector<double> >cross;
	int size = x.size();
	cross.resize(size - 1);
	int k = 0;
	for (int i = 0; i < size; ++i)
		if (i != a) {
			for (int j = 0; j < size; ++j)
				if (j != b)
					cross[k].push_back(x[i][j]);
			++k;
		}
	return cross;
}

int MatrixOperations::OpenMatrix(char *file_name,
	std::vector<std::vector<double> >&x) {
	FILE *in;
	if ((in = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "Cannot open file.\n");
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

int MatrixOperations::PrintMatrix(std::vector<std::vector<double> >x,
	TStringGrid* SG) {
	int sizex = x.size();
	if (sizex == 0)
		return 0;
	int sizey = x[0].size();
	if (sizey == 0)
		return 0;
	int cell_size = 45;
	SG->DefaultColWidth = cell_size;
	SG->DefaultRowHeight = cell_size;
	SG->ColCount = sizey;
	SG->RowCount = sizex;
	SG->Width = (cell_size + 1) * sizey + 3;
	SG->Height = (cell_size + 1) * sizex + 3;
	if (sizex == 1)
		SG->Height = 70;
	if (sizey == 1)
		SG->Width = 70;
	for (int i = 0; i < sizex; ++i)
		for (int j = 0; j < sizey; ++j)
			SG->Cells[j][i] = round10(x[i][j]);
	return 1;
}

int MatrixOperations::PrintMatrix(std::vector<FuzzyNumber>x, TStringGrid *SG) {
	int sizex = x.size();
	if (sizex == 0)
		return 0;
	int sizey = 3;
	int cell_size = 45;
	SG->DefaultColWidth = cell_size;
	SG->DefaultRowHeight = cell_size;
	SG->ColCount = sizey;
	SG->RowCount = sizex;
	SG->Width = (cell_size + 1) * sizey + 3;
	SG->Height = (cell_size + 1) * sizex + 3;
	for (int i = 0; i < sizex; ++i) {
		SG->Cells[0][i] = round10(x[i].m);
		SG->Cells[1][i] = round10(x[i].a);
		SG->Cells[2][i] = round10(x[i].b);
	}
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
	// mul.resize(1);
	// mul[0].resize(1, 0);
	// if ((a.size() == 0) || (b.size() == 0) || (a[0].size() == 0) ||
	// (a.size() != b[0].size()))
	// return mul;
	// mul.clear();
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
			for (int p = 0; p < n; ++p) {
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

double MatrixOperations::RowXCol(std::vector<double>&a, std::vector<double>&b) {
	int size = a.size();
	if ((int)b.size() != size)
		return 0;
	double sum = 0;
	for (int i = 0; i < size; ++i)
		sum += a[i] * b[i];
	return sum;
}

std::vector<std::vector<double> >MatrixOperations::Transp
	(std::vector<std::vector<double> >&x) {
	int rowx = x.size();
	int colx = x[0].size();
	std::vector<std::vector<double> >t;
	t.resize(colx);
	for (int i = 0; i < colx; ++i)
		for (int j = 0; j < rowx; ++j)
			t[i].push_back(x[j][i]);
	return t;
}

std::vector<std::vector<double> >MatrixOperations::Round
	(std::vector<std::vector<double> >&x) {
	std::vector<std::vector<double> >out;
	out.resize(x.size());
	for (unsigned int i = 0; i < x.size(); ++i)
		for (unsigned int j = 0; j < x[i].size(); ++j)
			out[i].push_back(round(x[i][j]));
	return out;
}

// ---------------------------------------------------------------------------

#pragma hdrstop

#include "FuzzyNumber.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

int FuzzyNumber::AppendNumberToFile() {
	FILE *out;
	if ((out = fopen(append_file_name, "a")) == NULL) {
		fprintf(stderr, "Cannot create output file.\n");
		return 0;
	}
	fprintf(out, "%lf %lf %lf\n", this->m, this->a, this->b);
	fclose(out);
	return 1;
}



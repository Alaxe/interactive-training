#include "topsecret.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define PASSWORD "T3owDde1Up2c3GXU69lm"

namespace Grader {
	static std::vector<int> a;
	static int qLeft;
	FILE *in;
	FILE *out;
}

bool is_less(int i, int k) {
	if ((i < 0) || (i >= (int)(Grader::a.size()) - 1)) {
		fprintf(Grader::out, "Invalid question asked.\n");
		std::exit(0);
	}
	if ((k < 0) || (k > (int)(Grader::a.size()) - 1)) {
		fprintf(Grader::out, "Invalid question asked.\n");
		std::exit(0);
	}
	if (Grader::qLeft == 0) {
		fprintf(Grader::out, "Too many questions asked.\n");
		std::exit(0);
	}
	Grader::qLeft--;
	return Grader::a[i] < k;
}

int main() {
	Grader::in = fopen(PASSWORD ".in", "r");
	Grader::out = fopen(PASSWORD ".out", "w");

	int n, q;
	assert(fscanf(Grader::in, "%i %i", &n, &q) == 2);
	Grader::qLeft = q;
	Grader::a.resize(n + 1);

	for (unsigned i = 0;i < Grader::a.size();i++) {
		assert(fscanf(Grader::in, "%i", &Grader::a[i]) == 1);
	}

	int ans = find_position(n, q);
	if (ans == Grader::a[n]) {
		fprintf(Grader::out, "Output is correct.\n");
	} else {
		fprintf(Grader::out, "Output isn't correct.\n");
	}

	fclose(Grader::in);
	fclose(Grader::out);
}

#include "topsecret.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>

namespace Grader {
	static std::vector<int> a;
	static int qLeft;
}

bool is_less(int i, int k) {
	if ((i < 0) || (i >= (int)(Grader::a.size()) - 1)) {
		printf("Invalid question asked.\n");
		std::exit(0);
	}
	if ((k < 0) || (k > (int)(Grader::a.size()) - 1)) {
		printf("Invalid question asked.\n");
		std::exit(0);
	}
	if (Grader::qLeft == 0) {
		printf("Too many questions asked.\n");
		std::exit(0);
	}
	Grader::qLeft--;
	return Grader::a[i] < k;
}

int main() {
	int n, q;
	assert(scanf("%i %i", &n, &q) == 2);
	Grader::qLeft = q;
	Grader::a.resize(n + 1);

	for (unsigned i = 0;i < Grader::a.size();i++) {
		assert(scanf("%i", &Grader::a[i]) == 1);
	}

	int ans = find_position(n, q);
	if (ans == Grader::a[n]) {
		printf("Output is correct.\n");
	} else {
		printf("Output isn't correct.\n");
	}
}

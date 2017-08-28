#include "findnumber.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

namespace Grader {
	static const size_t MAX_N = 1e5;

	static int nums[MAX_N];
	static int seekedInd; 

	static int numCnt;
	static int allowedQ;
	static int madeQ = 0;

	static void input() {
		assert(scanf("%i %i %i", &numCnt, &seekedInd, &allowedQ) == 3);
		for (int i = 0;i < numCnt;i++) {
			assert(scanf("%i", &nums[i]) == 1);
		}
	}
	static void print_verdict(const char *message) {
		printf("%s\n", message);
	}

	static void grade_answer(int answer) {
		if (answer != seekedInd) {
			print_verdict("Output isn't correct.");
		} else {
			print_verdict("Output is correct.");
		}
	}
}

int get_number(int i) {
	Grader::madeQ++;
	if ((i < 0) || (i >= Grader::numCnt)) {
		Grader::print_verdict("Invalid question asked.");
		exit(0);
	}
	if (Grader::madeQ > Grader::allowedQ) {
		Grader::print_verdict("Too many questions asked.");
		exit(0);
	}
	return Grader::nums[i];
}

int main() {
	Grader::input();
	int solution = find_index(Grader::numCnt, Grader::nums[Grader::seekedInd]);
	Grader::grade_answer(solution);
}

#include "findnumber.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define PASSWORD "616TwMP5owSS2AXkFVW3"

namespace Grader {
	static const size_t MAX_N = 1e5;

	static int nums[MAX_N];
	static int seekedInd; 

	static int numCnt;
	static int allowedQ;
	static int madeQ = 0;

	static FILE *in;
	static FILE *out;

	static void open_files() {
		in = fopen(PASSWORD ".in", "r");
		out = fopen(PASSWORD ".out", "w");
	}

	static void input() {
		assert(fscanf(in, "%i %i %i", &numCnt, &seekedInd, &allowedQ) == 3);
		for (int i = 0;i < numCnt;i++) {
			assert(fscanf(in, "%i", &nums[i]) == 1);
		}
	}
	static void print_verdict(const char *message) {
		fprintf(out, "%s\n", message);
		fclose(in);
		fclose(out);
		std::exit(0);
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
	}
	if (Grader::madeQ > Grader::allowedQ) {
		Grader::print_verdict("Too many questions asked.");
	}
	return Grader::nums[i];
}

int main() {
	Grader::open_files();
	Grader::input();
	int solution = find_index(Grader::numCnt, Grader::nums[Grader::seekedInd]);
	Grader::grade_answer(solution);
}

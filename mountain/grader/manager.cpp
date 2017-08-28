#include <cstdio>
#include <vector>
#include <cassert>

#include "avi.h"
#include "bobi.h"

namespace Manager {
	void compute(FILE *pipe) {
		int n, m;
		assert(scanf("%i %i", &n, &m) == 2);
		std::vector<int> a;
		a.resize(n);

		for (int i = 0;i < a.size();i++) {
			assert(scanf("%i", &a[i]) == 1);
		}
		std::vector<bool> b = encode(a, m);
	
		if (b.size() > m) {
			fprintf(pipe, "-1 -1\n");
		} else {
			fprintf(pipe, "%i %i\n", n, b.size());
			for (int i = 0;i < b.size();i++) {
				fprintf(pipe, "%u ", (unsigned)(b[i]));
			}
			fprintf(pipe, "\n");
		}
	}
	void retrieve(FILE *pipe) {
		int n, m;
		assert(fscanf(pipe, "%i %i", &n, &m) == 2);
		if (n > 0) {
			std::vector<bool> b(m);
			for (int i = 0;i < b.size();i++) {
				unsigned t;
				assert(fscanf(pipe, "%u", &t) == 1);
				b[i] = t;
			}

			std::vector<int> a = decode(b, n);
			for (int i = 0;i < a.size();i++) {
				printf("%i ", a[i]);
			}
			printf("\n");
		} else {
			printf("Too many bits used\n");
		}
	}
}


int main(int argc, char **argv) {
	if (argc < 3) {
		return 1;
	}
	if (argv[1][0] == '0') {
		FILE *pipe = fopen(argv[2], "w");
		if (pipe == nullptr) {
			return 1;
		}

		Manager::compute(pipe);

		fclose(pipe);
	} else if (argv[1][0] == '1') {
		FILE *pipe = fopen(argv[2], "r");
		if (pipe == nullptr) {
			return 1;
		}

		Manager::retrieve(pipe);

		fclose(pipe);
	} else {
		return 1;
	}
}

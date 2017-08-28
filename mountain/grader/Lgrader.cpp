#include <cstdio>
#include <vector>

#include "avi.h"
#include "bobi.h"

int main() {
	int n, m;
	scanf("%i %i", &n, &m);

	std::vector<int> aIn;
	aIn.resize(n);
	for (int i = 0;i < aIn.size();i++) {
		scanf("%i", &aIn[i]);
	}

	std::vector<bool> b = encode(aIn, m);
	if (b.size() > m) {
		printf("Too many bits used\n");
		return 0;
	}

	for (int i = 0;i < b.size();i++) {
		printf("%u ", (unsigned)(b[i]));
	}
	printf("\n");
	std::vector<int> aOut = decode(b, n);
	for (int i = 0;i < aOut.size();i++) {
		printf("%i ", aOut[i]);
	}
	printf("\n");
}

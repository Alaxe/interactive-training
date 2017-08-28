#include "sumqueries.h"
#include <vector>
#include <cstdio>

#define PASSWORD "kHql8jBjhdm8llwZJ0v0"

int main() {
	FILE *in = fopen(PASSWORD ".in", "r");
	FILE *out = fopen(PASSWORD ".out", "w");

	int n, q;
	fscanf(in, "%i %i", &n, &q);

	std::vector<int> a(n);
	for (int i = 0;i < n;i++) {
		fscanf(in, "%i", &a[i]);
	}
	init(a);

	for (int i = 0;i < q;i++) {
		int l, r;
		fscanf(in, "%i %i", &l, &r);
		fprintf(out, "%lli\n", sum(l, r));
	}
}

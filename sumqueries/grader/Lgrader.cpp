#include "sumqueries.h"
#include <vector>
#include <cstdio>

int main() {
	int n, q;
	scanf("%i %i", &n, &q);

	std::vector<int> a(n);
	for (int i = 0;i < n;i++) {
		scanf("%i", &a[i]);
	}
	init(a);

	for (int i = 0;i < q;i++) {
		int l, r;
		scanf("%i %i", &l, &r);
		printf("%lli\n", sum(l, r));
	}
}

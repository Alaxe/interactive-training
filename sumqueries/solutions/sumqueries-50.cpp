#include "sumqueries.h"

std::vector<int> a;

void init(std::vector<int> pA) {
	a = pA;
}

long long sum(int l, int r) {
	long long ans = 0;
	for (int i = l;i <= r;i++) {
		ans += a[i];
	}
	return ans;
}

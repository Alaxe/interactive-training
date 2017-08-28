#include "sumqueries.h"

std::vector<long long> sums;

void init(std::vector<int> a) {
	sums.push_back(0);
	for (int i = 0;i < a.size();i++) {
		sums.push_back(sums.back() + a[i]);
	}
}

long long sum(int i, int j) {
	return sums[j + 1] - sums[i];
}

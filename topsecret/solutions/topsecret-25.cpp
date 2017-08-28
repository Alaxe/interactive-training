#include "topsecret.h"
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> a;

int find_position(int n, int q) {
	for (int i = 0;i < n;i++) {
		int low = 0;
		int high = n + 1;
		while (high - low > 1) {
			int m = (low + high) / 2;
			if (is_less(i, m)) {
				high = m;
			} else {
				low = m;
			}
		}
		a.push_back(low);
	}
	std::sort(a.begin(), a.end());
	for (int i = 1;i < a.size();i++) {
		if (a[i] > a[i - 1] + 1) {
			return a[i - 1] + 1;
		}
	}
	return n;
}

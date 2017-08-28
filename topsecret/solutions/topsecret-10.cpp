#include "topsecret.h"
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> a;

int find_position(int n, int q) {
	for (int i = 0;i < n;i++) {
		a.push_back(n);
		for (int j = 1;j <= n;j++) {
			if (is_less(i, j)) {
				a[i] = j - 1;
				break;
			}
		}
	}
	std::sort(a.begin(), a.end());
	for (int i = 1;i < a.size();i++) {
		if (a[i] > a[i - 1] + 1) {
			return a[i - 1] + 1;
		}
	}
	return n;
}

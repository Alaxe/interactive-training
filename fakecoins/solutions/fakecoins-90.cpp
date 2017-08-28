#include "fakecoins.h"
#include <algorithm>

int find_heavier(int N) {
	std::vector<int> h;
	std::vector<int> l;

	for (int b = 0;b < 10;b++) {
		h.clear();
		l.clear();
		for (int i = 0;i < N;i++) {
			if (i & (1U << b)) {
				h.push_back(i);
			} else {
				l.push_back(i);
			}
		}
		int r = compare_coins(h, l);
		if (r == 1) {
			break;
		} else if (r == -1) {
			std::swap(h, l);
			break;
		}
	}

	while (h.size() > 1) {
		int k = h.size() / 2;
		std::vector<int> a;
		std::vector<int> b;
		for (int i = 0;i < k;i++) {
			a.push_back(h[i]);
			b.push_back(h[i + k]);
		}
		int res = compare_coins(a, b);
		if (res == 0) {
			return h.back();
		} else if (res == 1) {
			h = a;
		} else {
			h = b;
		}
	}
	return h[0];
}

#include "topsecret.h"
#include <vector>

std::vector<int> lb;
std::vector<int> ub;
int n;

void gen_bounds() {
	for (int i = 0;i < n;i++) {
		lb.push_back(0);
		ub.push_back(n + 1);
	}
}

bool is_ls(int a) {
	int lessCnt = 0;
	for (int i = 0;i < n;i++) {
		if (lb[i] >= a) {
			continue;
		} else if (ub[i] < a) {
			lessCnt++;
			continue;
		} else {
			if (is_less(i, a)) {
				ub[i] = a - 1;
				lessCnt++;
			} else {
				lb[i] = a;
			}
		}
	}
	return lessCnt < a;
}

int find_position(int N, int q) {
	n = N;

	gen_bounds();

	int low = 0;
	int high = n + 1;
	while (high - low > 1) {
		int m = (high + low) / 2;
		if (is_ls(m)) {
			high = m;
		} else {
			low = m;
		}
	}
	return low;
}

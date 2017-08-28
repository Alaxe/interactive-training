#include "bobi.h"

static std::vector<bool>::iterator curBit;

static bool pop_bit() {
	return *(curBit++);
}

static unsigned pop_bits(int cnt) {
	unsigned ans = 0;
	for (int i = 0;i < cnt;i++) {
		ans += (pop_bit() << i);
	}
	return ans;
}



std::vector<int> decode(std::vector<bool> b, int n) {
	curBit = b.begin();

	std::vector<int> a;
	a.push_back(pop_bits(32));

	unsigned curLeft = 0;
	unsigned cur = 0;

	for (int i = 1;i < n;i++) {
		if (curLeft == 0) {
			cur = pop_bits(8);
			curLeft = 5;
		}
		a.push_back(a.back() + cur % 3 - 1);

		cur /= 3;
		curLeft--;
	}
	return a;
}

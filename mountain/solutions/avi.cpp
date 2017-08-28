#include "avi.h"

static std::vector<bool> b;

static void push_bit(bool v) {
	b.push_back(v);
}

static void push_bits(int cnt, unsigned mask) {
	for (int i = 0;i < cnt;i++) {
		push_bit((mask & (1U << i)) > 0);
	}
}

std::vector<bool> encode(std::vector<int> a, int m_max) {
	push_bits(32, (unsigned)(a[0]));

	unsigned curVal = 0;
	unsigned curPow = 1;
	for (int i = 1;i < a.size();i++) {
		unsigned v = a[i] + 1 - a[i - 1];
		curVal += curPow * v;
		curPow *= 3;
		if (curPow == 243) {
			push_bits(8, curVal);
			curVal = 0;
			curPow = 1;
		}
	}
	if (curPow > 1) {
		push_bits(8, curVal);
	}
	
	return b;
}

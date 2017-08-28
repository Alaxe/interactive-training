#include "findnumber.h"

int find_index(int N, int a) {
	int low = 0;
	int high = N;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (get_number(mid) > a) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return low;
}

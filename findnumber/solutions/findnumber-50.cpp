#include "findnumber.h"

int find_index(int N, int a) {
	for (int i = 0;i < N;i++) {
		if (get_number(i) == a) {
			return i;
		}
	}
}

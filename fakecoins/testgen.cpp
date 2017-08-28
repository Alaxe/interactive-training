#include <bits/stdc++.h>

using namespace std;
const int MAXN = (1 << 20);

mt19937 mt(time(NULL));

int n = 1024, q = 30;
int a, b;

void generate_random_test()
{
	a = rand() % (n - 1);
	b = a + 1 + rand() % (n - a - 1);
	if(mt() % 2) swap(a, b);
}

string m_to_string(int a)
{
	string res = "";
	for(int x = 0; x < 1; x++)
	{
		res += (char)((a % 10) + '0');
		a /= 10;
	}

	reverse(res.begin(), res.end());
	return res;
}

void print_test()
{
	cout << n << " " << q << endl;
	cout << a << " " << b << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int test_cnt = 0; test_cnt <= 4; test_cnt++)
	{
		string file_name = "subtask2-" + m_to_string(test_cnt) + ".in";
		freopen(file_name.c_str(), "w", stdout);
		generate_random_test();
		print_test();
	}

	return 0;
}

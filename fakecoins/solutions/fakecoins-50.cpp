#include <bits/stdc++.h>
//#include "Lgrader.cpp"
#include "fakecoins.h"

using namespace std;
const int MAXN = (1 << 10);

int query(vector<int> li)
{
	vector<int> l_half, r_half;
	for(int i = 0; i < (int)li.size() / 2; i++) l_half.push_back(li[i]);
	for(int i = (int)li.size() / 2; i < (int)li.size(); i++) r_half.push_back(li[i]);
	return compare_coins(l_half, r_half);
}

int rec(vector<int> li)
{
	if(li.size() == 1)
		return li[0]; 

	vector<int> l_half, r_half;
	for(int i = 0; i < (int)li.size() / 2; i++) l_half.push_back(li[i]);
	for(int i = (int)li.size() / 2; i < (int)li.size(); i++) r_half.push_back(li[i]);
	if(query(li) == -1) return rec(r_half);
	else return rec(l_half);

}

int find_heavier(int n)
{
	vector<int> li;
	for(int i = 0; i < n; i++) li.push_back(i);
	
	int last_q = 42;
	while((last_q = query(li)) == 0) random_shuffle(li.begin(), li.end());

	vector<int> l_half, r_half;
	for(int i = 0; i < (int)li.size() / 2; i++) l_half.push_back(li[i]);
	for(int i = (int)li.size() / 2; i < (int)li.size(); i++) r_half.push_back(li[i]);
	if(last_q == -1) return rec(r_half);
	else return rec(l_half);
}

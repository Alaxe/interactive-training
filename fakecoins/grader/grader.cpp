#include "fakecoins.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <bitset>

#define PASSWORD "DTmsaWqQkTXSGwSaKwXh"

namespace Grader 
{
	static int n;
	static int lighter, heavier;
	static int qLeft;	

	static std::bitset<(1 << 10)> used;
	static std::bitset<(1 << 10)> impossible[(1 << 10)];

	static FILE *in;
	static FILE *out;


	static void open_files() {
		in = fopen(PASSWORD ".in", "r");
		out = fopen(PASSWORD ".out", "w");
	}

	static void terminate(const char *msg) {
		fprintf(out, msg);
		fclose(in);
		fclose(out);
		exit(0);
	}

	static void invalid_question()	 
	{
		terminate("Invalid question asked.\n");
	}

	static void too_many_questions()
	{
		terminate("Too many questions asked.\n");
	}
}

int compare_coins(std::vector<int> a, std::vector<int> b)
{
	Grader::used.reset();

	for(int coin: a)
	{
		if(coin < 0 || coin >= Grader::n) Grader::invalid_question();
		if(Grader::used[coin]) Grader::invalid_question();
		Grader::used[coin] = true;
	}

	for(int coin: b)
	{
		if(coin < 0 || coin >= Grader::n) Grader::invalid_question();
		if(Grader::used[coin]) Grader::invalid_question();
		Grader::used[coin] = true;
	}

	if(a.size() != b.size()) Grader::invalid_question();
	if (Grader::qLeft == 0) Grader::too_many_questions();
	Grader::qLeft--;

	if(Grader::heavier == -1 || Grader::lighter == -1)
	{
		bool ok = 0;
		for(int i: a)
			for(int j: a)
				if(i < j && !Grader::impossible[i][j])
					ok = 1;

		for(int i: b)
			for(int j: b)
				if(i < j && !Grader::impossible[i][j])
					ok = 1;

		if(ok)
		{
			for(int i: a)
				for(int j: b)
				{
					Grader::impossible[i][j] = true;
					Grader::impossible[j][i] = true;
				}

			return 0;
		}

		for(int i: a)
			for(int j: b)
				if(!Grader::impossible[i][j])
				{
					Grader::heavier = i;
					Grader::lighter = j;
				}
	}

	int weight_a = 0, weight_b = 0;
	for(int coin: a) 
		if(coin == Grader::heavier) weight_a += 11; 
		else if(coin == Grader::lighter) weight_a += 9; 
		else weight_a += 10; 

	for(int coin: b) 
		if(coin == Grader::heavier) weight_b += 11; 
		else if(coin == Grader::lighter) weight_b += 9; 
		else weight_b += 10; 

	if(weight_a < weight_b) return -1;
	if(weight_a == weight_b) return 0;
	return 1;
}

int main() 
{
	Grader::open_files();
	int n, q;
	assert(fscanf(Grader::in, "%i %i", &n, &q) == 2);
	Grader::qLeft = q;
	Grader::n = n;

	int mode;
	assert(fscanf(Grader::in, "%i", &mode) == 1);
	if (mode == 0)
	{
		assert(fscanf(Grader::in, "%i %i", &Grader::lighter, &Grader::heavier) == 2);
	}
	else
	{
		Grader::lighter = -1;
		Grader::heavier = -1;
	}

	for(int i = 0; i < n; i++) 
		Grader::impossible[i].reset();

	int ans = find_heavier(n);
	if (ans == Grader::heavier) Grader::terminate("Output is correct.\n");
	else Grader::terminate("Output isn't correct.\n");
}

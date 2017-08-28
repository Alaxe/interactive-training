#include "fakecoins.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <bitset>

namespace Grader 
{
	static int n;
	static int lighter, heavier;
	static int qLeft;	
	
	static std::bitset<(1 << 10)> used;

	static void invalid_question()	 
	{
		printf("Invalid question asked.\n");
		std::exit(0);
	}

	static void too_many_questions()
	{
		printf("Too many questions asked.\n");
		std::exit(0);
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
	int n, q;
	assert(scanf("%i %i", &n, &q) == 2);
	Grader::qLeft = q;
	Grader::n = n;

	assert(scanf("%i %i", &Grader::lighter, &Grader::heavier) == 2);

	int ans = find_heavier(n);
	if (ans == Grader::heavier) printf("Output is correct.\n");
	else printf("Output isn't correct.\n");
}

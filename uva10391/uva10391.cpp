#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10391"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

unsigned int BKDRHash(const char str[]){

	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str){
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF)%1200 ;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	return 0;
}
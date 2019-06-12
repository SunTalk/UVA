#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11727"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE,Case = 1;
	scanf("%d",&CASE);
	int table[5];

	while( CASE-- ){
		scanf("%d %d %d",&table[0],&table[1],&table[2]);
		sort(&table[0],&table[3]);
		printf("Case %d: %d\n",Case++,table[1]);
	}

	return 0;
}
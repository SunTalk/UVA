#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11462"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 2000000

int table[MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	USE_CPPIO();

	int num;
	while( cin >> num ){
		for(int i = 0 ; i < num ; i++ )
			cin >> table[i];
		sort(&table[0],&table[num]);
		for(int i = 0 ; i < num ; i++ )
			cout << table[i] << ( i == num-1 ? '\n':' ' ) ;
	}

	return 0;
}
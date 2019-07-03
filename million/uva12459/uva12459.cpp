#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12459"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	USE_CPPIO();

	long long table[85];
	long long mom = 1,dad = 0;
	long long num;

	for(int i = 1 ; i < 85 ; i++ ){
		table[i] = mom+dad;
		num = mom;
		mom = mom+dad;
		dad = num;
	}

	while( cin >> num && num )
		cout << table[num] << endl ;

	return 0;
}
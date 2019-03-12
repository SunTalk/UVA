#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11401"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAX 1000000
#define ULL unsigned long long

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	ULL table[MAX+5];
	ULL one,two;
	one = two = 1;
	table[0] = table[1] = table[2] = table[3] = 0;
	
	for(ULL i = 4 ; i <= MAX ; i++ ){
		
		table[i] = table[i-1] + one*two;
		two++;
		i++;
		table[i] = table[i-1] + one*two;
		one++;

	}

	ULL num;
	while( cin >> num ){
		if( num < 3 )
			break;
		cout << table[num] << endl;
	}

	return 0;
}
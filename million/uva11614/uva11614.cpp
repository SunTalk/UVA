#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11614"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int TIMES;
	scanf("%d",&TIMES);

	long long num;
	while( TIMES-- ){

		cin >> num;
		num = num*2;
		long long tmp = sqrt(num)+1;
		
		for(long long i = tmp ; i >= 0 ; i-- ){
			if( i * (i+1) <= num ){
				cout << i << endl;
				break;
			}
		}

	}

	return 0;
}
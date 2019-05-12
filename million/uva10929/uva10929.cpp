#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10929"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string num;

	while( cin >> num ){

		if( num == "0" )
			break;

		int ans = 0;
		for(int i = 0 ; i < num.size() ; i++ ){
			if( i%2 == 0 )
				ans = ans + num[i] - '0';
			else
				ans = ans - num[i] + '0';
		}

		if( ans%11 == 0 )
			cout << num << " is a multiple of 11.\n" ;
		else
			cout << num << " is not a multiple of 11.\n" ;

	}

	return 0;
}
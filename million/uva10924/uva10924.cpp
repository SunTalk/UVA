#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10924"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isPrime(int k){
	for(int i = 2 ; i <= sqrt(k) ; i++ )
		if( k%i == 0 )
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int ans;
	while( cin >> str ){
		
		ans = 0;
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] >= 'a' && str[i] <= 'z' )
				ans = ans + str[i] - 'a' + 1;
			if( str[i] >= 'A' && str[i] <= 'Z' )
				ans = ans + str[i] - 'A' + 27;
		}

		if( isPrime(ans) )
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");

	}

	return 0;
}
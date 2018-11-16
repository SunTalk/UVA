#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11582"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define ULL unsigned long long
#define MAX 10005

int POW_MOD( ULL x, ULL n, ULL k){

	if( n == 0 )
		return 1;
	ULL tmp = POW_MOD(x,n/2,k);
	ULL ans = (ULL)tmp*tmp%k;
	if( n % 2 == 1 )
		ans = ans*x%k;
	return (int)ans;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	USE_CPPIO();

	int times,power,i;
	ULL one,two;
	int Fibonacci[MAX];

	cin >> times;
	while( times-- ){
		cin >> one >> two >> power;

		Fibonacci[0] = 0;
		Fibonacci[1] = 1%power;
		for( i = 2 ; i <= MAX ; i++ ){
			Fibonacci[i] = ( Fibonacci[i-1] + Fibonacci[i-2] ) % power;
			if( Fibonacci[i] == Fibonacci[1] && Fibonacci[i-1] == Fibonacci[0] )
				break;
		}
		int tmp = i-1;
		int ans = POW_MOD(one%tmp,two,(ULL)tmp);

		cout << Fibonacci[ans] << endl;
	}

	return 0;
}
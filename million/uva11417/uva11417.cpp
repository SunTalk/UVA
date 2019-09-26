#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11417"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 500

int GCD(int a, int b){
	return a%b ? GCD(b,a%b):b;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	int ans = 0;
	int table[MAXN+5];
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		for(int j = 1 ; j < i ; j++ )
			ans += GCD(i,j);
		table[i] = ans;
	}

	int num;
	while( ~scanf("%d",&num) && num )
		printf("%d\n",table[num]);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10019"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int bits(int num){
	int ans = 0;
	while( num ){
		ans += num%2;
		num /= 2;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int num,a,b;
	while( kase-- ){
	
		scanf("%d",&num);
		a = bits(num);
		b = 0;
		while( num ){
			b += bits(num%10);
			num /= 10;
		}
		printf("%d %d\n",a,b);
		
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12563"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int song,time,sec;
	int bag[MAXN+5];

	for(int k = 1 ; k <= kase ; k++ ){

		scanf("%d %d",&song,&time);
		memset(bag,0x8f,sizeof(bag));
		bag[0] = 0;
		for(int i = 0 ; i < song ; i++ ){
			scanf("%d",&sec);
			for(int j = time-1 ; j >= sec ; j-- )
				bag[j] = max(bag[j], bag[j-sec]+1 );
		}

		int ans;
		for(int i = ans = time-1 ; i >= 0 ; i-- )
			if( bag[i] > bag[ans] )
				ans = i;

		printf("Case %d: %d %d\n", k, bag[ans]+1 , ans+678 );

	}

	return 0;
}
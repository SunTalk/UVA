#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1260"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int A[MAXN+5];
	int num,ans;

	while( kase-- ){

		scanf("%d",&num);

		ans = 0;

		scanf("%d",&A[0]);
		for(int i = 1 ; i < num ; i++ ){
			scanf("%d", &A[i]);
			for(int j = i-1 ; j >= 0 ; j-- )
				if( A[i] >= A[j] )
					ans++;
		}

		printf("%d\n",ans );

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11204"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	int N,M;
	int table[50];
	int tmp,ans;

	while( kase-- ){
		
		memset(table,0,sizeof(table));
		scanf("%d %d",&N,&M);
		for(int i = 0 ; i < M ; i++ ){
			for(int j = 0 ; j < N ; j++ ){
				scanf("%d",&tmp);
				if( tmp == 1 )
					table[j]++;
			}
		}

		ans = 1;
		for(int i = 0 ; i < N ; i++ )
			if( table[i] > 1 )
				ans *= table[i];

		printf("%d\n",ans );

	}

	return 0;
}
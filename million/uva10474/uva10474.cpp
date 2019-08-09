#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10474"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int N,Q,tmp,ans;
	int table[MAXN+5];

	int kase = 1;

	while( ~scanf("%d %d",&N,&Q) && N ){

		for(int i = 0 ; i < N ; i++ )
			scanf("%d",&table[i]);
		sort(table,table+N);

		printf("CASE# %d:\n",kase++ );
		for(int j = 0 ; j < Q ; j++ ){
			
			scanf("%d",&tmp);
			ans = lower_bound(table,table+N,tmp)-table;
			if( table[ans] == tmp )
				printf("%d found at %d\n", tmp,ans+1);
			else
				printf("%d not found\n", tmp );
		
		}

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10305"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int n,m,a,b;
	int table[MAXN+5][MAXN+5];
	int check[MAXN+5];
	int ans[MAXN+5];

	while( ~scanf("%d %d",&n,&m) && n ){

		memset(table,0,sizeof(table));
		memset(check,0,sizeof(check));
		memset(ans,0,sizeof(ans));

		for(int i = 0 ; i < m ; i++ ){
			scanf("%d %d",&a,&b);
			if( table[a][b] == 0 ){
				table[a][b] = 1;
				check[b]++;
			}
		}

		for(int i = 1 ; i <= n ; i++ ){
			int k = 1;
			while( check[k] )
				k++;
			ans[i] = k;
			check[k] = -1;
			for(int j = 1 ; j <= n ; j++ )
				if( table[k][j] )
					check[j]--;
		}

		for(int i = 1 ; i <= n ; i++ )
			printf("%d%c", ans[i],i==n?'\n':' ');

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "907"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 600
#define MAXK 300

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5][MAXK+5];
	int camp,night;

	while( ~scanf("%d %d",&camp,&night) ){
		
		memset(table,0,sizeof(table));

		for(int i = 1 ; i <= camp+1 ; i++ ){
			scanf("%d",&table[i][0]);
			table[i][0] = table[i-1][0] + table[i][0];
		}

		for(int j = 1 ; j <= night ; j++ ){
			for(int i = 1 ; i <= camp+1 ; i++ ){
				table[i][j] = INT_MAX;
				for(int k = 1 ; k <= i ; k++ ){
					table[i][j] = min(table[i][j],max(table[k][j-1],table[i][0]-table[k][0]));
				}
			}
		}

		printf("%d\n",table[camp+1][night] );

	}
    
	return 0;
}
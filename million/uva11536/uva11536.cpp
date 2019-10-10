#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int CASE = 1;
	int N,M,K;
	int check[105];

	while( kase-- ){
		
		printf("Case %d: ",CASE++);

		scanf("%d %d %d",&N,&M,&K);
		table[1] = 1, table[2] = 2, table[3] = 3;
		for(int i = 4 ; i <= N ; i++)
			table[i] = ((table[i-1] + table[i-2] + table[i-3])%M)+1;

		memset(check,0,sizeof(check));
		int tmp = K;
		int ans = INT_MAX;
		for(int i = 1 ; i <= N ; i++ ){
			if( 1 <= table[i] && table[i] <= K ){
				if( check[table[i]] == 0 )
					tmp--;
				check[table[i]] = i;
				if( tmp == 0 ){
					int LL = INT_MAX;
					int RR = INT_MIN;
					for(int j = 1 ; j <= K ; j++ ){
						LL = min(LL,check[j]);
						RR = max(RR,check[j]);
					}
					ans = min(ans,RR-LL+1);
				}
			}
		}

		if( tmp )
			printf("sequence nai\n");
		else
			printf("%d\n",ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20

int main(int argc, char const *argv[])
{

	int num;
	int tmp[MAXN+5];
	int fact[MAXN+5];
	int now[MAXN+5];
	int LCS[MAXN+5][MAXN+5];

	scanf("%d",&num);
	for(int i = 1 ; i <= num ; i++ )
		scanf("%d",&tmp[i]);
	for(int i = 1 ; i <= num ; i++ )
		fact[tmp[i]] = i;

	while( ~scanf("%d",&tmp[1]) ){

		for(int i = 2 ; i <= num ; i++ )
			scanf("%d",&tmp[i]);
		for(int i = 1 ; i <= num ; i++ )
			now[tmp[i]] = i;

		memset(LCS,0,sizeof(LCS));
		for(int i = 1 ; i <= num ; i++ ){
			for(int j = 1 ; j <= num ; j++ ){
				if( now[i] == fact[j] )
					LCS[j][i] = LCS[j-1][i-1]+1;
				else
					LCS[j][i] = max(LCS[j-1][i],LCS[j][i-1]);
			}
		}

		printf("%d\n",LCS[num][num]);

	}

	return 0;
}
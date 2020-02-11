#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int bag[MAXN+10][MAXN+10];
int conV[MAXN+10],infV[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int kind,num;
	while( kase-- ){

		scanf("%d %d",&kind,&num);
		for(int i = 0 ; i < kind ; i++ )
			scanf("%d %d",&conV[i],&infV[i]);

		for(int i = 0 ; i <= num ; i++ )
			for(int j = 0 ; j <= num ; j++ )
				bag[i][j] = INF;
		bag[0][0] = 0;

		for(int k = 0 ; k < kind ; k++ )
			for(int i = conV[k] ; i <= num ; i++ )
				for(int j = infV[k] ; j <= num ; j++ )
					if( bag[i-conV[k]][j-infV[k]] != INF )
						bag[i][j] = min(bag[i][j],bag[i-conV[k]][j-infV[k]]+1);

		int ans = INF;
		for(int i = 0 ; i <= num ; i++ )
			for(int j = 0 ; j <= num ; j++ )
				if( i*i+j*j == num*num )
					ans = min(ans,bag[i][j]);

		if( ans == INF ) printf("not possible\n");
		else printf("%d\n",ans);

	}

	return 0;
}
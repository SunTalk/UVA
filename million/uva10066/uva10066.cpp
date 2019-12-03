#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int A,B;
	int table[MAXN+5][2];
	int LCS[MAXN+5][MAXN+5];
	int kase = 1;
	while( ~scanf("%d %d",&A,&B) && A ){

		for(int i = 1 ; i <= A ; i++ )
			scanf("%d",&table[i][0]);
		for(int i = 1 ; i <= B ; i++ )
			scanf("%d",&table[i][1]);

		memset(LCS,0,sizeof(LCS));

		for(int i = 1 ; i <= A ; i++ ){
			for(int j = 1 ; j <= B ; j++ )
				if( table[i][0] == table[j][1] )
					LCS[i][j] = LCS[i-1][j-1]+1;
				else
					LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
		}

		printf("Twin Towers #%d\n", kase++);
		printf("Number of Tiles : %d\n\n", LCS[A][B]);

	}

	return 0;
}
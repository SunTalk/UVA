#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool table[MAXN+10][5];
int L[MAXN+10],R[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int N,K,num,tmp;
	string str;
	while( kase-- ){

		scanf("%d %d",&N,&K);
		memset(table,0,sizeof(table));
		for(int i = 0 ; i < K ; i++ ){
			
			scanf("%d",&num);
			for(int j = 0 ; j < num ; j++ )
				scanf("%d",&L[j]);
			for(int j = 0 ; j < num ; j++ )
				scanf("%d",&R[j]);
			cin >> str;

			if( str ==  "=" ){
				for(int j = 0 ; j < num ; j++ )
					table[L[j]][1] = table[R[j]][1] = true;
			}
			else if( str == "<" ){
				for(int j = 0 ; j < num ; j++ )
					table[L[j]][2] = table[R[j]][3] = true;
			}
			else if( str == ">" ){
				for(int j = 0 ; j < num ; j++ )
					table[L[j]][3] = table[R[j]][2] = true;
			}

		}

		for(int i = 1 ; i <= N ; i++ ){
			if( table[i][1] || table[i][2] && table[i][3] )
				table[i][0] = true;
		}

		int ans = -1;
		for(int i = 1 ; i <= N ; i++ ){
			if( table[i][0] == false ){
				if( ans == -1 ) ans = i;
				else ans = 0;
			}
		}

		printf("%d\n",ans>0?ans:0);
		if( kase ) printf("\n");

	}

	return 0;
}
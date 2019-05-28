#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1175"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int MAN[MAXN+5][MAXN+5];
int WOMAN[MAXN+5][MAXN+5];
int ALREADY[MAXN+5];
int NEXT[MAXN+5];
int ans[MAXN+5];


int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int people,tmp;

	while( CASE-- ){
		scanf("%d",&people);
		for(int i = 1 ; i <= people ; i++ ){
			for(int j = 1 ; j <= people ; j++ ){
				scanf("%d",&WOMAN[i][j]);
			}
		}
		for(int i = 1 ; i <= people ; i++ ){
			for(int j = 1 ; j <= people ; j++ ){
				scanf("%d",&tmp);
				MAN[i][tmp] = j;
			}
		}

		queue <int> mate;
		for(int i = 1 ; i <= people ; i++ ){
			mate.push(i);
			NEXT[i] = 1;
			ALREADY[i] = 0;
			ans[i] = 0;
		}

		while( !mate.empty() ){
			
			tmp = mate.front();
			
			if( ALREADY[ WOMAN[tmp][ NEXT[tmp] ] ] != 0 ){
				if( MAN[ WOMAN[tmp][ NEXT[tmp] ] ][tmp] < MAN[ WOMAN[tmp][ NEXT[tmp] ] ][ ALREADY[ WOMAN[tmp][ NEXT[tmp] ] ] ] ){
					ans[tmp] = WOMAN[tmp][ NEXT[tmp] ];
					mate.push(ALREADY[ WOMAN[tmp][ NEXT[tmp] ] ]);
					ALREADY[ WOMAN[tmp][ NEXT[tmp] ] ] = tmp ;
				}
				else
					mate.push(tmp);
			}
			else{
				ans[tmp] = WOMAN[tmp][ NEXT[tmp] ];
				ALREADY[ WOMAN[tmp][ NEXT[tmp] ] ] = tmp ;
			}

			NEXT[tmp]++;
			mate.pop();
			
		}
		for(int i = 1 ; i <= people ; i++ )
			printf("%d\n",ans[i] );
		if( CASE != 0 )
			printf("\n");
	}

	return 0;
}
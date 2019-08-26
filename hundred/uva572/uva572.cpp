#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "572"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

char table[MAXN+5][MAXN+5];
void DFS(int a, int b){
	table[a][b] = '*';
	for(int i = -1 ; i <= 1 ; i++ )
		for(int j = -1 ; j <= 1 ; j++ )
			if( table[a+i][b+j] == '@' )
				DFS(a+i,b+j);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int x,y,ans;

	while( ~scanf("%d %d\n",&x,&y) && x ){

		for(int i = 0 ; i < x ; i++ ){
			for(int j = 0 ; j < y ; j++ )
				scanf("%c",&table[i][j]);
			getchar();
		}

		ans = 0;
		for(int i = 0 ; i < x ; i++ ){
			for(int j = 0 ; j < y ; j++ ){
				if( table[i][j] == '@' ){
					ans++;
					DFS(i,j);
				}
			}
		}

		printf("%d\n",ans );

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10189"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

char table[MAXN+5][MAXN+5];
int ans[MAXN+5][MAXN+5];
int a[8] = {-1,0,1,-1,1,-1,0,1};
int b[8] = {-1,-1,-1,0,0,1,1,1};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int x,y;
	int Case = 1;

	while( ~scanf("%d %d\n",&x,&y) && (x|y) ){
		memset(ans,0,sizeof(ans));

		for(int i = 1 ; i <= x ; i++ ){
			for(int j = 1 ; j <= y ; j++ ){
				scanf("%c",&table[i][j]);
				if( table[i][j] == '*' ){
					for(int k = 0 ; k < 8 ; k++ ){
						ans[i+a[k]][j+b[k]]++;
					}
				}
			}
			getchar();
		}

		if( Case != 1 )
			printf("\n");

		printf("Field #%d:\n",Case++ );
		for(int i = 1 ; i <= x ; i++ ){
			for(int j = 1 ; j <= y ; j++ ){
				if( table[i][j] == '*' )
					printf("*");
				else
					printf("%d",ans[i][j] );
			}
			printf("\n");
		}

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "352"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

char Map[30][30];
int war;

void mark(int i,int j){
	Map[i][j] = 5;
	if( Map[i-1][j-1] == 1 )
		mark(i-1,j-1);
	if( Map[i-1][j] == 1 )
		mark(i-1,j);
	if( Map[i-1][j+1] == 1 )
		mark(i-1,j+1);
	if( Map[i][j-1] == 1 )
		mark(i,j-1);
	if( Map[i][j+1] == 1 )
		mark(i,j+1);
	if( Map[i+1][j-1] == 1 )
		mark(i+1,j-1);
	if( Map[i+1][j] == 1 )
		mark(i+1,j);
	if( Map[i+1][j+1] == 1 )
		mark(i+1,j+1);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int dimension,i,j;
	char enemy;
	int Case = 1;
	while( ~scanf("%d",&dimension) ){

		memset(Map,0,sizeof(Map));
		war = 0;
		getchar();
		for( i = 1 ; i <= dimension ; i++ ){
			for( j = 1 ; j <= dimension ; j++ ){
				scanf("%c",&enemy);
				if( enemy == '1' )
					Map[i][j] = 1;
			}
			getchar();
		}

		for( i = 1 ; i <= dimension ; i++ ){
			for( j = 1 ; j <= dimension ; j++ ){
				if( Map[i][j] == 1 ){
					mark(i,j);
					war++;
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", Case,war );
		Case++;

	}

	return 0;
}
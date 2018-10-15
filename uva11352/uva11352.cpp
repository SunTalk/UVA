#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11352"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int Map[105][105];
int check[105][105];
int lengh,Min;

void attack(int i,int j){
	if( Map[i-2][j-1] == 0 )
		Map[i-2][j-1] = 3;
	if( Map[i-2][j+1] == 0 )
		Map[i-2][j+1] = 3;
	if( Map[i-1][j-2] == 0 )
		Map[i-1][j-2] = 3;
	if( Map[i-1][j+2] == 0 )
		Map[i-1][j+2] = 3;
	if( Map[i+1][j-2] == 0 )
		Map[i+1][j-2] = 3;
	if( Map[i+1][j+2] == 0 )
		Map[i+1][j+2] = 3;
	if( Map[i+2][j-1] == 0 )
		Map[i+2][j-1] = 3;
	if( Map[i+2][j+1] == 0 )
		Map[i+2][j+1] = 3;
}

void Go(int i,int j,int lengh){

	if( Map[i-1][j-1] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i-1][j] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i-1][j+1] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i][j-1] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i][j+1] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i+1][j-1] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i+1][j] == 200 )
		if(lengh<Min)
			Min = lengh;
	if( Map[i+1][j+1] == 200 )
		if(lengh<Min)
			Min = lengh;

	if( Map[i-1][j-1] == 0 && check[i-1][j-1] == 0 )
		check[i-1][j-1] = 3;
	if( Map[i-1][j] == 0 && check[i-1][j] == 0 )
		check[i-1][j] = 3;
	if( Map[i-1][j+1] == 0 && check[i-1][j+1] == 0 )
		check[i-1][j+1] = 3;
	if( Map[i][j-1] == 0 && check[i][j-1] == 0 )
		check[i][j-1] = 3;
	if( Map[i][j+1] == 0 && check[i][j+1] == 0 )
		check[i][j+1] = 3;
	if( Map[i+1][j-1] == 0 && check[i+1][j-1] == 0 )
		check[i+1][j-1] = 3;
	if( Map[i+1][j] == 0 && check[i+1][j] == 0 )
		check[i+1][j] = 3;
	if( Map[i+1][j+1] == 0 && check[i+1][j+1] == 0 )
		check[i+1][j+1] = 3;
	
	//

	if( check[i-1][j-1] == 0 )
		check[i-1][j-1] = 1;
	if( check[i-1][j] == 0 )
		check[i-1][j] = 1;
	if( check[i-1][j+1] == 0 )
		check[i-1][j+1] = 1;
	if( check[i][j-1] == 0 )
		check[i][j-1] = 1;
	if( check[i][j+1] == 0 )
		check[i][j+1] = 1;
	if( check[i+1][j-1] == 0 )
		check[i+1][j-1] = 1;
	if( check[i+1][j] == 0 )
		check[i+1][j] = 1;
	if( check[i+1][j+1] == 0 )
		check[i+1][j+1] = 1;

	//
	if( check[i-1][j-1] == 3 )
		Go(i-1,j-1,lengh+1);
	if( check[i-1][j] == 3 )
		Go(i-1,j,lengh+1);
	if( check[i-1][j+1] == 3 )
		Go(i-1,j+1,lengh+1);
	if( check[i][j-1] == 3 )
		Go(i,j-1,lengh+1);
	if( check[i][j+1] == 3 )
		Go(i,j+1,lengh+1);
	if( check[i+1][j-1] == 3 )
		Go(i+1,j-1,lengh+1);
	if( check[i+1][j] == 3 )
		Go(i+1,j,lengh+1);
	if( check[i+1][j+1] == 3 )
		Go(i+1,j+1,lengh+1);

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,i;
	scanf("%d",&times);
	int line,column,j,k;
	int king_i,king_j;
	int ans;
	char chess;

	for( i = 0 ; i < times ; i++ ){

		scanf("%d %d",&line,&column);
		getchar();

		memset(Map,-1,sizeof(Map));
		memset(check,0,sizeof(check));
		lengh = 0;

		for( j = 2 ; j <= line+1 ; j++ ){
			for( k = 2 ; k <= column+1 ; k++ ){
				scanf("%c",&chess);
				if( chess == '.' )
					Map[j][k] = 0;
				if( chess == 'A' ){
					Map[j][k] = 100;
					king_i = j;
					king_j = k;
				}
				if( chess == 'B' )
					Map[j][k] = 200;
				if( chess == 'Z' )
					Map[j][k] = 1;
			}
			getchar();
		}

		for( j = 2 ; j <= line+1 ; j++ ){
			for( k = 2 ; k <= column+1 ; k++ ){
				if( Map[j][k] == 1 )
					attack(j,k);
			}
		}

		lengh = 0;
		Min = 2147482647;
		Go(king_i,king_j,1);
		ans = Min;

		// for( j = 0 ; j <= line+3 ; j++ ){
		// 	for( k = 0 ; k <= column+3 ; k++ ){
		// 		printf("%4d",Map[j][k] );
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");

		if( ans == 2147482647 )
			printf("King Peter, you can't go now!\n");
		else
			printf("Minimal possible length of a trip is %d\n",ans );

	}


	return 0;
}
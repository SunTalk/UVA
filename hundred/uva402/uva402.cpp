#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "402"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int people,lucky;
	int poke[20];
	int life[55];
	int i,j;
	int CASE = 1;

	while( ~scanf("%d %d",&people,&lucky) ){

		memset(life,0,sizeof(life));
		for( i = 0 ; i < 20 ; i++ )
			scanf("%d ",&poke[i] );

		for( i = 1 ; i <= people ; i++ )
			life[i] = true;

		int left = people;
		int tmp = 0;
		for( i = 0 ; i < 20 ; i++ ){
			tmp = 0;
			if( left <= lucky )
				break;
			for( j = 1 ; j <= people ; j++ ){
				if( life[j] )
					tmp++;
				if( tmp == poke[i] ){
					life[j] = false;
					left--;
					tmp = 0;
				}
				if( left == lucky )
					break;
			}
		}

		printf("Selection #%d\n", CASE++);
		bool check = true;
		for( i = 1 ; i <= people ; i++ ){
			if( life[i] ){
				if(check){
					printf("%d",i);
					check = false;
				}
				else{
					printf(" %d",i);
				}
			}
		}
		printf("\n\n");

	}

	return 0;
}
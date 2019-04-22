#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "160"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isPrime(int k){
	for(int i = 2 ; i < k ; i++ )
		if( k%i == 0 )
			return false;
	return true;
}

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
//30

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[105][30];
	memset(table,-1,sizeof(table));

	for(int i = 2 ; i < 105 ; i++ ){
		int tmp = i;
		for(int j = 0 ; j < 30 ; j++ ){
			if( tmp % prime[j] == 0 ){
				table[i][j] = max( max(1,table[i][j]+1) , table[i-1][j] + 1);
				tmp = tmp/prime[j];
				j--;
			}
			if( table[i-1][j] != -1 ){
				table[i][j] = max(table[i-1][j],table[i][j]);
			}
		}
	}

	int num;
	while( ~scanf("%d",&num) && num ){

		printf("%3d! =",num );
		int count = 0;

		for(int i = 0 ; i < 30 ; i++ ){
			printf("%3d",table[num][i]);
			count++;
			if( table[num][i+1] == -1 )
				break;
			if( count == 15 )
				printf("\n      ");
		}

		printf("\n");

	}

	return 0;
}
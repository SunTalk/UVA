#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1213"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1120
vector <int> PrimeNum;

void isPrime(int k){
	bool check = false;
	for(int i = 2 ; i < k ; i++ ){
		if( k%i == 0 )
			return;
	}
	PrimeNum.push_back(k);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	for(int i = 2 ; i < MAXN+5 ; i++ )
		isPrime(i);

	int table[MAXN+5][15],i,j,k;
	memset(table,0,sizeof(table));
	table[0][0] = 1;
	for( k = 0 ; k < PrimeNum.size() ; k++ ){
		for( i = MAXN+4 ; i >= PrimeNum[k] ; i-- ){
			for( j = 1 ; j < 15 ; j++ ){
				table[i][j] = table[i-PrimeNum[k]][j-1]+table[i][j];
			}
		}
	}

	int num,limit;
	while( ~scanf("%d %d",&num,&limit) && (num | limit) )
		printf("%d\n",table[num][limit] );

	return 0;
}
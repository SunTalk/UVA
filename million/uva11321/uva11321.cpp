#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int N,M;
int table[MAXN+5];

bool isOdd(int k){
	return abs(k)&1;
}

bool cmp(int a, int b){
	if( a%M != b%M ) return a%M < b%M;
	if( isOdd(a) != isOdd(b) ) return isOdd(a) ;
	if( isOdd(a) ) return a > b;
	return a < b;
}

int main(int argc, char const *argv[])
{

	while( ~scanf("%d %d", &N, &M) ){

		for(int i = 0 ; i < N ; i++ )
			scanf("%d", &table[i]);
		sort(table,table+N,cmp);

		printf("%d %d\n", N, M);
		for(int i = 0 ; i < N ; i++ )
			printf("%d\n",table[i]);

	}

	return 0;
}
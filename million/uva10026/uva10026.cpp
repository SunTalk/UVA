#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

struct work{
	int S,T,num;
	bool operator<(work &rhs){
		if( (double)S/(double)T > (double)rhs.S/(double)rhs.T ) return true;
		else if( (double)S/(double)T == (double)rhs.S/(double)rhs.T )
			if( num < rhs.num ) return true;
		return false;
	}
}table[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d",&table[i].T,&table[i].S);
			table[i].num = i+1;
		}
		sort(table,table+num);

		for(int i = 0 ; i < num ; i++ ){
			if( i ) printf(" ");
			printf("%d",table[i].num);
		}
		printf("\n");

		if( kase ) printf("\n");

	}

	return 0;
}
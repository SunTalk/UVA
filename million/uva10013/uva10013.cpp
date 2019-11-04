#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int one[MAXN+5];
int two[MAXN+5];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num,a,b;

	while( kase-- ){

		memset(one,0,sizeof(one));
		memset(two,0,sizeof(two));

		scanf("%d",&num);
		for(int i = 1 ; i <= num ; i++ )
			scanf("%d %d",&one[i],&two[i]);

		for(int i = num ; i >= 1 ; i-- ){
			one[i] += two[i];
			one[i-1] += one[i]/10;
			one[i] %= 10;
		}

		if( one[0] ) printf("%d", one[0]);
		for(int i = 1 ; i <= num ; i++ )
			printf("%d",one[i]);
		printf("\n");
		if( kase ) printf("\n");

	}

	return 0;
}
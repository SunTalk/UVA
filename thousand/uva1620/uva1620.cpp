#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 500

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num,cnt;
	int table[MAXN+5];

	while( kase-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		cnt = 0;
		for(int i = 0 ; i < num ; i++ )
			for(int j = i+1 ; j < num ; j++ )
				if( table[j] < table[i] )
					cnt++;

		if( num%2 && cnt%2 )
			printf("impossible\n");
		else
			printf("possible\n");

	}

	return 0;
}
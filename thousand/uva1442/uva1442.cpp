#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

int CEIL[MAXN+5];
int FLOOR[MAXN+5];
int LEFT[MAXN+5];
int RIGHT[MAXN+5];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num;

	while( kase-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d", &FLOOR[i]);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d", &CEIL[i]);
		memset(LEFT, 0, sizeof(LEFT));
		memset(RIGHT, 0, sizeof(RIGHT));

		int now = MAXN+5;
		for(int i = 0 ; i < num ; i++ ){
			if( CEIL[i] < now )
				now = CEIL[i];
			if( now < FLOOR[i] )
				now = FLOOR[i];
			LEFT[i] = now;
		}

		now = MAXN+5;
		for(int i = num-1 ; i >= 0 ; i-- ){
			if( CEIL[i] < now )
				now = CEIL[i];
			if( now < FLOOR[i] )
				now = FLOOR[i];
			RIGHT[i] = now;
		}

		int ans = 0;
		for(int i = 0 ; i < num ; i++ )
			ans += (min(LEFT[i],RIGHT[i])-FLOOR[i]);
		printf("%d\n",ans);

	}


	return 0;
}
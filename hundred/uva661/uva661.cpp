#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int n,m,c;
	int kase = 1;
	int table[MAXN];
	bool turn[MAXN];

	while( ~scanf("%d %d %d",&n,&m,&c) && (n|m|c) ){

		memset(turn,0,sizeof(turn));
		for(int i = 1 ; i <= n ; i++ )
			scanf("%d",&table[i]);

		int now = 0,used = 0;
		int act;

		for(int i = 1 ; i <= m ; i++ ){
			
			scanf("%d",&act);
			if( turn[act] ) now -= table[act];
			else now += table[act];

			turn[act] ^= 1;
			used = max(used,now);
		}

		printf("Sequence %d\n", kase++ );
		if( used > c ) printf("Fuse was blown.\n");
		else{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n",used);
		}
		printf("\n");

	}

	return 0;
}
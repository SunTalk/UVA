#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
	
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d", &table[i]);

		int maxn = table[0];
		int ans  = table[0]-table[1];
		for(int i = 1 ; i < num ; i++ ){
			ans = max(ans, maxn-table[i]);
			maxn = max(maxn, table[i]);
		}

		printf("%d\n",ans);

	}

	return 0;
}
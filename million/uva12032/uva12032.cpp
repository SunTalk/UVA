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
	for(int K = 1 ; K <= kase ; K++ ){

		memset(table,0,sizeof(table));

		scanf("%d",&num);
		for(int i = 1 ; i <= num ; i++ )
			scanf("%d",&table[i]);

		int ans = table[num]-table[num-1];
		for(int i = num-1 ; i > 0 ; i-- ){
			int tmp = table[i]-table[i-1];
			if( ans == tmp )
				ans++;
			else
				ans = max(ans, tmp);
		}

		printf("Case %d: %d\n", K, ans);

	}

	return 0;
}
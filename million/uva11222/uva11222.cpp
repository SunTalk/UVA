#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool slove[MAXN+10][5];
vector <int> ans[5];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num,tmp;
	for(int K = 1 ; K <= kase ; K++ ){

		memset(slove,0,sizeof(slove));
		for(int i = 1 ; i <= 3 ; i++ ){
			ans[i].clear();
			scanf("%d",&num);
			for(int j = 0 ; j < num ; j++ ){
				scanf("%d",&tmp);
				slove[tmp][i] = true;
			}
		}

		for(int i = 0 ; i < MAXN+5 ; i++ ){
			if( slove[i][1] && !slove[i][2] && !slove[i][3] )
				ans[1].push_back(i);
			if( !slove[i][1] && slove[i][2] && !slove[i][3] )
				ans[2].push_back(i);
			if( !slove[i][1] && !slove[i][2] && slove[i][3] )
				ans[3].push_back(i);
		}

		int S = max(ans[1].size(),max(ans[2].size(),ans[3].size()));

		printf("Case #%d:\n",K);
		for(int i = 1 ; i <= 3 ; i++ ){
			if( ans[i].size() == S ){
				printf("%d %d",i,S);
				for(int j = 0 ; j < S ; j++ )
					printf(" %d",ans[i][j]);
				printf("\n");
			}
		}

	}

	return 0;
}
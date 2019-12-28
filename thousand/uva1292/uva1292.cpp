#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 2000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN][2];
vector <int> con[MAXN];
int is_vis[MAXN];

void dfs(int k){

	is_vis[k] = table[k][1] = 1;
	table[k][0] = 0;

	for(int i = 0 ; i < con[k].size() ; i++ ){
		int j = con[k][i];
		if( is_vis[j] ) continue;
		dfs(j);
		table[k][0] += table[j][1];
		table[k][1] += min(table[j][0],table[j][1]);
	}

}

int main(int argc, char const *argv[])
{

	int num;
	int a,b,c;

	while( ~scanf("%d", &num) ){

		for(int i = 0 ; i < num ; i++ )
			con[i].clear();
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d:(%d)", &a, &b );
			for(int i = 0 ; i < b ; i++ ){
				scanf("%d",&c);
				con[a].push_back(c);
				con[c].push_back(a);
			}
		}

		int ans = 0;
		memset(is_vis,0,sizeof(is_vis));
		for(int i = 0; i < num ; i++ ){
			if( is_vis[i] ) continue;
			dfs(i);
			ans += min(table[i][0],table[i][1]);
		}

		printf("%d\n",ans);

	}

	return 0;
}
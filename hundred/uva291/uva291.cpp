#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

vector <int> path[MAXN];
int ans[MAXN];
bool is_vis[MAXN][MAXN];

void backtracking(int k, int pre){

	if( k == 9 ){
		for(int i = 0 ; i < 9 ; i++ )
			printf("%d",ans[i]);
		printf("\n");
		return;
	}

	for(int i = 0 ; i < path[pre].size() ; i++ ){
		int tmp = path[pre][i];
		if( !is_vis[pre][tmp] ){
			is_vis[pre][tmp] = is_vis[tmp][pre] = true;
			ans[k] = tmp;
			backtracking(k+1,tmp);
			is_vis[pre][tmp] = is_vis[tmp][pre] = false;
		}
	}

}

int main(int argc, char const *argv[])
{

	memset(ans, 0, sizeof(ans));
	memset(is_vis, 0, sizeof(is_vis));

	path[1].push_back(2);
	path[1].push_back(3);
	path[1].push_back(5);

	path[2].push_back(1);
	path[2].push_back(3);
	path[2].push_back(5);

	path[3].push_back(1);
	path[3].push_back(2);
	path[3].push_back(4);
	path[3].push_back(5);

	path[4].push_back(3);
	path[4].push_back(5);

	path[5].push_back(1);
	path[5].push_back(2);
	path[5].push_back(3);
	path[5].push_back(4);

	ans[0] = 1;
	backtracking(1,1);

	return 0;
}
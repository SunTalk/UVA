#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10004"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector <int> EDGE[205];
int COLOR[205];
bool is_visit[205];
bool ans;

void DFS(int k){

	for(int i = 0 ; i < EDGE[k].size() ; i++ ){
		if( COLOR[EDGE[k][i]] == COLOR[k] ){
			ans = false;
			return;
		}
	}	

	for(int i = 0 ; i < EDGE[k].size() ; i++ ){
		if( is_visit[EDGE[k][i]] )
			continue;
		is_visit[EDGE[k][i]] = true;
		if( COLOR[k] == 1 )
			COLOR[EDGE[k][i]] = 2;
		if( COLOR[k] == 2 )
			COLOR[EDGE[k][i]] = 1;
		DFS(EDGE[k][i]);
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int node,edge;
	int a,b;

	while( ~scanf("%d",&node) && node ){

		for(int i = 0 ; i < node ; i++ )
			EDGE[i].clear();
		memset(is_visit,0,sizeof(is_visit));
		memset(COLOR,0,sizeof(COLOR));

		scanf("%d",&edge);
		for(int i = 0 ; i < edge ; i++ ){
			scanf("%d %d",&a,&b);
			EDGE[a].push_back(b);
			EDGE[b].push_back(a);
		}

		ans = true;
		is_visit[0] = true;
		COLOR[0] = 1;
		DFS(0);

		if( ans )
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");

	}

	return 0;
}
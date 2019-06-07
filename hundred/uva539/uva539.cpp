#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "539"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int MAP[30][30];
int tmp_ans,ans;
int node,edge;

void dfs(int k,int len){

	if( len > tmp_ans )
		tmp_ans = len;

	for(int i = 0 ; i < node ; i++ ){
		if( MAP[k][i] ){
			MAP[k][i] = MAP[i][k] = 0;
			dfs(i,len+1);
			MAP[k][i] = MAP[i][k] = 1;
		}
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int a,b;

	while( scanf("%d %d",&node,&edge) && ( node || edge ) ){
		
		memset(MAP,0,sizeof(MAP));
		for(int i = 0 ; i < edge ; i++ ){
			scanf("%d %d",&a,&b);
			MAP[a][b] = MAP[b][a] = 1;
		}

		ans = 0;
		for(int i = 0 ; i < node ; i++ ){
			tmp_ans = 0;
			dfs(i,0);
			if( tmp_ans > ans )
				ans = tmp_ans;
		}

		printf("%d\n",ans );

	}

	return 0;
}
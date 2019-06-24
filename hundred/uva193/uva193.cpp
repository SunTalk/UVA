#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "193"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

vector <int> EDGE[MAXN+5];
int color[MAXN+5];
vector<int> tmp;
vector<int> ANS;
int point,edge;
int ans;

enum COLOR{
	none,
	white,
	black
};

void DFS(int n){

	if( n > point ){
		if( tmp.size() > ans ){
			ans = tmp.size();
			ANS = tmp;
		}
		else if( tmp.size() == ans ){
			bool change = false;
			for(int i = 0 ; i < tmp.size() ; i++ ){
				if( tmp[i] > ANS[i] )
					change = true;
			}
			if( change ){
				ans = tmp.size();
				ANS = tmp;
			}
		}
		return;
	}

	bool is_Black = true;
	for(int i : EDGE[n] )
		if( color[i] == black )
			is_Black = false;


	if( is_Black ){
		tmp.push_back(n);
		color[n] = black;
		DFS(n+1);
		tmp.pop_back();
		color[n] = none;
	}

	color[n] = white;
	DFS(n+1);
	color[n] = none;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int a,b;

	while( CASE-- ){
		scanf("%d %d",&point,&edge);

		for(int i = 1 ; i <= point ; i++ )
			EDGE[i].clear();
		memset(color,0,sizeof(color));
		tmp.clear();
		ans = 0;

		for(int i = 0 ; i < edge ; i++ ){
			scanf("%d %d",&a,&b);
			EDGE[a].push_back(b);
			EDGE[b].push_back(a);
		}

		DFS(1);

		printf("%d\n",ans );
		for(int i = 0 ; i < ANS.size() ; i++ )
			printf("%d%c",ANS[i], ( i == ANS.size()-1 ? '\n':' ' ) );

	}

	return 0;
}
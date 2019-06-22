#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "929"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAXN 1000
#define MAXNUM 0x7f7f7f7f

int maze[MAXN+5][MAXN+5];
int ans[MAXN+5][MAXN+5];
bool is_visit[MAXN+5][MAXN+5];
int x_add[4] = {0,-1,1,0};
int y_add[4] = {-1,0,0,1};

struct Node{
	int x,y,dis;
	Node(){};
	Node(int _x, int _y,int _dis){
		x = _x;
		y = _y;
		dis = _dis;
	};

	bool operator <(const Node &rhs)const {
		return dis > rhs.dis;
	};

};
priority_queue < Node > PQ;
Node tmp;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int x,y;
	while( CASE-- ){

		memset(maze,0,sizeof(maze));
		memset(ans,0,sizeof(ans));
		memset(is_visit,0,sizeof(is_visit));

		scanf("%d %d",&x,&y);
		for(int i = 0 ; i <= x+1 ; i++ ){
			for(int j = 0 ; j <= y+1 ; j++ ){
				if( i == 0 || j == 0 || i == x+1 || j == y+1 ){
					is_visit[i][j] = true;
					maze[i][j] = MAXNUM;
				}
				else{
					scanf("%d",&maze[i][j]);
					ans[i][j] = MAXNUM;
				}
			}
		}

		PQ.emplace(1,1,maze[1][1]);
		int doo = 1;
		
		while( !PQ.empty() ){
			tmp = PQ.top();
			PQ.pop();

			if( tmp.dis < ans[tmp.x][tmp.y] && !is_visit[tmp.x][tmp.y] ){
				is_visit[tmp.x][tmp.y] = true;
				ans[tmp.x][tmp.y] = tmp.dis;
				for(int i = 0 ; i < 4 ; i++ ){
					if( !is_visit[tmp.x+x_add[i]][tmp.y+y_add[i]] )
						PQ.emplace(tmp.x+x_add[i],tmp.y+y_add[i],tmp.dis+maze[tmp.x+x_add[i]][tmp.y+y_add[i]]);
				}
			}

		}

		printf("%d\n",ans[x][y] );
		
	}

	return 0;
}
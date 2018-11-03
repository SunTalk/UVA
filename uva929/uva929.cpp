#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "929"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAX 1005
#define INF 2147483647


int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,i,j;
	scanf("%d",&times);

	int **maze = new int*[MAX];
	int **ans = new int*[MAX];
	for( i = 0 ; i < MAX ; i++ ){
		maze[i] = new int[MAX];
		ans[i] = new int[MAX];
	}

	int x,y;
	pair<int,int> tmp;
	while( times-- ){
		scanf("%d %d",&x,&y);
		for( i = 0 ; i < x ; i++ )
			for( j = 0 ; j < y ; j++ )
				scanf("%d",&maze[i][j]),ans[i][j]=INF;

		priority_queue < pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > PQ;

		tmp.first = tmp.second = 0;
		PQ.push(tmp);

		while( !PQ.empty() ){
			tmp = PQ.top();
			PQ.pop();
			

			
		}

	}

	for( i = 0; i < MAX ; i++){
		delete [] maze[i];
		delete [] ans[i];
	}
	delete [] maze;
	delete [] ans;

	return 0;
}
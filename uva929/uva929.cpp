#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "929"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,tmp,x,y;
	int maze[1005],i,j;

	scanf("%d",&times);

	for(int k = 0 ; k < times ; k++ ){
		memset(maze,0,sizeof(maze));

		scanf("%d %d",&x,&y);
		for( i = 0 ; i < x ; i++ ){
			for( j = 0 ; j < y ; j++ ){
				scanf("%d",&tmp);
				if( i == 0 )
					maze[j] = tmp;
				else if( j == 0 )
					maze[j] = maze[j] + tmp;
				else
					maze[j] = tmp + min(maze[j],maze[j-1]);
			}
		}



	}



	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "116"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int weight[15][105];
	int DP[15][105];
	int path[15][105];
	int row,column,i,j;
	int up,mid,down;

	while( ~scanf("%d %d",&row,&column) ){

		memset(weight,0,sizeof(weight));
		memset(DP,0,sizeof(DP));
		memset(path,0,sizeof(path));

		for( i = 0 ; i < row ; i++ ){
			for( j = 0 ; j < column ; j++ ){
				scanf("%d",&weight[i][j]);
				DP[i][j] = weight[i][j];
			}
		}

		for( j = column-2 ; j >= 0 ; j-- ){
			for( i = 0 ; i < row ; i++ ){
				up = weight[i][j] + DP[(i-1+row)%row][j+1];
				mid = weight[i][j] + DP[i][j+1];
				down = weight[i][j] + DP[(i+1)%row][j+1];

				path[i][j] = INT_MAX;

				if( up <= mid && up <= down ){
					DP[i][j] = up;
					path[i][j] = min( path[i][j], (i-1+row)%row );
				}
				if( mid <= up && mid <= down ){
					DP[i][j] = mid;
					path[i][j] = min( path[i][j], i );
				}
				if( down <= up && down <= mid ){
					DP[i][j] = down;
					path[i][j] = min( path[i][j], (i+1)%row );
				}
			}
		}

		int min_path = INT_MAX;
		int start;
		for( i = 0 ; i < row ; i++ ){
			if( DP[i][0] < min_path ){
				min_path = DP[i][0];
				start = i;
			}
		}

		int next = start;
		printf("%d",start+1 );
		for( i = 0 ; i < column-1 ; i++ ){
			printf(" %d",path[next][i]+1 );
			next = path[next][i];
		}
		printf("\n%d\n", min_path );

	}

	return 0;
}
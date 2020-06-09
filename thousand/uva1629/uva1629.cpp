#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool hasA[MAXN][MAXN];
int table[MAXN][MAXN][MAXN][MAXN];

int sum(int upon, int down, int left, int right){

	int ret = 0;
	for(int i = upon+1 ; i <= down ; i++ ){
		for(int j = left+1 ; j <= right ; j++ ){
			if( hasA[i][j] )
				ret++;
		}
	}
	return ret>1?2:ret;

}

int dp(int upon, int down, int left, int right){

	int &ret = table[upon][down][left][right];
	if( ret != -1 ) return ret;

	int total = sum(upon,down,left,right);
	if( total == 1 ) return ret = 0;
	if( total == 0 ) return ret = INF;
	ret = INF;

	for(int i = upon+1 ; i < down ; i++ )
		ret = min(ret, dp(i,down,left,right)+dp(upon,i,left,right)+right-left );
	for(int i = left+1 ; i < right ; i++ )
		ret = min(ret, dp(upon,down,i,right)+dp(upon,down,left,i)+down-upon);

	return ret;

}

int main(int argc, char const *argv[])
{

	int n,m,k;
	int kase = 1;
	while( ~scanf("%d %d %d",&n,&m,&k) ){

		memset(hasA,0,sizeof(hasA));
		memset(table,-1,sizeof(table));

		int x,y;
		for(int i = 0 ; i < k ; i++ ){
			scanf("%d %d",&x,&y);
			hasA[x][y] = true;
		}

		printf("Case %d: %d\n",kase++,dp(0,n,0,m));

	}

	return 0;
}
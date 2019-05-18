#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10003"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int table[55][55];
int point[55];
int dp(int l, int r){

	if( table[l][r] > -1 )
		return table[l][r];
	if( l+1 == r )
		return table[l][r] = 0;
	int ans = INT_MAX;

	for(int i = l+1 ; i < r ; i++ )
		ans = min(ans,dp(l,i)+dp(i,r));

	table[l][r] = ans + point[r] - point[l];
	return table[l][r];

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int len,num;

	while( ~scanf("%d %d",&len,&num) && len ){

		memset(table,-1,sizeof(table));
		memset(point,0,sizeof(point));

		for(int i = 1 ; i <= num ; i++ )
			scanf("%d",&point[i]);
		point[num+1] = len;

		printf("The minimum cutting is %d.\n", dp(0,num+1));

	}

	return 0;
}
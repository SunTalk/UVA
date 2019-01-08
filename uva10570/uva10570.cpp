#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10570"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int start[1005];
int tmp[505],mark[505];
int num,i,j;

int solve(){

	int ans = INT_MAX;

	for( i = 0 , j = num ; i < num ; i++ , j++ )
		start[j] = start[i];
	for( i = 0 ; i < num ; i++ ){
		int cnt = 0;
		for( j = 0 ; j < num ; j++ ){
			tmp[j] = start[i+j];
			mark[tmp[j]] = j;
		}
		for( j = 0 ; j < num ; j++ ){
			if( tmp[j] != j ){
				cnt++;
				int use = mark[j];
				swap( tmp[j] , tmp[use] );
				mark[tmp[use]] = use;
			}
		}
		ans = min(ans,cnt);
	}

	return ans;
	
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	while( ~scanf("%d",&num) && num ){
		
		for( i = 0 ; i < num ; i++ ){
			scanf("%d",&start[i]);
			start[i]--;
		}

		int ANS = solve();
		reverse(start,start+num);
		ANS = min(ANS,solve());
		printf("%d\n",ANS );

	}

	return 0;
}
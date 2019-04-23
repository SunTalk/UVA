#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "193"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector <int> table[105];
int tmp[105],ans[105];
int point,edge;
int ANS;

void solve( int n ){

	if( n > ANS ){
		ANS = n;
		for(int i = 0; i < 105 ; i++ )
			ans[i] = tmp[i];
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	while( CASE-- ){

		memset(tmp,0,sizeof(tmp));
		memset(ans,0,sizeof(ans));
		for(int i = 0 ; i < 105 ; i++ )
			table[i].clear();

		scanf("%d %d",&point,&edge);

		int a,b;
		for(int i = 0 ; i < edge ; i++ ){
			scanf("%d %d",&a,&b);
			table[a].push_back(b);
			table[b].push_back(a);
		}

		


	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10050"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 4000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int num,nwork;
	int table[105];
	bool day[MAXN];

	while( kase-- ){

		scanf("%d %d", &num, &nwork );
		for(int i = 0 ; i < nwork ; i++ )
			scanf("%d",&table[i]);

		int ans = 0;
		memset(day,0,sizeof(day));
		for(int i = 0 ; i < nwork ; i++ ){
			for(int j = table[i] ; j <= num ; j += table[i] ){
				if( !day[j] && j%7 != 0 && j%7 != 6 ){
					ans++;
					day[j] = true;
				}
			}
		}

		printf("%d\n",ans );

	}

	return 0;
}
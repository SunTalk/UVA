#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12403"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	string str;
	int num,ans = 0;

	while( kase-- ){
		
		cin >> str;
		if( str == "donate" ){
			scanf("%d",&num);
			ans += num;
		}
		else
			printf("%d\n",ans );

	}

	return 0;
}
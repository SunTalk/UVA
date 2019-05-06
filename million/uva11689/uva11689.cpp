#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11689"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int one,two,change;
	int tmp,ans;
	while( CASE-- ){

		scanf("%d %d %d",&one,&two,&change);
		tmp = one + two;
		ans = 0;

		while( tmp >= change ){
			ans = ans + tmp/change;
			tmp = tmp/change + tmp%change;
		}
		printf("%d\n",ans );

	}

	return 0;
}
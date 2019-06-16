#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11547"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int ans;

	while( CASE-- ){
		scanf("%d",&ans);
		ans *= 567;
		ans /= 9;
		ans += 7492;
		ans *= 235;
		ans /= 47;
		ans -= 498;
		ans /= 10;
		printf("%d\n", abs(ans%10) );
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10346"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int n,k,ans;
	while( ~scanf("%d %d",&n ,&k) ){

		ans = n;
		while( n/k ){
			ans += n/k;
			n = n/k + n%k;
		}
		printf("%d\n",ans );

	}

	return 0;
}
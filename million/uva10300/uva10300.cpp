#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10300"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int num;
	long long ans;
	long long a,b,c;

	while( CASE-- ){
		scanf("%d",&num);
		ans = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%lld %lld %lld",&a,&b,&c);
			ans = ans + (a*c);
		}
		printf("%lld\n",ans );
	}

	return 0;
}
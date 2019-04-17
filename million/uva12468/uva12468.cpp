#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12468"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int a,b,ans;
	while( ~scanf("%d %d",&a,&b) ){
		if( a == -1 && b == -1 )
			break;
		ans = abs(a-b);
		if(ans>50)
			ans = 100 - ans;
		printf("%d\n",ans );
	}

	return 0;
}
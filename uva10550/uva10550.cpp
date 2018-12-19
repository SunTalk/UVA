#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10550"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int start,one,two,three;

	while( ~scanf("%d %d %d %d",&start,&one,&two,&three) ){

		if( start == 0 && one == 0 && two == 0 && three == 0 )
			break;
		int ans = 120;

		while( start != one ){
			start--;
			if( start == -1 )
				start = 39;
			ans++;
		}
		while( start != two ){
			start++;
			if( start == 40 )
				start = 0;
			ans++;
		}
		while( start != three ){
			start--;
			if( start == -1 )
				start = 39;
			ans++;
		}

		printf("%d\n",ans*9 );
	}

	return 0;
}
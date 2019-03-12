#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12208"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long one,two;
	long long ans,tmp,i;
	int Case=1;
	while( ~scanf("%lld %lld",&one,&two) ){

		if( one==0 && two==0 )
			break;
		
		two++;
		ans = 0;
		for( i = 1 ; i <= ( 1<<30 ) ; i=i<<1 ){
			
			tmp = i<<1;

			ans = ans + (two/tmp)*i;
			if( two%tmp > i )
				ans = ans + ( two%tmp - i );

			ans = ans - (one/tmp)*i;
			if( one%tmp > i )
				ans = ans - ( one%tmp - i );

			if( two < tmp )
				break; 

		}

		printf("Case %d: %lld\n",Case,ans );
		Case++;
	}

	return 0;
}
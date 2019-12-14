#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	for(int K = 1 ; K <= kase ; K++ ){

		scanf("%d",&num);
		double ans = 0;

		if ( num > 1180000 ) {
			ans += (num-1180000)/4.0;
			num = 1180000;
		}
		if ( num > 880000 ) {
			ans += (num-880000)/5.0;
			num = 880000;
		}	
		if ( num > 480000 ) {
			ans += (num-480000)*3/20.0;
			num = 480000;
		}

		if ( num > 180000 )
			ans += (num-180000)/10.0;
		if ( ans > 0 && ans < 2000 )
			ans = 2000;

		printf("Case %d: %d\n", K, (int)(ans+0.99));

	}

	return 0;
}
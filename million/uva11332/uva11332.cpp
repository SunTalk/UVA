#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11332"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int ans(int k){

	while( k > 9 ){
		int _tmp_ = k;
		k = 0;
		while( _tmp_ > 0 ){
			k += _tmp_%10;
			_tmp_ /= 10;
		}
	}

	return k;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;

	while( ~scanf("%d",&num) && num )
		printf("%d\n",ans(num) );

	return 0;
}
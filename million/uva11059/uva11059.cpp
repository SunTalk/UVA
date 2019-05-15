#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11059"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	long long table[20];
	long long tmp,ans;
	int CASE = 1;

	while( ~scanf("%d",&num) ){
		
		for(int i = 0 ; i < num ; i++ )
			scanf("%lld",&table[i]);

		ans = 0;
		for(int i = 1 ; i <= num ; i++ ){
			for(int j = 0 ; j < num ; j++ ){
				if( j+i > num )
					break;
				tmp = 1;
				for(int k = 0 ; k < i ; k++ ){
					tmp = tmp*table[j+k];
				}
				if( tmp > ans )
					ans = tmp;
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n", CASE++,ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10465"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	pair<int,int> bag[10005];
	int one,two,times;
	int ans,tmp,i;

	while( ~scanf("%d %d %d",&one,&two,&times) ){

		for( i = 0 ; i < times+5 ; i++ )
			bag[i].first = bag[i].second = 0;

		tmp = min(one,two);

		for( i = 1 ; i <= times ; i++ ){
			if( i >= tmp ){
				if( ( bag[i-tmp].first + tmp ) > bag[i].first ){
					bag[i].first = bag[i-tmp].first + tmp;
					bag[i].second = bag[i-tmp].second + 1;
					// printf("%d ",i );
				}
			}
		}

		if( tmp == one )
			tmp = two;
		else
			tmp = one;

		for( i = 1 ; i <= times ; i++ ){
			if( i >= tmp ){
				if( ( bag[i-tmp].first + tmp ) > bag[i].first ){
					bag[i].first = bag[i-tmp].first + tmp;
					bag[i].second = bag[i-tmp].second + 1;
				}
			}
		}

		if( times > bag[times].first )
			printf("%d %d\n", bag[times].second, times-bag[times].first );
		else
			printf("%d\n",bag[times].second );

	}

	return 0;
}
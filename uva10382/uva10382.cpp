#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10382"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	double num,len,wei;
	vector <pair <double,double>> range;
	double one,two;
	double count;

	while( ~scanf("%lf %lf %lf",&num,&len,&wei) ){

		wei = wei/2;
		wei = wei*wei;

		for(int i = 0 ; i < num ; i++){
			scanf("%lf %lf",&one,&two);
			count = two*two;
			count = count - wei;
			if( count  > 0 ){
				count = sqrt(count);
				range.emplace_back(one - count, one + count);
			}
		}

		sort(range.begin(),range.end());

		double check_l = 0;
		double check_r = 0;
		int ans = 0;
		int times = 0;
		for(int i = 0 ; i < range.size() ; ){
			while( range[i].first <= check_l && i < range.size() ){
				if( range[i].second > check_r )
					check_r = range[i].second;
				i++;
			}
			ans++;
			times++;

			if( check_r >= len )
				break;

			if( check_r < check_l || times > range.size() ){
				ans = -1;
				break;
			}
			check_l = check_r;
		}

		if( check_r < len )
			ans = -1;

		printf("%d\n",ans );

		range.clear();
	}

	return 0;
}
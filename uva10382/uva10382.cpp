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

	double num,len;
	double wei;
	vector <pair <double,double>> range;
	pair <double,double> tmp;
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
				tmp.first = one - count; 
				tmp.second = one + count;
				range.push_back(tmp);
			}
		}

		sort(range.begin(),range.end());
		
		// for(int i= 0 ; i < range.size() ; i++ )
		// 	printf("%lf %lf\n",range[i].first,range[i].second );
		// printf("\n");

		double check_l = 0;
		double check_r = 0;
		int ans = 0;
		int times = 0;
		for(int i = 0 ; i < range.size() ; ){
			while( range[i].first <= check_l ){
				if( range[i].second > check_r )
					check_r = range[i].second;
				i++;
			}
			ans++;

			if( check_r > len )
				break;

			if( check_r < check_l ){
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
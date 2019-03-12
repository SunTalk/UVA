#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1617"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	int num,one,two;
	vector < pair<int,int> > schedule;
	int i,j;

	while( times-- ){

		scanf("%d",&num);
		for( i = 0 ; i < num ; i++ ){
			scanf("%d %d",&one,&two);
			schedule.emplace_back(two,one);
			//first is right,second is left
		}

		sort(schedule.begin(),schedule.end());

		int ans = 0,tmp = schedule[0].first;
		for( i = 1 ; i < num ; i++ ){
			if( tmp != schedule[i].first ){
				if( tmp < schedule[i].second ){
					ans++;
					tmp = schedule[i].first;
				}
				else
					tmp++;
			}
		}

		printf("%d\n",ans );
		schedule.clear();

	}

	return 0;
}
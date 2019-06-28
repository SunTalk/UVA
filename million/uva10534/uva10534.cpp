#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10534"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

int NUM[MAXN+5],LIS[MAXN+5],LDS[MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,len;
	vector <int> table;

	while( ~scanf("%d",&num) ){

		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&NUM[i]);

		table.clear();
		table.push_back(NUM[0]);
		LIS[0] = len = 1;

		for(int i = 1 ; i < num ; i++ ){
			if( NUM[i] > table.back() ){
				table.push_back(NUM[i]);
				LIS[i] = ++len;
			}
			else{
				*lower_bound(table.begin(), table.end(),NUM[i]) = NUM[i];
				LIS[i] = lower_bound(table.begin(), table.end(),NUM[i])-table.begin() + 1;
			}
		}

		table.clear();
		table.push_back(NUM[num-1]);
		LDS[num-1] = len = 1;

		for(int i = num-2 ; i >= 0 ; i-- ){
			if( NUM[i] > table.back() ){
				table.push_back(NUM[i]);
				LDS[i] = ++len;
			}
			else{
				*lower_bound(table.begin(), table.end(),NUM[i]) = NUM[i];
				LDS[i] = lower_bound(table.begin(), table.end(),NUM[i])-table.begin() + 1;
			}
		}

		int MAX = 0;
		for(int i = 0 ; i < num ; i++ ){
			int tmp = min(LIS[i],LDS[i]);
			if( MAX < tmp )
				MAX = tmp;
		}

		printf("%d\n",MAX*2-1 );

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11997"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,i,j,k;
	int one[800],two[800];
	pair <int,int> tmp;

	while( ~scanf("%d",&number) ){
		
		for( i = 0 ; i < number ; i++ )
			scanf("%d",&one[i]);
		sort(one,one+number);

		for( k = 1 ; k < number ; k++ ){
			priority_queue <pair <int,int>,vector<pair <int,int>>,greater<pair <int,int>>> PQ;
			
			for( i = 0 ; i < number ; i++ )
				scanf("%d",&two[i]);
			sort(two,two+number);

			for( i = 0 ; i < number ; i++ )
				PQ.push( make_pair(one[i]+two[0],0) );
			
			for( i = 0 ; i < number ; i++ ){
				tmp = PQ.top();
				PQ.pop();
				one[i] = tmp.first;
				if( tmp.second+1 < number )
					PQ.push( make_pair( tmp.first - two[tmp.second] + two[tmp.second+1] , tmp.second+1 ) );
			}

		}
		
		for( i = 0 ; i < number-1 ; i++ )
			printf("%d ",one[i] );
		printf("%d\n",one[number-1]);
	}

	return 0;
}
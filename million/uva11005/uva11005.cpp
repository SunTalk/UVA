#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int money[40];
	int cost[40];
	int kase;
	scanf("%d",&kase);
	int N,num;

	for(int K = 1 ; K <= kase ; K++ ){
		
		if( K > 1 ) printf("\n");
		printf("Case %d:\n",K);

		memset(cost,0,sizeof(cost));
		for(int i = 0 ; i < 36 ; i++ )
			scanf("%d",&money[i]);
		
		scanf("%d",&N);
		while( N-- ){
			scanf("%d",&num);

			int MinCost = INT_MAX;
			for(int i = 2 ; i <= 36 ; i++ ){
				int tmp = num;
				int now = 0;
				while( tmp > 0 ){
					now += money[tmp%i];
					tmp /= i;
				}
				cost[i] = now;
				MinCost = min(MinCost,now);
			}

			printf("Cheapest base(s) for number %d:",num);
			for(int i = 2 ; i <= 36 ; i++ )
				if( cost[i] == MinCost )
					printf(" %d",i);
			printf("\n");

		}

	}



	return 0;
}
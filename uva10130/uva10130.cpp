#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10130"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	
	int goods,people;
	int total,power,i,j;

	while( times-- ){
		scanf("%d",&goods);
		int data[goods][2];//0-weight,1-value
		for( i = 0 ; i < goods ; i++ ){
			scanf("%d %d",&data[i][1],&data[i][0]);
		}

		scanf("%d",&people);
		int family[people];
		power = 0;
		for( i = 0 ; i < people ; i++ ){
			scanf("%d",&family[i]);
			power = max(power,family[i]);
		}

		int ans[power+1][2];
		memset(ans,0,sizeof(ans));
		for( i = 0 ; i < goods ; i++ ){
			for( j = 1 ; j <= power ; j++ )
				if( j >= data[i][0] )
					ans[j][1] = max( data[i][1] + ans[j-data[i][0]][0] , ans[j][0] );
			for( j = 1 ; j <= power ; j++ )
				ans[j][0] = ans[j][1];
		}

		total = 0;
		for( i = 0 ; i < people ; i++ )
			total = total + ans[family[i]][1];

		printf("%d\n",total );

	}

	return 0;
}
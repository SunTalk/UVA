#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "166"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int coin[6] = {5,10,20,50,100,200};
	int inf[605],limit[605];
	int have[6];

	memset(inf,0,sizeof(inf));

	for(int i = 0 ; i < 6 ; i++ ){
		for(int j = 0; j < 600 ; j++ ){
			if( j >= coin[i] ){
				if( j%coin[i] == 0 )
					inf[j] = inf[j-coin[i]]+1;
				else
					inf[j] = min(inf[j-coin[i]]+1,inf[j]);
			}
		}
	}

	int total;
	while( ~scanf("%d",&have[0]) ){
		total = have[0] * coin[0];
		for(int i = 1 ; i < 6 ; i++ ){
			scanf("%d",&have[i]);
			total += have[i]*coin[i];
		}

		if( !total )
			break;

		int a,b;
		scanf("%d.%d",&a,&b);
		int price = a*100+b;

		memset(limit,0,sizeof(limit));

		for(int i = 1 ; i < 605 ; i++ )
			limit[i] = 0x3f3f3f3f;

		for(int i = 0 ; i < 6 ; i++ ){
			for(int j = 0 ; j < have[i] ; j++ ){
				for(int k = 600 ; k >= coin[i] ; k-- ){
					limit[k] = min(limit[k-coin[i]]+1,limit[k]);
				}
			}
		}

		int ans = limit[price];
		for(int i = price ; i < 600 ; i = i+5 ){
			ans = min(ans, inf[i-price]+limit[i] );
		}
		printf("%3d\n",ans );

	}

	return 0;
}
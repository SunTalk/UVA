#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11559"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int member,money,hotel,week;
	int pay,vacant,ans;

	while( ~scanf("%d %d %d %d",&member,&money,&hotel,&week) ){

		ans = money+1;
		for(int i = 0 ; i < hotel ; i++ ){
			scanf("%d",&pay);
			for(int j = 0 ; j < week ; j++ ){
				scanf("%d",&vacant);
				if( vacant >= member && pay*member < ans )
					ans = pay*member;
			}
		}

		if( ans > money )
			printf("stay home\n");
		else
			printf("%d\n",ans);

	}

	return 0;
}
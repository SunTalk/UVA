#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int H[MAXN+5];
int W[MAXN+5];
int LIS[MAXN+5];
int LDS[MAXN+5];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num,tmp;
	int A,B;

	for(int K = 1 ; K <= kase ; K++ ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&H[i]);
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&W[i]);

		A = B = 0;
		for(int i = 0 ; i < num ; i++ ){
			LIS[i] = LDS[i] = W[i];
			for(int j = 0 ; j < i ; j++ ){
				if( H[j] < H[i] )
					LIS[i] = max(LIS[i],LIS[j]+W[i]);
				if( H[j] > H[i] )
					LDS[i] = max(LDS[i],LDS[j]+W[i]);
			}
			A = max(A,LIS[i]);
			B = max(B,LDS[i]);
		}

		if( B > A ) printf("Case %d. Decreasing (%d). Increasing (%d).\n",K,B,A);
		else printf("Case %d. Increasing (%d). Decreasing (%d).\n",K,A,B);

	}

	return 0;
}
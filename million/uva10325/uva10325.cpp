#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL lcm(LL a, LL b){
	return a*b/__gcd(a,b);
}

int main(int argc, char const *argv[])
{

	int N,M;
	int num[MAXN];

	while( ~scanf("%d %d",&N,&M) ){

		for(int i = 0 ; i < M ; i++ )
			scanf("%d",&num[i]);

		LL k = 1<<M,ans = N;
		for(int i = 1 ; i < k ; i++ ){
			LL L = 1,bits = 0;
			for(int j = 0 ; j < M ; j++ ){
				if( i&(1<<j) ){
					L = lcm(L,num[j]);
					bits++;
				}
			}
			if( bits&1 ) ans -= N/L;
			else ans += N/L;
		}

		printf("%lld\n",ans);

	}

	return 0;
}
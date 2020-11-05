#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL SG(LL k){
	return k&1?SG(k>>1):(k>>1);
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	while(kase--){

		int piles;
		scanf("%d",&piles);

		LL num, ans = 0;
		for(int i = 0 ; i < piles ; i++ ){
			scanf("%lld", &num);
			ans ^= SG(num);
		}

		printf("%s\n", ans?"YES":"NO");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

long long table[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d", &kase);

	int num;
	for(int K = 1 ; K <= kase ; K++ ){
		bool sym = true;

		char gar,gar2;
		getchar();
		scanf("%c %c %d\n", &gar, &gar2, &num);
		for(int i = 0 ; i < num*num ; i++ )
			scanf("%lld", &table[i]);

		for(int i = 0 ; i < num*num ; i++ ){
			int j = num*num-1-i;
			if( table[i] != table[j] || table[i] < 0 )
				sym = false;
		}
		printf("Test #%d: %s\n",K,sym?"Symmetric.":"Non-symmetric.");

	}

	return 0;
}
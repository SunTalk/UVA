#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	LL num;
	while( ~scanf("%lld", &num) ){
		if( num < 3 ) printf("0\n");
		else printf("%lld\n", (num-1)*(num-2)/2);
	}

	return 0;
}
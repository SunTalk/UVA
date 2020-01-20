#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

long long ans(long long a, long long b){
	long long A = a*(a-1)/2;
	long long B = b*(b-1)/2;
	return A*B;
}

int main(int argc, char const *argv[])
{

	long long a,b;
	int kase = 1;
	while( ~scanf("%lld %lld",&a,&b) && a && b )
		printf("Case %d: %lld\n",kase++,ans(a,b));

	return 0;
}
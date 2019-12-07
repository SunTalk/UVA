#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{
	
	long long start,num;
	while( ~scanf("%lld %lld",&start,&num) ){
		long long total = 0;
		while( total < num )
			total += (start++);
		printf("%lld\n",start-1);
	}

	return 0;
}
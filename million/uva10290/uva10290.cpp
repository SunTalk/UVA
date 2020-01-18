#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

bool sieve[MAXN+10];
vector <long long> prime;

void build(){
	memset(sieve,0,sizeof(sieve));
	sieve[0] = sieve[1] = true;
	for(int i = 2 ; i <= sqrt(MAXN) ; i++ )
		if( !sieve[i] )
			for(int j = i*i ; j < MAXN+5 ; j+=i )
				sieve[j] = true;
	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( !sieve[i] )
			prime.push_back(i);
		
}

int main(int argc, char const *argv[])
{

	build();

	long long num;
	while( ~scanf("%lld",&num) ){

		if( num == 0 ){
			printf("1\n");
			continue;
		}

		while( !(num&1) )
			num >>= 1;

		int sum = 1,idx = 1;
		while( num != 1 && num >= prime[idx]*prime[idx] && idx < prime.size() ){
			int tmp = 1;
			while( !(num%prime[idx]) ){
				tmp++;
				num /= prime[idx];
			}
			sum *= tmp;
			idx++;
		}

		if( num > 1 )
			sum <<= 1;

		printf("%d\n",sum);

	}

	return 0;
}
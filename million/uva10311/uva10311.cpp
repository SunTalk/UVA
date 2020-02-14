#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool visit[MAXN+10];
vector <int> prime;

void build(){

	memset(visit, 0, sizeof(visit));
	for(int i = 2; i < MAXN+5 ; i++ ){
		if( !visit[i] ){
			prime.push_back(i);
			for(int j = i+i ; j < MAXN+5 ; j+=i ){
				visit[j] = true;
			}
		}
	}

}

int main(int argc, char const *argv[])
{

	build();

	int num;
	while( ~scanf("%d", &num) ){
		
		if( num < 5 ) printf("%d is not the sum of two primes!\n",num);
		else if ( num&1 ){
			if( !visit[num-2] ) printf("%d is the sum of %d and %d.\n",num,2,num-2);
			else printf("%d is not the sum of two primes!\n",num);
		}
		else{
			bool check = false;

			int LB = lower_bound(prime.begin(),prime.end(),num/2)-prime.begin();
			for(int i = LB ; i >= 0 ; i-- ){
				if( num-prime[i] > prime[i] && !visit[num-prime[i]] ){
					check = true;
					printf("%d is the sum of %d and %d.\n",num,prime[i],num-prime[i]);
					break;
				}
			}

			if( !check )
				printf("%d is not the sum of two primes!\n",num);

		}

	}

	return 0;
}
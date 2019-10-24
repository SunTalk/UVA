#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 35000

bool sieve[MAXN+5];
vector<int> prime;
void build(){
	for(int i = 0 ; i < MAXN ; i++ )
		sieve[i] = true;
	for(int i = 2 ; i < MAXN ; i++ ){
		if( sieve[i] ){
			prime.push_back(i);
			for(int j = i*i ; j < MAXN ; j+=i )
				sieve[j] = false;
		}
	}
}

int factor(int num){

	int sum = 1;
	for(int i = 0 ; i < prime.size() ; i++ ){
		if( num%prime[i] == 0 ){
			int cnt = 1;
			while( num%prime[i] == 0 ){
				cnt++;
				num /= prime[i];
			}
			sum *= cnt;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int L,U,P,D;
	build();

	while( kase-- ){

		scanf("%d %d",&L,&U);

		D = 0;
		for(int i = L ; i <= U ; i++ ){
			int tmp = factor(i);
			if( tmp > D ){
				D = tmp;
				P = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,P,D);
	
	}

	return 0;
}
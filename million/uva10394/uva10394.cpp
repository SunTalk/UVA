#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool sieve[MAXN+10];
vector <int> Prime;
vector <pair<int,int>> TwinPrime;

void build(){

	memset(sieve, 0, sizeof(sieve));
	for(int i = 2 ; i < MAXN+5 ; i++ ){
		if( !sieve[i] ){
			for(int j = i+i ; j < MAXN+5 ; j+=i )
				sieve[j] = true;
			Prime.push_back(i);
		}
	}

	pair <int,int> P;
	for(int i = 1 ; i < Prime.size() ; i++ ){
		if( Prime[i-1]+2 == Prime[i] ){
			P.first = Prime[i-1];
			P.second = Prime[i];
			TwinPrime.push_back(P);
		}
	}

}


int main(int argc, char const *argv[])
{

	build();
	int num;
	while( ~scanf("%d", &num) )
		printf("(%d, %d)\n", TwinPrime[num-1].first, TwinPrime[num-1].second);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool table[MAXN+10];
vector <int> prime;

void build(){
	memset(table, 0, sizeof(table));
	for(int i = 2 ; i < MAXN+5 ; i++ ){
		if( !table[i] ){
			for(int j = i+i ; j < MAXN+5 ; j+=i )
				table[j] = true;
			prime.push_back(i);
		}
	}
}

int main(int argc, char const *argv[])
{

	build();

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){

		scanf("%d",&num);
		int ans = INF;
		for(int i = 0 ; i < prime.size() ; i++ ){
			int P = num/prime[i];
			if( P ) ans = min(ans,prime[i]*P);
		}

		printf("%d\n",ans);

	}

	return 0;
}
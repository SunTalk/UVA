#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int ans[MAXN+10];

void build(){
	for(int i = 1; i < (MAXN+5)/2 ; i++ )
		for(int j = i+i ; j < (MAXN+5) ; j += i )
			if( i == (j^(j-i)) )
				ans[j]++;
	for(int i = 1 ; i < (MAXN+5) ; i++ )
		ans[i] += ans[i-1];
}

int main(int argc, char const *argv[])
{

	build();
	int kase;
	scanf("%d",&kase);

	int num;
	for(int K = 1 ; K <= kase ; K++ ){
		scanf("%d",&num);
		printf("Case %d: %d\n",K,ans[num]);
	}

	return 0;
}
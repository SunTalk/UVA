#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL f(LL u, int i){
	if( (u>>i)&1 )
		return ((u>>(i+1))<<i) + (u&((1LL<<i)-1)) + 1;
	else
		return ((u>>(i+1))<<i);
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	LL a,b,sa,sb;
	LL ansAND,ansOR;

	for(int K = 1 ; K <= kase ; K++ ){
		
		cin >> a >> b ;
		ansAND = ansOR = 0;
		for(int i = 0 ; i < 63 ; i++ ){
			sa = f(a-1,i);
			sb = f(b,i);
			if( sb > sa )
				ansOR |= 1LL<<i;
			if( sb-sa == b-a+1 )
				ansAND |= 1LL<<i;
		}

		printf("Case %d: %lld %lld\n",K,ansOR,ansAND);
	
	}
	
	return 0;
}
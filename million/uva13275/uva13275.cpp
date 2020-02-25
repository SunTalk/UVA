#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int C(int k){
	return k/4-k/100+k/400;
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int mon,day,Syear,Eyear;
	for(int k = 1 ; k <= kase ; k++ ){

		scanf("%d %d %d %d",&day,&mon,&Syear,&Eyear);
		if( day != 29 || mon != 2 )
			printf("Case %d: %d\n", k, Eyear-Syear);
		else
			printf("Case %d: %d\n", k, C(Eyear)-C(Syear));

	}

	return 0;
}
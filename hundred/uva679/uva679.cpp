#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{
	
	int kase;
	scanf("%d",&kase);
	int D,I;

	while( kase-- ){

		scanf("%d %d",&D,&I);
		int ans = 1<<(D-1);
		I -= 1;
		int k = D-2;
		while( I ){
			ans |= (I&1)<<(k--);
			I >>= 1;
		}
		printf("%d\n",ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int num;
	int x,y;
	while( ~scanf("%d",&num) && num ){

		int k = 1;
		int cnt;
		for(cnt = 0 ; k < num ; cnt++ )
			k += 2*cnt;

		x = y = cnt;

		if( num == k ){
			if( cnt == 0 )
				x = y = 1;
		}
		else if( cnt&1 ){
			if( k-num < cnt )
				y -= (k-num);
			else{
				k -= 2*cnt;
				x--;
				y -= (num-k-1);
			}
		}
		else{
			if( k-num < cnt )
				x -= (k-num);
			else{
				k -= 2*cnt;
				y--;
				x -= (num-k-1);
			}
		}

		printf("%d %d\n",x,y);

	}

	return 0;
}
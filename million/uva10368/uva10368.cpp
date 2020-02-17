#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int a,b;
	while( ~scanf("%d %d",&a,&b) && a|b ){

		bool ans = false;

		if( a != b ){
			int x = max(a,b);
			int y = min(a,b);

			while( true ){
				if( x/y > 1 )
					break;
				x = x%y;
				swap(x,y);
				ans ^= 1;
			}

		}

		printf("%s wins\n",ans?"Ollie":"Stan");

	}

	return 0;
}
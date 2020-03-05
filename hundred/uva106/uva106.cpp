#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool table[MAXN+10];

int main(int argc, char const *argv[])
{

	int num;
	int x,y,z;
	while( ~scanf("%d",&num) && num ){

		memset(table, 0, sizeof(table));
		int tuple = 0;
		for(int i = 1 ; i <= sqrt(num) ; i++ ){
			for(int j = i+1 ; ; j+=2 ){
				
				if( __gcd(i,j) != 1 ) continue;

				x = j*j-i*i;
				y = 2*j*i;
				z = j*j+i*i;
				if( x > num || y > num || z > num ) break;
				
				tuple++;
				int a = x,b = y,c = z;
				while( a <= num && b <= num && c <= num ){
					table[a] = table[b]	= table[c] = true;
					a += x;
					b += y;
					c += z;
				}

			}
		}

		int notused = num;
		for(int i = 1 ; i <= num ; i++ )
			if( table[i] ) notused--;

		printf("%d %d\n",tuple,notused);

	}

	return 0;
}
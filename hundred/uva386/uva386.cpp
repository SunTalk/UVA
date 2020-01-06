#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 200
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	for(int a = 6 ; a <= MAXN ; ++a )
		for(int b = 2 ; b < a ; ++b )
			for(int c = b ; c < a ; ++c )
				for(int d = c ; d < a ; ++d )
					if( a*a*a == b*b*b+c*c*c+d*d*d )
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);

	return 0;
}
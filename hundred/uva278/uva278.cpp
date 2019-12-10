#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d\n",&kase);

	char kind;
	int m,n;
	while( kase-- ){

		scanf("%c %d %d\n", &kind, &m, &n);
		if( kind == 'r' )
			printf("%d\n",min(m,n));
		if( kind == 'k')
			printf("%d\n",(m*n+1)/2);
		if( kind == 'Q' )
			printf("%d\n",min(m,n));
		if( kind == 'K' )
			printf("%d\n",((m+1)/2)*((n+1)/2));

	}

	return 0;
}
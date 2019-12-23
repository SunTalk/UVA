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

	int G,L;

	while( kase-- ){
		scanf("%d %d", &G, &L );
		if( L%G == 0 ) printf("%d %d\n", G, L);
		else printf("-1\n");
	}

	return 0;
}
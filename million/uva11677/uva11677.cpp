#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int Sh,Sm,Eh,Em;

	while( ~scanf("%d %d %d %d", &Sh, &Sm, &Eh, &Em ) && (Sh|Sm|Eh|Em) ){
		int S = Sh*60+Sm;
		int E = Eh*60+Em;
		if( E < S ) E += 60*24;
		printf("%d\n",E-S);
	}

	return 0;
}
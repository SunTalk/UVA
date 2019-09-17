#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12279"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int tmp,a,b;
	int kase = 1;

	while( ~scanf("%d", &num) && num ){

		a = b = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d", &tmp);
			if( tmp == 0 )
				b++;
			else
				a++;
		}

		printf("Case %d: %d\n",kase++,a-b);

	}

	return 0;
}
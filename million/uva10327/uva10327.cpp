#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10327"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int table[MAXN+5];

	while( ~scanf("%d",&num) ){

		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		int ans = 0;

		for(int i = 0 ; i < num ; i++ ){
			for(int j = num-1 ; j > i ; j-- ){
				if( table[j] < table[j-1] ){
					ans++;
					swap(table[j],table[j-1]);
				}
			}
		}

		printf("Minimum exchange operations : %d\n", ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1614"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

pair<int,int> table[MAXN+5];
int ANS[MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	while( ~scanf("%d",&num) ){
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&table[i].first);
			table[i].second = i;
		}
		sort(&table[0],&table[num]);
		int a = 0,b = 0;
		for(int i = num-1 ; i >= 0 ; i-- ){
			if( a > b ){
				b += table[i].first;
				ANS[table[i].second] = 1;
			}
			else{
				a += table[i].first;
				ANS[table[i].second] = -1;
			}
		}
		if( a == b ){
			printf("Yes\n");
			for(int i = 0 ; i < num-1 ; i++ )
				printf("%d ",ANS[i] );
			printf("%d\n",ANS[num-1] );
		}
		else
			printf("No\n");
	}

	return 0;
}
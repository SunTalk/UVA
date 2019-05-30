#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "846"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
int table[MAXN];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int add = 1;
	table[0] = 0;
	for(int i = 1 ; i < MAXN ; i++ ){
		table[i] = table[i-1] + add;
		if( i%2 == 0 )
			add++;
		if( table[i] < 0 )
			table[i] = INT_MAX;
	}

	int CASE;
	scanf("%d",&CASE);
	int a,b;

	while( CASE-- ){
		scanf("%d %d",&a,&b);
		for(int i = 0 ; i < MAXN ; i++ ){
			if( b-a <= table[i] ){
				printf("%d\n",i );
				break;
			}
		}
	}

	return 0;
}
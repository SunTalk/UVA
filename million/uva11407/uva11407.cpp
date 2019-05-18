#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11407"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int table[10005];
	memset(table,1,sizeof(table));

	table[0] = 0;
	for(int i = 1 ; i < 105 ; i++ ){
		for(int j = i*i ; j < 10005 ; j++ ){
			table[j] = min(table[j],table[j-(i*i)]+1);
		}
	}

	int num,ans;
	while( CASE-- ){
		
		scanf("%d",&num);
		printf("%d\n",table[num] );

	}

	return 0;
}
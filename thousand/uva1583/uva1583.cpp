#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1583"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100005

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN];
	memset(table,0,sizeof(table));
	int num,ans;
	for(int i = 0 ; i < MAXN ; i++ ){
		ans = num = i;
		while( num > 0 ){
			ans = ans + num%10;
			num /= 10;
		}
		if( table[ans] == 0 )
			table[ans] = i;
	}

	int times;
	scanf("%d",&times);

	while( times-- ){
		scanf("%d",&num);
		printf("%d\n",table[num] );
	}

	return 0;
}
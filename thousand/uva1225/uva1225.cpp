#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1225"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[10005][10];
	memset(table,0,sizeof(table));
	int tmp,i,j;
	
	for( i = 1 ; i < 10005 ; i++ ){
		tmp = i;
		for( j = 0 ; j < 10 ; j++ )
			table[i][j] = table[i-1][j];
		while( tmp > 0 ){
			j = tmp%10;
			tmp = tmp/10;
			table[i][j]++;
		}
	}

	int times,number;
	scanf("%d",&times);
	while( times-- ){
		scanf("%d",&number);
		for( i = 0 ; i < 9 ; i++ )
			printf("%d ",table[number][i] );
		printf("%d\n",table[number][9] );
	}

	return 0;
}
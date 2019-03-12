#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10178"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[100];
	char one,two;
	int point,edge;
	int tmp_a,tmp_b,i;

	while( ~scanf("%d %d\n", &point, &edge ) ){

		for( i = 0 ; i < 100 ; i++ )
			table[i] = i;

		int ans = 1;
		for( i = 0 ; i < edge ; i++ ){

			scanf("%c %c\n", &one, &two );
			
			tmp_a = one - 'A';
			tmp_b = two - 'A';

			while( table[tmp_a] != tmp_a )
				tmp_a = table[tmp_a];

			while( table[tmp_b] != tmp_b )
				tmp_b = table[tmp_b];

			if( tmp_a == tmp_b )
				ans++;
			else
				table[tmp_b] = tmp_a;

		}

		printf("%d\n",ans );

	}

	return 0;
}
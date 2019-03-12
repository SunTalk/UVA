#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10106"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string one,two;
	int table[1000];
	int tmp_a,tmp_b,i,j;

	while( cin >> one >> two ){

		if( one == "0" || two == "0" ){
			printf("0\n");
			continue;
		}

		memset(table,0,sizeof(table));
		tmp_a = one.size();
		tmp_b = two.size();

		for( i = tmp_a-1 ; i >= 0 ; i-- )
			for( j = tmp_b-1 ; j >= 0 ; j-- )
				table[i+j+1] = table[i+j+1] + (one[i]-'0')*(two[j]-'0'); 

		for( i = tmp_a+tmp_b-1 ; i > 0 ; i-- ){
			if( table[i] > 9 ){
				j = table[i] - table[i]%10;
				j = j/10;
				table[i] = table[i]%10;
				table[i-1] = table[i-1] + j;
			}
		}

		if( table[0] != 0 )
			printf("%d",table[0] );
		for( i = 1 ; i < tmp_a+tmp_b ; i++ )
			printf("%d",table[i] );
		printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10405"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[10005][2];
	string one,two;
	int i,j;

	while( getline(cin,one) ){
		getline(cin,two);
		
		memset(table,0,sizeof(table));

		for( i = 0 ; i < two.size() ; i++ ){
			for( j = 1 ; j <= one.size() ; j++ ){
				if( two[i] == one[j-1] )
					table[j][1] = table[j-1][0]+1;
				else
					table[j][1] = max(table[j-1][1],table[j][0]);
			}
			for( j = 1 ; j <= one.size() ; j++ )
				table[j][0] = table[j][1];
		}

		printf("%d\n", table[one.size()][1] );

	}

	return 0;
}
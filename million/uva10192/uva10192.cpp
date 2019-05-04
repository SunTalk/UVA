#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10192"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string one,two;
	int table[105][2];
	int CASE = 1;

	while( getline(cin,one) ){
		if( one == "#" )
			break;
		getline(cin,two);

		memset(table,0,sizeof(table));

		for(int i = 1 ; i <= one.size() ; i++ ){
			for(int j = 1 ; j <= two.size() ; j++ ){
				if( one[i-1] == two[j-1] )
					table[j][1] = table[j-1][0]+1;
				else
					table[j][1] = max(table[j-1][1],table[j][0]);
			}
			for(int j = 1 ; j <= two.size() ; j++ )
				table[j][0] = table[j][1];
		}

		printf("Case #%d: you can visit at most %d cities.\n",CASE++,table[two.size()][1]);

	}

	return 0;
}
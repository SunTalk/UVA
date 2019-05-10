#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10739"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

int table[MAXN+5][MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	string str;
	int cases = 1;
	
	while( CASE-- ){

		cin >> str;
		memset(table,0,sizeof(table));

		for(int i = 0 ; i < str.size() ; i++ )
			for(int j = 0 ; j < str.size() ; j++ )
				table[i][j] = 0;

		for(int j = 0 ; j < str.size()  ; j++ ){
			for(int i = 0, k = j ; i < str.size(),k < str.size() ; i++,k++ ){				
				
				if( str[i] == str[k] )
					table[i][k] = table[i+1][k-1];
				else
					table[i][k] = min(table[i+1][k-1],min(table[i][k-1],table[i+1][k])) + 1;
					
			}
		}

		printf("Case %d: %d\n",cases++, table[0][str.size()-1]);		
	
	}

	return 0;
}
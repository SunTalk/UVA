#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11577"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d\n",&CASE);

	string str;
	int table[30];

	while( CASE-- ){

		getline(cin,str);
		memset(table,0,sizeof(table));

		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] >= 'a' && str[i] <= 'z' )
				table[str[i]-'a']++;
			if( str[i] >= 'A' && str[i] <= 'Z' )
				table[str[i]-'A']++;
		}

		int big = 0;
		for(int i = 0 ; i < 30 ; i++ ){
			if( table[i] > big )
				big = table[i];
		}

		for(int i = 0 ; i < 30 ; i++ ){
			if( table[i] == big )
				printf("%c",i+'a' );
		}
		printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "499"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 300

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5],ans;
	string str;

	while( getline(cin,str) ){
		
		memset(table,0,sizeof(table));
		ans = 0;
		for(int i =	 0 ; i < str.size() ; i++ ){
			if( !isalpha(str[i]) )
				continue;
			table[str[i]]++;
			if( table[str[i]] > ans )
				ans = table[str[i]];
		}

		for(int i =	'A' ; i <=	'Z' ; i++ )
			if( table[i] == ans )
				printf("%c",i);
		for(int i =	'a' ; i <=	'z' ; i++ )
			if( table[i] == ans )
				printf("%c",i);
		printf(" %d\n",ans );

	}

	return 0;
}
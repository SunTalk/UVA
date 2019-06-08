#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10222"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string one,two;
	one = "ertyuiop[]asdfghjkl;'zxcvbnm,./qw";
	two = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";

	map <char,char> table;
	for(int i = 0 ; i < one.size() ; i++ )
		table[one[i]] = two[i];

	char tmp;
	while( ~scanf("%c",&tmp) ){
		if( table.find(tmp) != table.end() )
			printf("%c",table[tmp] );
		else
			printf("%c",tmp );
	}

	return 0;
}
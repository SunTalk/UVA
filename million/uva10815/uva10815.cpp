#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10815"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char word;
	map <string,int> table;
	string str = "";

	while( ~scanf("%c",&word) ){
		if( isalpha(word) ){
			str = str+word;
		}
		else if( str != "" ){
			transform(str.begin(),str.end(),str.begin(),::tolower);
			table[str] = 1;
			str = "";
		}
	}

	for(auto i : table )
		cout << i.first << endl;

	return 0;
}
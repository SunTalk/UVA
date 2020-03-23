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

	set <string> table;
	char word;
	string str = "";

	while( ~scanf("%c",&word) ){
		if( isalpha(word) ){
			str = str+word;
		}
		else if( str != "" ){
			transform(str.begin(),str.end(),str.begin(),::tolower);
			table.insert(str);
			str = "";
		}
	}

	if( str != "" ){
		transform(str.begin(),str.end(),str.begin(),::tolower);
		table.insert(str);
	}

	for(auto i : table )
		cout << i << endl;

	return 0;
}
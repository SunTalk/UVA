#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12250"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	map <string,string> table;
	table["HELLO"] = "ENGLISH";
	table["HOLA"] = "SPANISH";
	table["HALLO"] = "GERMAN";
	table["BONJOUR"] = "FRENCH";
	table["CIAO"] = "ITALIAN";
	table["ZDRAVSTVUJTE"] = "RUSSIAN";

	string str;
	int kase = 1;

	while( cin >> str && str != "#" ){
		printf("Case %d: ", kase++ );
		if( table[str] != "" )
			cout << table[str] << endl;
		else
			cout << "UNKNOWN" << endl;
	}

	return 0;
}
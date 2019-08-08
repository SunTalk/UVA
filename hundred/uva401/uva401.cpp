#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "401"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

map <char,char> table;

bool is_mir(string str){

	for(int i = 0,j = str.size()-1 ; i <= j ; i++,j-- )
		if( table[str[i]] != str[j] )
			return false;
	return true;

}

bool is_pal(string str){

	string tmp = str;
	reverse(tmp.begin(), tmp.end());
	if( str == tmp )
		return true;
	return false;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char c[21] = {'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
	char r[21] = {'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'};

	for(int i = 0 ; i < 21 ; i++ )
		table[c[i]] = r[i];

	string str;
	while( cin >> str ){

		if( is_pal(str) ){
			if( is_mir(str) )
				cout << str << " -- is a mirrored palindrome.\n\n";
			else
				cout << str << " -- is a regular palindrome.\n\n";
		}
		else if( is_mir(str) ){
			cout << str << " -- is a mirrored string.\n\n";
		}
		else{
			cout << str << " -- is not a palindrome.\n\n" ;
		}

	}

	return 0;
}
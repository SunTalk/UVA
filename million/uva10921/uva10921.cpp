#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10921"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

string change(string str){

	for(int i = 0 ; i < str.size() ; i++ ){
		if( 'A' <= str[i] && str[i] <= 'C' )
			str[i] = '2';
		if( 'D' <= str[i] && str[i] <= 'F' )
			str[i] = '3';
		if( 'G' <= str[i] && str[i] <= 'I' )
			str[i] = '4';
		if( 'J' <= str[i] && str[i] <= 'L' )
			str[i] = '5';
		if( 'M' <= str[i] && str[i] <= 'O' )
			str[i] = '6';
		if( 'P' <= str[i] && str[i] <= 'S' )
			str[i] = '7';
		if( 'T' <= str[i] && str[i] <= 'V' )
			str[i] = '8';
		if( 'W' <= str[i] && str[i] <= 'Z' )
			str[i] = '9';
	}
	return str;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	while( cin >> str )
		cout << change(str) << endl;

	return 0;
}
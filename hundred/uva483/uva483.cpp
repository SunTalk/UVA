#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "483"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	stack <char > rev;

	while( getline(cin,str) ){

		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] != ' ' ){
				rev.push(str[i]);
			}
			else{
				while( !rev.empty() ){
					cout << rev.top();
					rev.pop();
				}
				cout << " ";
			}
		}
		while( !rev.empty() ){
			cout << rev.top();
			rev.pop();
		}
		cout << "\n";

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "353"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str,tmp,cmp;
	map <string,bool> data;

	while( cin >> str ){

		data.clear();

		for(int i = 0 ; i < str.size() ; i++ ){
			for(int j = 1 ; j <= str.size()-i ; j++ ){
				cmp = tmp = str.substr(i,j);
				reverse(cmp.begin(), cmp.end());
				if( tmp == cmp )
					data[tmp] = true;

			}
		}

		cout << "The string '" << str <<  "' contains "<< data.size() <<" palindromes." << endl;
		
	}


	return 0;
}
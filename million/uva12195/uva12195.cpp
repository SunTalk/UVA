#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12195"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	char table[7] = {'W','H','Q','E','S','T','X'};
	double tmp;
	int ans;


	while( getline(cin,str) && str != "*" ){
		
		ans = 0;
		for(int i = 0 ; i < str.size() ; i++ ){

			if( str[i] == '/' ){
				if( tmp == 1 )
					ans++;
				tmp = 0;
			}
			for(int j = 0 ; j < 7 ; j++ )
				if( str[i] == table[j] )
					tmp += 1/pow(2,j);

		}

		printf("%d\n",ans );

	}

	return 0;
}
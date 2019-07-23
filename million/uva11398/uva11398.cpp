#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11398"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	string num = "";
	int ans;
	char flag;

	while( cin >> str && str != "~" ){

		if( str == "#" ){
			
			ans = 0;
			for(int i = 0 ; i < num.size() ; i++ ){
				ans *= 2;
				if( num[i] == '1' )
					ans += 1;
			}
			num = "";
			printf("%d\n", ans );

		}
		else if( str.size() == 1 ){
			flag = '1';
		}
		else if( str.size() == 2 ){
			flag = '0';
		}
		else{
			for(int i = 0 ; i < str.size()-2 ; i++ )
				num += flag;
		}

	}

	return 0;
}
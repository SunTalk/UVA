#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10878"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int num,digital;
	while( getline(cin,str) ){
		if(str[0] == '_')
			continue;
		num = 0;
		digital = 1;
		for(int i = 9 ; i > 0 ; i-- ){
			if( str[i] == '.' )
				continue;
			if( str[i] == 'o' )
				num = num + digital;
			digital = digital * 2;
		}
		char tmp = num;
		printf("%c", num );
	}

	return 0;
}
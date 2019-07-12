#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10473"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	stringstream ss;
	int num;

	while( cin >> str ){
		
		if( str[0] == '-' )
			break;
		
		ss.clear();
		ss.str(str);

		if( str[1] == 'x' ){
			ss >> hex >> num;
			printf("%d\n",num );
		}
		else{
			ss >> dec >> num;
			printf("0x%X\n",num );
		}

	}

	return 0;
}
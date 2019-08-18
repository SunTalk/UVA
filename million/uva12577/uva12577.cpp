#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12577"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int kase = 1;
	while( cin >> str && str != "*" ){
		if( str == "Hajj" )
			printf("Case %d: Hajj-e-Akbar\n",kase++ );
		else
			printf("Case %d: Hajj-e-Asghar\n",kase++ );
	}

	return 0;
}
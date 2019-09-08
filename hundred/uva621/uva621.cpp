#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "621"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	regex neg("^.*35$");
	regex fail("^9.*4$");

	int kase;
	scanf("%d",&kase);
	string str;

	while( kase-- ){
		cin >> str;
		if( str == "1" || str == "4" || str == "78" )
			printf("+\n");
		else if( regex_match(str,neg) )
			printf("-\n");
		else if( regex_match(str,fail) )
			printf("*\n");
		else
			printf("?\n");
	}

	return 0;
}
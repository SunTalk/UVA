#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12289"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d\n",&CASE);
	string str;

	while( CASE-- ){

		cin >> str;
		
		if( str.size() == 5 )
			printf("3\n");
		else if( (str[0] == 'o' && str[1] == 'n') || (str[0] == 'o' && str[2] == 'e') || (str[1] == 'n' && str[2] == 'e') )
			printf("1\n");
		else
			printf("2\n");

	}

	return 0;
}
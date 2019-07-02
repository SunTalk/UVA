#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "13216"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	string str;

	while( CASE-- ){
		
		cin >> str;

		if( str == "0" )
			printf("1\n");
		else if( str == "1" )
			printf("66\n");
		else{
			int ans = str[str.size()-1] - '0' + 9;
			ans %= 5;
			if( ans == 1 )
				printf("56\n");
			if( ans == 2 )
				printf("96\n");
			if( ans == 3 )
				printf("36\n");
			if( ans == 4 )
				printf("76\n");
			if( ans == 0 )
				printf("16\n");
		}

	}

	return 0;
}
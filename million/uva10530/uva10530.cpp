#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10530"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,lower,upper;
	lower = 0;
	upper = 11;
	string action;
	bool ans = true;

	while( ~scanf("%d",&num) && num ){

		getline(cin,action);

		if( action == "too high" ){
			if( num < lower )
				ans = false;
			else if( num < upper )
				upper = num;
		}
		if( action == "too low" ){
			if( num > upper )
				ans = false;
			else if( num > lower )
				lower = num;
		}
		if( action == "right on" ){
			if(ans && num > lower && num < upper)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			ans = true;
			upper = 11;
			lower = 0;
		}

	}

	return 0;

}
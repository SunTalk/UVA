#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12439"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	string month;
	int day,year;
	int one,two;

	for(int k = 1 ; k <= kase ; k++ ){
		
		cin >> month;
		scanf("%d, %d", &day, &year);
		if( month == "January" || month == "February" )
			year--;
		one = year/4 - year/100 + year/400;

		cin >> month;
		scanf("%d, %d", &day, &year);
		if( month == "January" || month == "February" )
			year--;
		if( month == "February" && day == 29 )
			year++;
		two = year/4 - year/100 + year/400;

		printf("Case %d: %d\n", k, two-one );

	}

	return 0;
}
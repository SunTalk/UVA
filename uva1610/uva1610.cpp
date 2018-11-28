#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1610"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string name[1005];
	string one,two;
	string ans;
	int number,i;

	while( scanf("%d",&number) && number ){
		for( i = 1 ; i <= number ; i++ )
			cin >> name[i];

		sort(name+1,name+number+1);
		
		one = name[number/2];
		two = name[number/2+1];

		i = 0;
		ans = "A";

		while( i < one.size() ){
			while( ans < one && ans[i] <= 'Z' )
				ans[i]++;

			if( ans[i] <= 'Z' && one <= ans && ans < two )
				break;

			if( one[i] != ans[i] )
				ans[i]--;

			ans = ans + 'A';
			++i;
		}

		cout << ans << endl;

	}

	return 0;
}
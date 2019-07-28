#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11687"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int tmp,ans;

	while( cin >> str && str != "END" ){

		if( str == "1" ){
			printf("1\n");
			continue;
		}

		ans = 2;
		tmp = str.size();

		while( tmp != 1 ){
			int check = 0;

			while( tmp > 0 ){
				tmp /= 10;
				check++;
			}
			tmp = check;
			ans++;
		}

		printf("%d\n",ans );

	}

	return 0;
}
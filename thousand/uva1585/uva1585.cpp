#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1585"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	string str;
	int sum,ans;

	while( kase-- ){

		cin >> str;
		sum = ans = 0;
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == 'O' ){
				sum++;
				ans += sum;
			}
			else
				sum = 0;
		}
		printf("%d\n",ans);

	}

	return 0;
}
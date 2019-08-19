#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "575"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[35];
	for(int i = 0 ; i < 35 ; i++ )
		table[i] = pow(2,i)-1;
	table[31] = INT_MAX;

	string str;
	while( cin >> str && str != "0" ){
		reverse(str.begin(), str.end());
		int ans = 0;
		for(int i = 0 ; i < str.size() ; i++ )
			ans += ((str[i]-'0')*table[i+1]);
		printf("%d\n",ans );
	}

	return 0;
}
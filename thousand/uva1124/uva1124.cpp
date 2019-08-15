#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1124"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	while( getline(cin,str) )
		cout << str << endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "13178"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int num;

	while( CASE-- ){
		scanf("%d",&num);
		cout << ( num%3 == 1 ? "NO":"YES" ) << endl;
	}

	return 0;
}
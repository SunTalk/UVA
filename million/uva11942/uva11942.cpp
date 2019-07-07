#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11942"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int num[15];
	int S[15];
	
	cout << "Lumberjacks:" << endl;

	while( CASE-- ){

		for(int i = 0 ; i < 10 ; i++ ){
			scanf("%d",&num[i]);
			S[i] = num[i];
		}

		sort(&S[0],&S[10]);

		bool order = false;

		int i;
		for( i = 0 ; i < 10 ; i++ ){
			if( num[i] != S[i] )
				break;
		}
		if( i == 10 )
			order = true;

		reverse(&S[0],&S[10]);
		for( i = 0 ; i < 10 ; i++ ){
			if( num[i] != S[i] )
				break;
		}
		if( i == 10 )
			order = true;

		if( order )
			cout << "Ordered" << endl;
		else
			cout << "Unordered" << endl;

	}

	return 0;
}
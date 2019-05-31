#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11220"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d\n\n",&CASE);
	// getchar('\n');
	string str;
	int Case=1;

	while( CASE-- ){

		if( Case != 1 )
			printf("\n");

		printf("Case #%d:\n",Case++ );
		while( getline(cin,str) && str != "" ){
			string ans = "";
			int tmp = 1;
			int coun = 1;
			for(int i = 0 ; i < str.size() ; i++ ){
				if( str[i] == ' ' )
					tmp = 0;
				if( tmp == coun ){
					coun++;
					tmp++;
					ans = ans + str[i];
				}
				tmp++;
			}
			cout << ans << endl;
		}

	}

	return 0;
}
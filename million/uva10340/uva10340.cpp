#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10340"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string substr,str;
	while( cin >> substr >> str ){
		int i = 0;
		bool ans = false;
		for(int j = 0 ; j < str.size() ; j++ ){
			if( str[j] == substr[i] )
				i++;
			if( i == substr.size() )
				ans = true;
		}
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
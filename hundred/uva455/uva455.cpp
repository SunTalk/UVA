#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "455"

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
	string str,one,two;
	int ans;

	while( kase-- ){
		
		cin >> str;
		ans = str.size();
		int k = 0;
		for(int i = 1 ; i <= str.size() ; i++ ){
			if( str.size()%i == 0 )
				for( k = i ; k < str.size() ; k++ )
					if( str[k] != str[k%i] )
						break;
			if( k == str.size() ){
				ans = i;
				break;
			}
		}

		printf("%d\n",ans);
		if(kase)
			printf("\n");

	}

	return 0;
}
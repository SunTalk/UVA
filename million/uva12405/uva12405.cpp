#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12405"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int num,ans;
	string str;

	for(int k = 1 ; k <= kase ; k++ ){

		ans = 0;
		scanf("%d",&num);
		cin >> str;
		
		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == '.' ){
				ans++;
				i += 2;
			}
		}

		printf("Case %d: %d\n", k,ans);


	}

	return 0;
}
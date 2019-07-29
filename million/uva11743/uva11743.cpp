#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11743"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int kase;
	scanf("%d\n",&kase);
	int odd[8] = {1,3,6,8,11,13,16,18};
	int even[8] = {0,2,5,7,10,12,15,17};

	while( kase-- ){

		getline(cin,str);
		int tmp,ans = 0;
		
		for(int i = 0 ; i < 8 ; i++ ){
			tmp = (str[even[i]]-'0');
			tmp *= 2;
			ans += (tmp%10);
			ans += (tmp/10);
			ans += (str[odd[i]]-'0');
		}

		if( ans%10 == 0 )
			printf("Valid\n");
		else
			printf("Invalid\n");

	}

	return 0;
}
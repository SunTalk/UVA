#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11541"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);
	string str;
	int Case = 1;

	while( kase-- ){
		
		printf("Case %d: ",Case++);

		cin >> str;
		char tmp;
		int num = 0;
		for(int i = 0 ; i <= str.size() ; i++ ){
			if( i == str.size() || str[i] >= 'A' && str[i] <= 'Z' ){
				for(int j = 0 ; j < num ; j++ )
					cout << tmp ;
				num = 0;
				tmp = str[i];
			}
			else{
				num *= 10;
				num = num + (str[i]-'0');
			}
		}
		cout << endl;

	}

	return 0;
}
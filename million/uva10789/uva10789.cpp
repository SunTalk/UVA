#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10789"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isPrime(int n)
{
	if( n == 0 || n == 1 )
		return false;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[100];
	string str,ans;

	int kase;
	scanf("%d",&kase);
	int CASE = 1;

	while( kase-- ){

		printf("Case %d: ",CASE++ );
		
		cin >> str;
		memset(table,0,sizeof(table));
		for(int i = 0 ; i < str.size() ; i++ )
			table[str[i]-'0']++;

		ans = "";
		for(int i = 0 ; i < 100 ; i++ ){
			if( isPrime(table[i]) ){
				char tmp = i+'0';
				ans = ans+tmp;
			}
		}

		if( ans == "" )
			cout << "empty" << endl ;
		else
			cout << ans << endl;

	}

	return 0;
}
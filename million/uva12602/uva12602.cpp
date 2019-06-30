#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12602"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	string str;
	int a,b;

	while( CASE-- ){
		
		cin >> str;
		a = (str[0]-'A')*676 + (str[1]-'A')*26 + (str[2]-'A') ;
		b = (str[4]-'0')*1000 + (str[5]-'0')*100 + (str[6]-'0')*10 + (str[7]-'0') ;
		
		if( abs(a-b) <= 100 )
			printf("nice\n");
		else
			printf("not nice\n");
	
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10922"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int change(int num){
	int tmp = 0;
	while( num > 0 ){
		tmp = tmp + num%10;
		num = num/10;
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string number;
	int num,ans,i;
	
	while( cin >> number ){

		if( number == "0" )
			break;

		num = 0;
		for( i = 0 ; i < number.size() ; i++ )
			num = num + number[i]-'0';

		ans = 1;
		while( num % 9 == 0 ){
			if( num == 9 )
				break;
			num = change(num);
			ans++;
		}

		cout << number;

		if( num == 9 )
			printf(" is a multiple of 9 and has 9-degree %d.\n",ans );
		else
			printf(" is not a multiple of 9.\n");
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11879"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool solve(string num ){
	if( num.size() < 10 ){
		int ans = 0;
		for(int i = 0 ; i < num.size() ; i++ )
			ans = ans*10 + num[i]-'0';
		return ans%17 == 0;
	}

	char tmp = num[num.size()-1];
	num = num.substr(0,num.size()-1);

	for(int i = 0 ; i < 5 ; i++ ){
		int j = num.size()-1;
		bool overflow = false;
		if( num[j] >= tmp )
			num[j] = num[j]-tmp+'0';
		else{
			num[j] = num[j]-tmp+10+'0';
			overflow = true;
		}
		while( overflow ){
			j--;
			num[j] = num[j]-1;
			if( num[j] < '0' )
				num[j] = num[j]+10;
			else
				overflow = false;
		}
	}

	return solve(num);

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string num;
	while( cin >> num ){
		if( num == "0" )
			break;
		if( solve(num) )
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "424"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

string ADD(string a, string b){
	
	string ans = "";
	int A = a.size()-1;
	int B = b.size()-1;

	int add = 0;
	int tmp;

	while( A >= 0 || B >= 0 || add > 0 ){

		if( A >= 0 )
			add += (a[A--]-'0');
		if( B >= 0 )
			add += (b[B--]-'0');

		tmp = add%10;
		add /= 10;

		char k = tmp+'0';
		ans = ans + k;

	}

	reverse(ans.begin(), ans.end());
	return ans;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	string ANS = "";

	while( cin >> str )
		ANS = ADD(ANS,str);

	cout << ANS <<endl;

	return 0;
}
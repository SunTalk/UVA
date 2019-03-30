#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11192"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	string str,ans;
	stack <char> s;

	while( ~scanf("%d",&num) && num ){
		cin >> str;
		ans = "";
		num = str.size()/num;
		for(int i = 0 ; i < str.size() ; i++ ){
			s.push(str[i]);
			if( s.size() == num ){
				while( !s.empty() ){
					ans = ans + s.top();
					s.pop();
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
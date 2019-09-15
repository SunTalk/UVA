#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "156"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

bool cmp(string a,string b){
	
	transform(a.begin(),a.end(),a.begin(),::tolower);
	transform(b.begin(),b.end(),b.begin(),::tolower);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if( a == b )
		return true;
	return false;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	string str;
	list <string> table;
	list <string> rm;
	while( cin >> str && str != "#"){
		bool check = true;
		for(auto i = table.begin() ; i != table.end() ; i++ ){
			if( cmp(str,*i) ){
				check = false;
				rm.push_back(*i);
				table.erase(i);
				break;
			}
		}
		if( check ){
			for(auto i = rm.begin() ; i != rm.end() ; i++ ){
				if( cmp(str,*i) ){
					check = false;
					break;
				}
			}
		}

		if( check )
			table.push_back(str);
	}

	table.sort();

	for(auto i = table.begin() ; i != table.end() ; i++ )
		cout << *i << endl;

	return 0;
}
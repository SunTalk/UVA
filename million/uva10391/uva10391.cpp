#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	string str;
	set <string> table;

	while( cin >> str )
		table.insert(str);

	for(auto s : table){
		for(int i = 1 ; i < s.size() ; i++ ){
			string one = s.substr(0,i);
			string two = s.substr(i,s.size());
			if( table.find(one) != table.end() && table.find(two) != table.end() ){
				cout << s << endl;
				break;
			}
		}
	}


	return 0;
}
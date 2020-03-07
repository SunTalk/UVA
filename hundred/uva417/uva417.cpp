#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

vector <string> table;
void build(string str){

	if( str.size() > 5 ) return;

	table.push_back(str);
	for(char i = str.size()==0?'a':str.back()+1 ; i <= 'z' ; i++ )
		build(str+i);
	
}

bool cmp(string a, string b){
	if( a.size() == b.size() )
		return a < b;
	return a.size() < b.size();
}

int main(int argc, char const *argv[])
{

	build("");
	sort(table.begin(), table.end(),cmp);
	map <string,int> ans;
	for(int i = 0 ; i < table.size() ; i++ )
		ans[table[i]] = i;

	string str;
	while( cin >> str ){
		if( ans.find(str) != ans.end() )
			cout << ans[str] << endl;
		else cout << "0" << endl;
	}

	return 0;
}
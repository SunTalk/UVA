#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10420"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	vector <pair<string,int> > table;
	pair<string,int > data;
	string space,name;
	scanf("%d",&times);

	while( times-- ){
		cin >> space;
		getline(cin,name);
		bool check = true;
		for(int i = 0 ; i < table.size() ; i++ ){
			if( table[i].first == space ){
				table[i].second++;
				check = false;
			}
		}
		if(check)
			table.emplace_back(space,1);
	}
	sort(table.begin(),table.end());
	for(int i = 0 ; i < table.size() ; i++ )
		cout << table[i].first << " " << table[i].second << endl;

	return 0;
}
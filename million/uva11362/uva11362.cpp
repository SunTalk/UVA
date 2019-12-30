#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	vector <string> table;
	string str;
	int num;

	while( kase-- ){
		
		scanf("%d",&num);
		table.clear();
		while( num-- ){
			cin >> str;
			table.push_back(str);
		}
		sort(table.begin(),table.end());
		
		bool ans = true;
		for(int i = 1 ; i < table.size() ; i++)
			if( table[i-1] == table[i].substr(0,table[i-1].size()) )
				ans = false;

		printf("%s\n", ans?"YES":"NO");

	}

	return 0;
}
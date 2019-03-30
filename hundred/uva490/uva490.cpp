#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "490"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	vector <string> table;
	string tmp;
	int num = 0;

	while( getline(cin,tmp) ){
		table.push_back(tmp);
		if( tmp.size() > num )
			num = tmp.size();
	}

	for(int i = 0 ; i < num ; i++ ){
		for(int j = table.size()-1 ; j >= 0 ; j-- ){
			if( i < table[j].size() )
				cout << table[j][i] ;
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
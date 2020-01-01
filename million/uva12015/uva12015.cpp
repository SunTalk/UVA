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

	for(int K = 1 ; K <= kase ; K++ ){

		table.clear();
		int MAX = 0;
		for(int i = 0 ; i < 10 ; i++ ){
			cin >> str >> num ;
			
			if( num > MAX ){
				table.clear();
				table.push_back(str);
				MAX = num;
			}
			else if( num == MAX ){
				table.push_back(str);
			}

		}

		printf("Case #%d:\n",K);
		for(int i = 0; i < table.size() ; i++ )
			cout << table[i] << endl;

	}

	return 0;
}
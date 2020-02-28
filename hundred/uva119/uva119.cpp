#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int num;
	string group[MAXN];
	map <string,int> table;
	bool check = false;

	while( ~scanf("%d",&num) && num ){

		for(int i = 0 ; i < num ; i++ ){
			cin >> group[i];
			table[group[i]] = 0;
		}

		int price,peo;
		string name;
		for(int i = 0 ; i < num ; i++ ){
			cin >> name >> price >> peo ;
			table[name] -= price;
			table[name] += peo==0?price:price%peo;
			for(int j = 0 ; j < peo ; j++ ){
				cin >> name;
				table[name] += price/peo;
			}
		}

		if( check ) cout << endl;
		check = true;
		for(int i = 0 ; i < num ; i++ ){
			cout << group[i] << " " << table[group[i]] << endl;
		}

	}

	return 0;
}
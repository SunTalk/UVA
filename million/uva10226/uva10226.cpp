#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d\n",&kase);

	for(int K = 1 ; K <= kase ; K++ ){

		string str;
		map <string,int> table;
		int total = 0;
		while( getline(cin,str) ){

			if( str == "" ) break;

			if( table.find(str) != table.end() )
				table[str]++;
			else table[str] = 1;
			total++;

		}

		for(auto i : table){
			cout << i.first << " ";
			double ans = double(i.second)/double(total);
			printf("%.4lf\n",ans*100); 
		}

		if( K != kase )
			printf("\n");

	}

	return 0;
}
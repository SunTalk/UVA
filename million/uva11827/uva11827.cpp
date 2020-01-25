#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d\n",&kase);
	
	string str;
	vector <int> table;
	int num;

	while ( kase-- ){
		
		getline(cin,str);
		stringstream ss(str);

		table.clear();
		while( ss>>num )
			table.push_back(num);

		int ans = 0;
		for(int i = 0 ; i < table.size() ; i++ )
			for(int j = i+1 ; j < table.size() ; j++ )
				ans = max(ans,__gcd(table[i],table[j]));

		printf("%d\n",ans);

	}

	return 0;
}
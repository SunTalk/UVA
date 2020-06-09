#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{


	int num;
	while( ~scanf("%d",&num) && num ){

		map <string,int> table;
		string str;
		int tmp[5];
		for(int i = 0 ; i < num ; i++ ){
			for(int j = 0 ; j < 5 ; j++ )
				scanf("%d",&tmp[j]);
			sort(tmp,tmp+5);
			str = "";
			for(int j = 0 ; j < 5 ; j++ )
				str += to_string(tmp[j]);
			if( table.find(str) != table.end() )
				table[str]++;
			else table[str] = 1;

		}

		int mmax = 0;
		for(auto i : table)
			mmax = max(i.second,mmax);
		int ans = 0;
		for(auto i : table)
			if( i.second == mmax )
				ans += mmax;

		printf("%d\n",ans);

	}

	return 0;
}
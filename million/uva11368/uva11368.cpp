#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11368"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Doll{
	int w,h;
	bool operator<(const Doll &rhs)const{
		return w < rhs.w && h < rhs.h;
	}
};

bool cmp( Doll &lhs, Doll &rhs ){
	if( lhs.w == rhs.w )
		return lhs.h > rhs.h;//避免第一維相同大小的娃娃互套
	return lhs.w < rhs.w;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);
	int num,w,h;
	vector <Doll> table;
	vector <Doll> ans;	
	
	while( CASE-- ){

		table.clear();
		ans.clear();

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d",&w,&h);
			table.push_back({w,h});
		}

		sort(table.begin(), table.end(),cmp);

		int i,j;
		ans.push_back(table[0]);
		for( i = 1 ; i < table.size() ; i++ ){
			for( j = 0 ; j < ans.size() ; j++ ){
				if( ans[j] < table[i] ){
					ans[j] = table[i];
					break;
				}
			}
			if( j == ans.size() )
				ans.push_back(table[i]);
		}

		printf("%d\n", ans.size() );

	}

	return 0;
}
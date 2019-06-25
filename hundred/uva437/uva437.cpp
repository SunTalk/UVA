#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "437"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Block{
	
	int L,W,H;
	bool operator<( const Block &rhs )const{
		if( L == rhs.L )
			return W < rhs.W;
		return L < rhs.L;
	};

};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int a,b,c;
	int table[1000];
	vector <Block> Tower;
	int Case = 1;

	while( ~scanf("%d",&num) && num ){

		Tower.clear();
		memset(table,0,sizeof(table));

		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d %d",&a,&b,&c);
			Tower.push_back({a,b,c});
			Tower.push_back({a,c,b});
			Tower.push_back({b,a,c});
			Tower.push_back({b,c,a});
			Tower.push_back({c,a,b});
			Tower.push_back({c,b,a});
		}
		sort(Tower.begin(), Tower.end());

		for(int i = 0 ; i < Tower.size() ; i++ )
			table[i] = Tower[i].H;

		int ANS = 0;
		for(int i = 0 ; i < Tower.size() ; i++ ){
			for(int j = i+1 ; j < Tower.size() ; j++ )
				if (Tower[j].L > Tower[i].L && Tower[j].W > Tower[i].W)
					if (table[i] + Tower[j].H > table[j])
						table[j] = table[i] + Tower[j].H;
			ANS = max(table[i], ANS);
		}

		printf("Case %d: maximum height = %d\n",Case++,ANS );

	}

	return 0;
}
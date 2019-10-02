#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

struct node{
	int num,R,C;
	node(){};
	node(int n, int r, int c){
		num = n, R = r, C = c;
	}
	bool operator<(const node &rhs)const{
		if( num == rhs.num ){
			if( R == rhs.R )
				return C < rhs.C;
			return R < rhs.R;
		}
		return num < rhs.num;
	};
};

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	string str;
	int row,column;
	int table[MAXN+5][MAXN+5];
	int ans[MAXN+5][MAXN+5];
	priority_queue <node> PQ;

	while( kase-- ){
		
		memset(table,0,sizeof(table));
		memset(ans,0,sizeof(ans));
		while( !PQ.empty() )
			PQ.pop();

		cin >> str;
		scanf("%d %d",&row,&column);
		for(int i = 0 ; i <= row+1 ; i++ ){
			for(int j = 0 ; j <= column+1 ; j++ ){
				if( i == 0 || j == 0 || i == row+1 || j == column+1 ){
					table[i][j] = 1000;
					continue;
				}
				scanf("%d",&table[i][j]);
			}
		}

		for(int i = 1 ; i <= row ; i++ ){
			for(int j = 1 ; j <= column ; j++ ){
				ans[i][j] = 1;
				node tmp(table[i][j],i,j);
				PQ.push(tmp);
			}
		}

		int ANS = 1;
		while( !PQ.empty() ){
			node tmp = PQ.top();

			if( table[tmp.R][tmp.C] < table[tmp.R-1][tmp.C] )
				ans[tmp.R][tmp.C] = max(ans[tmp.R][tmp.C],ans[tmp.R-1][tmp.C]+1);
			if( table[tmp.R][tmp.C] < table[tmp.R][tmp.C-1] )
				ans[tmp.R][tmp.C] = max(ans[tmp.R][tmp.C],ans[tmp.R][tmp.C-1]+1);
			if( table[tmp.R][tmp.C] < table[tmp.R+1][tmp.C] )
				ans[tmp.R][tmp.C] = max(ans[tmp.R][tmp.C],ans[tmp.R+1][tmp.C]+1);
			if( table[tmp.R][tmp.C] < table[tmp.R][tmp.C+1] )
				ans[tmp.R][tmp.C] = max(ans[tmp.R][tmp.C],ans[tmp.R][tmp.C+1]+1);
			ANS = max(ANS,ans[tmp.R][tmp.C]);

			PQ.pop();
		}

		cout << str << ": " << ANS << endl;

	}

	return 0;
}
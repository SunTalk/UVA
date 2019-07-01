#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "103"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Box{
	
	int id,len,pre;
	vector<int> edge;

	Box(){
		pre = -1;
		len = 1;
	};

	void S(){
		sort(edge.begin(), edge.end());
	}

	bool operator<( const Box &rhs )const{
		for(int i = 0 ; i < edge.size() ; i++ )
			if( !( edge[i] < rhs.edge[i] ) )
				return false;
		return true;
	}

};

bool cmp(Box &lhs, Box &rhs){
	int n = 0;
	while( lhs.edge[n] == rhs.edge[n] && n < lhs.edge.size() )
		n++;
	if( n == lhs.edge.size() )
		return lhs.id < rhs.id;
	return lhs.edge[n] < rhs.edge[n];
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	vector <Box> table;
	Box tmp;
	int box,dimension;
	int num,cur;
	stack <int> ans;

	while( ~scanf("%d %d",&box,&dimension) ){
		
		table.clear();
		for(int i = 1 ; i <= box ; i++ ){
			tmp.edge.clear();
			tmp.id = i;
			for(int i = 0 ; i < dimension ; i++ ){
				scanf("%d",&num);
				tmp.edge.push_back(num);
			}
			tmp.S();
			table.push_back(tmp);
		}
		sort(table.begin(), table.end(),cmp);

		int MAX = 0;
		for(int i = 0 ; i < table.size() ; i++ ){
			for(int j = i+1 ; j < table.size() ; j++ ){
				if( table[i] < table[j] ){
					if( table[i].len+1 > table[j].len ){
						table[j].len = table[i].len+1;
						table[j].pre = i;
					}
				}
			}
			if( table[i].len > MAX ){
				MAX = table[i].len;
				cur = i;
			}
		}

		printf("%d\n",MAX );

		do{
			ans.push(table[cur].id);
			cur = table[cur].pre;
		}while( cur != -1 );

		while( !ans.empty() ){
			printf("%d%c", ans.top(), ans.size()==1 ? '\n':' ' );
			ans.pop();
		}

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

struct edge{
	int to,len;
	bool operator<(const edge &rhs)const{
		return len > rhs.len;
	}
}E;

vector <edge> City[MAXN+5];

int table[MAXN+5][MAXN+5][2];

void dij(int k){

	E.to = k;
	E.len = 0;

	priority_queue <edge> PQ;
	PQ.push(E);

	while( !PQ.empty() ){
		E = PQ.top();
		PQ.pop();
		int T = E.to;
		int L = E.len;

		if( L < table[k][T][0] ){
			table[k][T][1] = table[k][T][0];
			table[k][T][0] = L;
		}
		else if( table[k][T][0] < L && L < table[k][T][1] )
			table[k][T][1] = L;
		else
			continue;

		edge tmp;
		for(auto i : City[T] ){
			tmp.to = i.to;
			tmp.len = L+i.len;
			PQ.push(tmp);
		}

	}

}

int main(int argc, char const *argv[])
{
	
	int n,r;
	int kase = 1;
	while( ~scanf("%d %d", &n, &r) ){

		printf("Set #%d\n", kase++);
		memset(table, INF, sizeof(table));
		for(int i = 0 ; i < n ; i++ )
			City[i].clear();

		int a,b,c;
		for(int i = 0 ; i < r ; i++ ){
			scanf("%d %d %d", &a, &b, &c);
			E.to = b,E.len = c;
			City[a].push_back(E);
			E.to = a;
			City[b].push_back(E);
		}

		for(int i = 0 ; i < n ; i++ )
			dij(i);

		int num;
		scanf("%d", &num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d", &a, &b);
			if( table[a][b][1] == INF )
				printf("?\n");
			else
				printf("%d\n",table[a][b][1]);
		}

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "908"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000

struct Node{
	int a,b,len;
	bool operator<(const Node &rhs )const{
		return len>rhs.len;
	}
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,count,pre_ans,ans;
	int table[MAXN+5];
	int a,b;
	priority_queue <Node > PQ;
	Node tmp;
	bool check = false;

	while( ~scanf("%d",&count) ){

		pre_ans = ans = 0;
		memset(table,0,sizeof(table));
		for(int i = 1 ; i < count ; i++ ){
			scanf("%d %d %d",&tmp.a,&tmp.b,&tmp.len);
			pre_ans = pre_ans + tmp.len;
			table[i] = i;
		}

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d %d",&tmp.a,&tmp.b,&tmp.len);
			PQ.push(tmp);
		}

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d %d",&tmp.a,&tmp.b,&tmp.len);
			PQ.push(tmp);
		}
		
		while( !PQ.empty() ){
			tmp = PQ.top();
			PQ.pop();
			a = tmp.a;
			b = tmp.b;
			while( table[a] != a )
				a = table[a];
			while( table[b] != b )
				b = table[b];
			if( table[a] == table[b] )
				continue;
			ans = ans + tmp.len;
			table[a] = table[b];
			count--;
			if( count == 0 )
				break;
		}

		if(check)
			printf("\n");
		printf("%d\n%d\n",pre_ans,ans );
		check = true;
	}

	return 0;
}
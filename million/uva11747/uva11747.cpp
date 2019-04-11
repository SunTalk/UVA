#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11747"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct Node{
	int a,b,len;
	bool operator<(const Node &ll )const{
		return len > ll.len;
	}
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[1005];
	int num,edge;
	vector <int> ans;
	Node tmp;

	while( ~scanf("%d %d",&num,&edge) ){
		if( num == 0 && edge == 0 )
			break;

		priority_queue <Node> PQ;
		ans.clear();

		for(int i = 0 ; i < num+5 ; i++ )
			table[i] = i;

		for(int i = 0 ; i < edge ; i++ ){
			scanf("%d %d %d",&tmp.a,&tmp.b,&tmp.len);
			PQ.push(tmp);
		}

		int one,two;
		while( !PQ.empty() ){
			tmp = PQ.top();
			PQ.pop();

			one = tmp.a;
			two = tmp.b;

			while( table[one] != one )
				one = table[one];
			while( table[two] != two )
				two = table[two];

			if( one == two )
				ans.push_back(tmp.len);
			else
				table[one] = two;

		}

		for(int i = 0 ; i < ans.size() ; i++ )
			printf("%d%c", ans[i], i==ans.size()-1 ? '\n':' ' );
		if( ans.size() == 0 )
			printf("forest\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10954"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 5000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num,tmp;
	priority_queue <int, vector<int>,greater<int>> table;

	while( ~scanf("%d",&num) && num ){

		while( !table.empty() )
			table.pop();

		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&tmp);
			table.push(tmp);
		}

		int ans = 0;
		while( table.size() > 1 ){

			int a = table.top();
			table.pop();
			int b = table.top();
			table.pop();

			ans += (a+b);
			table.push(a+b);

		}

		printf("%d\n",ans);

	}

	return 0;
}
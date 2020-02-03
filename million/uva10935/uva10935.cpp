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
	queue <int> Q;
	vector <int> ans;

	while( ~scanf("%d",&num) && num ){

		while( !Q.empty() ) Q.pop();
		ans.clear();

		for(int i = 1 ; i <= num ; i++ )
			Q.push(i);

		while( !Q.empty() ){
			ans.push_back(Q.front());
			Q.pop();
			if( Q.empty() ) break;
			Q.push(Q.front());
			Q.pop();
		}

		printf("Discarded cards:");
		for(int i = 0 ; i < ans.size()-1 ; i++ )
			printf(" %d%c",ans[i],(i==ans.size()-2)?'\n':',');
		if( ans.size() == 1 ) printf("\n");
		printf("Remaining card: %d\n",ans.back());
	
	}

	return 0;
}
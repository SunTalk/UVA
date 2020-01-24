#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int N,M,num;
	map <int,int> table;

	while( ~scanf("%d %d",&N,&M) && (N|M) ){

		table.clear();
		for(int i = 0; i < N ; i++ ){
			scanf("%d",&num);
			table[num] = 1;
		}
		int ans = 0;
		for(int i = 0; i < M ; i++ ){
			scanf("%d",&num);
			if( table[num] )
				ans++;
		}

		printf("%d\n",ans);

	}

	return 0;
}
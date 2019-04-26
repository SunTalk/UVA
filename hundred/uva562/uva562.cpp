#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "562"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	int num;
	int sum,tmp;
	int data[105];
	int pack[100005];

	while( CASE-- ){
		scanf("%d",&num);

		sum = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&data[i]);
			sum = sum + data[i];
		}

		int half = sum/2;
		memset(pack,0,sizeof(pack));
		for(int i = 0 ; i < num ; i++ ){
			for(int j = half ; j >= data[i] ; j-- ){
				pack[j] = max(pack[j],pack[j-data[i]]+data[i]);
			}
		}

		printf("%d\n", sum - pack[half] - pack[half] );


	}

	return 0;
}
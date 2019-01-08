#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1312"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	
	int num,x,y;
	pair<int,int> tree[105];
	int tmp,ans,ans_x,ans_y;
	int i,j,k;

	while( times-- ){
		
		scanf("%d %d %d",&num,&x,&y);

		for( i = 0 ; i < num ; i++ )
			scanf("%d %d",&tree[i].first,&tree[i].second);
		tree[num].first = tree[num].second = 0;
		tree[num+1].first = x;
		tree[num+1].second = y;
		sort(&tree[0],&tree[num+2]);

		// for( i = 0 ; i < num+2 ; i++ )
		// 	printf("%d %d\n",tree[i].first,tree[i].second);
		// printf("\n");
		ans = ans_x = ans_y = 0;
		for( i = 0 ; i < num+2 ; i++ ){
			for( j = i+1 ; j < num+2 ; j++ ){

				priority_queue <int,vector<int>,greater<int>> PQ;
				PQ.push(y);
				for( k = i ; k <= j ; k++ ){
					if( tree[k].first > tree[i].first && tree[k].first < tree[j].first )
						PQ.push(tree[k].second);
				}

				int len = tree[j].first - tree[i].first;
				int cnt = 0;

				while( !PQ.empty() ){
					tmp = PQ.top();
					int check = min(len,tmp-cnt);
					if( check > ans ){
						ans = check;
						ans_x = tree[i].first;
						ans_y = cnt;
					}
					// printf("check: %d %d %d\n",tree[i].first,cnt,check );
					// printf("data: %d %d %d\n\n",i,j,tmp);
					cnt = tmp;
					PQ.pop();
				}
					
			}
			// printf("----------------------------------\n");
		}

		printf("%d %d %d\n",ans_x,ans_y,ans );
		if( times != 0 )
			printf("\n");
	}

	return 0;
}
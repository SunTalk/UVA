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
		sort(&tree[0],&tree[num]);

		ans = ans_x = ans_y = 0;
		for( i = 0 ; i < num ; i++ ){
			for( j = i+1 ; j < num ; j++ ){
				for( k = i+1 ; k < j ; k++ ){
					if( k == k+1 )
						tmp = 0;
					else 
						tmp = tree[k-1].second;
					tmp = min( tree[j].first - tree[i].first , tree[k].second-tmp );
					if( tmp > ans ){
						ans = tmp;
						ans_x = i;
						ans_y = k-1;
					}					
				}
			}
		}

		printf("%d %d %d\n",ans_x,ans_y,ans );

	}

	return 0;
}
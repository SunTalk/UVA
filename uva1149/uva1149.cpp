#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1149"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int case_num;
	scanf("%d",&case_num);

	int num,weight;
	int bag[10005];
	int tmp,ans,i,j;
	bool check;

	for( i = 0 ; i < case_num ; i++ ){

		scanf("%d %d",&num,&weight);
		memset(bag,0,sizeof(bag));	
		
		ans = 0;
		check = 0;

		for( j = 0 ; j < num ; j++ ){
			scanf("%d",&bag[j]);
		}
		
		sort(&bag[0],&bag[num]);

		tmp = 0;
		int left = 0;
		int right = num-1;

		for( j = 0 ; j < num ; j-- ){

			if( bag[left] + bag[right] <= weight )
				left++;
			right--;
			ans++;
			if( right < left )
				break;
		}

		if( i != 0 )
			printf("\n");

		printf("%d\n",ans );

	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1619"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int days,i,j;
	int num[MAXN+5];
	long long sum[MAXN+5],tmp;
	int left[MAXN+5],right[MAXN+5];
	bool check = 0;

	while( ~scanf("%d",&days) ){

		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));

		for( i = 1 ; i <= days ; i++ ){
			scanf("%d",&num[i]);
			sum[i] = num[i] + sum[i-1];
		}

		for( i = 1 ; i <= days ; i++ ){
			tmp = i-1;
			while( num[tmp] >= num[i] && tmp > 0 )
				tmp = left[tmp]-1;
			left[i] = tmp+1;
		}

		for( i = days ; i > 0 ; i-- ){
			tmp = i+1;
			while( num[tmp] >= num[i] && tmp <= days )
				tmp = right[tmp]+1;
			right[i] = tmp-1;
		}
		
		long long ans = -1;
		int ans_l,ans_r;

		for( i = 1 ; i <= days ; i++ ){
			tmp = sum[right[i]] - sum[left[i]-1];
			tmp = tmp*num[i];
			if( tmp > ans ){
				ans = tmp;
				ans_l = left[i];
				ans_r = right[i];
			}

		}

		if( ans == 0 )
			ans_l = ans_r = 1;

		if(check)
			printf("\n");

		printf("%lld\n", ans);
		printf("%d %d\n",ans_l,ans_r );
		check = true;

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "524"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool check[20];
int ans[20];
int num;

bool isPrime(int k){
	for(int j = 2 ; j <= sqrt(k) ; j++ ){
		if( k % j == 0 )
			return false;
	}
	return true;
}

void BK(int k){
	
	if( k == num+1 ){
		if( isPrime(ans[1]+ans[num]) ){
			for(int i = 1 ; i < num ; i++ )
				printf("%d ",ans[i] );
			printf("%d\n",ans[num] );
		}
		return;
	}

	for(int i = 2 ; i <= num ; i++ ){
		if( !check[i] && isPrime(i+ans[k-1]) ){
			ans[k] = i;
			check[i] = true;
			BK(k+1);
			check[i] = false;
		}
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE = 1;
	while( ~scanf("%d",&num) ){
		memset(check,0,sizeof(check));
		ans[1] = 1;
		if( CASE != 1 )
			printf("\n");
		printf("Case %d:\n", CASE);
		CASE++;
		BK(2);
	}

	return 0;
}
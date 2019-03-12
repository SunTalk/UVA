#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11258"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	long long tmp,limit=2147483647;
	string num;
	long long dp[205];

	while( times-- ){
		
		cin >> num;
		memset(dp,0,sizeof(dp));
		for(int i = 1 ; i <= num.size() ; i++ ){
			for(int j = 1 ; j<=10 && j<=i ; j++ ){
				tmp = 0;
				for(int k = 0 ; k < j ; k++ ){
					tmp = tmp*10 + num[i-j+k]-'0';
					if( tmp >= 0 && tmp <= limit )
						dp[i] = max(dp[i],dp[i-j]+tmp);
					else
						break;
				}
			}
		}
		printf("%lld\n",dp[num.size()] );

	}

	return 0;
}
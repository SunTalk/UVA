#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10127"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int tmp,ans;

	while( ~scanf("%d",&num) ){
		
		tmp = ans = 0;
		do{
			tmp = tmp*10 + 1;
			tmp = tmp%num;
			ans++;
		}while( tmp != 0 );

		printf("%d\n",ans);
	
	}

	return 0;
}
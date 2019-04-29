#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10276"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int TIMES;
	scanf("%d",&TIMES);
	int table[55],num;

	while( TIMES-- ){
		
		scanf("%d",&num);
		memset(table,0,sizeof(table));

		int ans = 1;
		while(1){

			int tmp = ans;
			for(int i = 1; i <= num ; i++ ){
				int test = sqrt(table[i] + tmp);
				if( test*test == table[i]+tmp || table[i] == 0 ){
					table[i] = tmp;
					ans++;
					break;
				}
			}

			if( tmp == ans )
				break;

		}

		printf("%d\n",ans-1 );

	}

	return 0;
}
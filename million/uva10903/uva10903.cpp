#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10903"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int n,k;
	double win[105];
	double total[105];
	int one,two;
	string ONE,TWO;
	bool flag = false;

	while( ~scanf("%d %d\n",&n,&k) && n ){

		memset(win,0,sizeof(win));
		memset(total,0,sizeof(total));

		for(int i = 0 ; i < (k*n*(n-1)/2) ; i++ ){
			
			cin >> one >> ONE >> two >> TWO ;

			if( ONE == "rock" ){
				if( TWO == "paper" ){
					win[two]++;
					total[one]++;
					total[two]++;
				}
				if( TWO == "scissors" ){
					win[one]++;
					total[one]++;
					total[two]++;
				}
			}

			if( ONE == "paper" ){
				if( TWO == "scissors" ){
					win[two]++;
					total[one]++;
					total[two]++;
				}
				if( TWO == "rock" ){
					win[one]++;
					total[one]++;
					total[two]++;
				}
			}

			if( ONE == "scissors" ){
				if( TWO == "rock" ){
					win[two]++;
					total[one]++;
					total[two]++;
				}
				if( TWO == "paper" ){
					win[one]++;
					total[one]++;
					total[two]++;
				}
			}

		}

		if( flag )
			printf("\n");
		flag = true;

		for(int i = 1 ; i <= n ; i++ ){
			if( total[i] == 0 )
				printf("-\n");
			else
				printf("%.3lf\n", win[i]/total[i] );
		}

	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11997"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,tmp,i,j,k;
	int Karr[755][2];
	int ans[755];

	while( ~scanf("%d",&number) ){

		memset(Karr,0,sizeof(Karr));
		memset(ans,0,sizeof(ans));

		for( i = 0 ; i < number ; i++ ){
			Karr[i][0] = Karr[i][1] = 200000000;
			for( j = 0 ; j < number ; j++ ){
				scanf("%d",&tmp);
				if( tmp < Karr[i][0] ){
					Karr[i][1] = Karr[i][0];
					Karr[i][0] = tmp;
				}
				else if( tmp < Karr[i][1] )
					Karr[i][1] = tmp;
			}
		}

		for( i = 0 ; i < number ; i++ ){
			ans[0] = ans[0] + Karr[i][0];
		}
		
		for( i = 0 ; i < number ; i++ ){
			for( j = 0 ; j < number ; j++ ){
				if( i == j )
					ans[i+1] = ans[i+1] + Karr[j][1];
				else
					ans[i+1] = ans[i+1] + Karr[j][0];
			}
		}

		for( i = 1 ; i < number+1 ; i++ ){
			j = i-1;
			while( ans[j] > ans[j+1] && j != -1 ){
				swap(ans[j],ans[j+1]);
				j--;
			}
		}

		for( i = 0 ; i < number ; i++ )
			printf("%d ",ans[i] );
		printf("\n");

	}


	return 0;
}
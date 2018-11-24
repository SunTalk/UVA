#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1513"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 100000
#define lowbit(x) ( (x) & (-x) )

int total[2*MAX+5];
int pos[MAX+5];

void Add( int k, int num ){

	while( k < MAX*2 ){

		total[k] = total[k] + num;
		k = k + lowbit(k);

	}

}

int Sum( int k ){

	int ans = 0;
	
	while( k > 0 ){
		ans = ans + total[k];
		k = k - lowbit(k);
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);

	int movie,move;
	int tmp,i,j;

	while( times-- ){

		memset(total,0,sizeof(total));
		memset(pos,0,sizeof(pos));

		scanf("%d %d",&movie,&move);

		for( i = 1 ; i <= movie ; i++ ){
			pos[i] = movie - i + 1;
			Add(pos[i],1);
		}

		j = movie;
		for( i = 1 ; i <= move ; i++ ){

			scanf("%d",&tmp);
			printf("%d", movie - Sum(pos[tmp]) );
			if( i == move )
				printf("\n");
			else
				printf(" ");
			
			Add(pos[tmp],-1);
			pos[tmp] = ++j;
			Add(pos[tmp],1);

		}

	}

	return 0;
}
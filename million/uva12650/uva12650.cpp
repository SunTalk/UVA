#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12650"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int table[10005];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int N,R;
	int tmp;

	while( ~scanf("%d %d",&N,&R) ){

		memset(table,0,sizeof(table));
		for(int i = 0 ; i < R ; i++ ){
			scanf("%d",&tmp);
			table[tmp] = 1;
		}

		if( N == R ){
			printf("*\n");
			continue;
		}

		for(int i = 1 ; i <= N ; i++ )
			if( table[i] == 0 )
				printf("%d ",i );
		printf("\n");

	}

	return 0;
}
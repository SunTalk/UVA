#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

int table[MAXN+5];

int main(int argc, char const *argv[])
{
	int num,need;
	while( ~scanf("%d",&num) ){

		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);
		scanf("%d",&need);

		sort(table,table+num);
		int check = need;
		int A,B;
		for(int i = 0 ; i < num ; i++ ){
			for(int j = i+1 ; j < num ; j++ ){
				if( table[i]+table[j] == need ){
					if( table[j]-table[i] < check ){
						check = table[j]-table[i];
						A = table[i];
						B = table[j];
					}
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n",A ,B );

	}

	return 0;
}
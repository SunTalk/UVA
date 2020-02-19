#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int main(int argc, char const *argv[])
{

	int table[MAXN+10];
	int num;
	while( ~scanf("%d",&num) && num ){

		for(int i = 0; i < num ; i++ )
			scanf("%d",&table[i]);

		bool flag = false;
		for(int i = 0 ; i< num ; i++ ){
			if( table[i] ){
				if( flag ) printf(" ");
				printf("%d", table[i]);
				flag = true;
			}
		}
		if( !flag ) printf("0");
		printf("\n");

	}

	return 0;
}
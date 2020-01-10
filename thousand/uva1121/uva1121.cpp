#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	int num,target;

	while( ~scanf("%d %d",&num,&target) ){
		
		for(int i = 0; i < num ; i++ )
			scanf("%d",&table[i]);

		int total = 0, bottom = 0, small = INT_MAX;
		for(int i = 0; i < num ; i++ ){
			total += table[i];
			while( total >= target ){
				small = min(i-bottom+1,small);
				total -= table[bottom++];
			}
		}

		printf("%d\n", small==INT_MAX ? 0 : small);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	memset(table, 0, sizeof(table));
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		table[i] = 4*i+2;
		for(int j = 1 ; j <= i ; j++ ){
			if( i%j == 0 ){
				for(int k = 1 ; k <= j ; k++ ){
					if( i/j%k == 0 ){
						table[i] = min(table[i],2*(i/j+i/k+j*k));
					}
				}
			}
		}
	}

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
		scanf("%d",&num);
		printf("%d\n",table[num]);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool isPrime[MAXN+10];

void build(){
	isPrime[0] = isPrime[1] = false;
	for(int i = 2 ; i < MAXN+5 ; i++ )
		isPrime[i] = true;

	for(int i = 2 ; i < MAXN+5 ; i++ )
		if( isPrime[i] )
			for(int j = i+i ; j < MAXN+5 ; j+=i )
				isPrime[j] = false;

}

int main(int argc, char const *argv[])
{

	build();

	int num;
	while( ~scanf("%d",&num) ){
		if( num < 8 ) printf("Impossible.\n");
		else{

			if( num&1 ){
				printf("2 3 ");
				num -= 5;
			}
			else{
				printf("2 2 ");
				num -= 4;
			}
			for(int i = 2 ; i <= num ; i++ ){
				if( isPrime[i] && isPrime[num-i] ){
					printf("%d %d\n",i,num-i);
					break;
				}
			}
		}
	}

	return 0;
}
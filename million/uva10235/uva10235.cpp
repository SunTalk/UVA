#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000
#define DEVIATION 0.00000005

bool prime[MAXN+10];
void init(){
	for(int i = 0 ; i < MAXN+5 ; i++ )
		prime[i] = true;
	prime[0] = prime[1] = false;
	for(int i = 2 ; i < MAXN+5 ; i++ ){
		if( prime[i] ){
			for(int j = i+i ; j < MAXN+5 ; j+=i ){
				prime[j] = false;
			}
		}
	}
}

int rev(int k){
	int r = 0;
	while( k > 0 ){
		r *= 10;
		r += k%10;
		k /= 10;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	
	init();
	int num;
	while( ~scanf("%d",&num) ){

		int R = rev(num);
		if( !prime[num] )
			printf( "%d is not prime.\n", num );
		else if( R != num && prime[R] )
			printf( "%d is emirp.\n", num );
		else
			printf( "%d is prime.\n", num );

	}

	return 0;
}
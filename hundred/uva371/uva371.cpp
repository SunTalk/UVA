#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

long long len(long long k){
	long long cnt = 0;
	do {
		if( k&1 ) k = k*3+1;
		else k = k/2;
		cnt++;
	}while( k > 1 );
	return cnt;
}

int main(int argc, char const *argv[])
{

	long long L,H,V,S,tmp;

	while( cin >> L >> H && L){

		if( L > H )
			swap(L,H);

		S = 0;
		for(long long i = L ; i <= H ; i++ ){
			tmp = len(i);
			if( tmp > S ){
				S = tmp;
				V = i;
			}
		}

		printf("Between %lld and %lld",L,H);
		printf(", %lld generates the longest sequence of %lld values.\n",V,S);

	}

	return 0;
}
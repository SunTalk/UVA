#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int num;
	int table[10];
	long long a,b;
	while( ~scanf("%d",&num) ){

		memset(table, 0, sizeof(table));
		while( num ){
			table[num%10]++;
			num /= 10;
		}

		a = b = 0;
		for(int i = 9 ; i >= 0 ; i-- ){
			for(int j = 0 ; j < table[i] ; j++ ){
				a *= 10;
				a += i;
			}
		}
		if( table[0] ){
			for(int i = 1 ; i < 10 ; i++ ){
				if( table[i] ){
					b = i;
					table[i]--;
					break;
				}
			}
		}
		for(int i = 0 ; i < 10 ; i++ ){
			for(int j = 0 ; j < table[i] ; j++ ){
				b *= 10;
				b += i;
			}
		}
		
		printf("%lld - %lld = %lld = 9 * %lld\n",a,b,a-b,(a-b)/9);

	}


	return 0;
}
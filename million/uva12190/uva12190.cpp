#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int Price(int cwh){
	int price = 0;
	price += min(max(0, cwh*2), 2*100);
	cwh -= 100;
	price += min(max(0, cwh*3), 3*(10000-100));
	cwh -= (10000-100);
	price += min(max(0, cwh*5), 5*(1000000-10000));
	cwh -= (1000000-10000);
	price += max(0, cwh*7);
	return price;
}

int Cwh(int price){
	int cwh = 0;
	cwh += min(max(0, price/2), 100);
	price -= 2*100;
	cwh += min(max(0, price/3), (10000-100));
	price -= 3*(10000-100);
	cwh += min(max(0, price/5), (1000000-10000));
	price -= 5*(1000000-10000);
	cwh += max(0, price/7);
	return cwh;
}

int main(int argc, char const *argv[])
{
	int A,B;
	while( ~scanf("%d %d", &A, &B) && (A|B) ){
		int total = Cwh(A);
		int L = 0, R = total;
		int ans = 0;
		while( L < R ){
			
			int M = (L+R)/2;
			int diff = Price(total-M)-Price(M);

			if( diff == B ){
				ans = M;
				break;
			}

			if( diff < B )
				R = M;
			else
				L = M;

		}
		printf("%d\n", Price(ans));
	}

	return 0;
}
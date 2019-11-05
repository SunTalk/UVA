#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000
#define DEVIATION 0.00000005

bool is_prime(int k){
	for(int i = 2 ; i <= sqrt(k) ; i++ )
		if( k%i == 0 )
			return false;
	return true;
}	

int table[MAXN+10];

int main(int argc, char const *argv[])
{

	memset(table, 0, sizeof(table));
	table[0] = 1;
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		if( is_prime((i*i+i+41)) )
			table[i]++;
		table[i] += table[i-1];
	}

	int a,b;
	while( ~scanf("%d %d",&a,&b) ){

		int A = table[b]-(a==0?0:table[a-1]);
		double ans = double(A)/double(b-a+1)*100;
		printf("%.2lf\n",ans+DEVIATION);

	}

	return 0;
}
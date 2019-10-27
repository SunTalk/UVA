#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

double Stirling(int n){
	return (0.5*log(2.0*acos(-1.0)*n)+n*log(n+0.0)-n)/log(10.0);
}

int main(int argc, char const *argv[])
{
	int n,k;
	while( ~scanf("%d %d",&n,&k) )
		printf("%u\n",(unsigned int)(Stirling(n)-Stirling(k)-Stirling(n-k))+1);

	return 0;
}
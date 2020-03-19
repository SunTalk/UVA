#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL H(int num){

	long long ans = 0;
	int tmp = (int)sqrt(num+0.0);

	for(int i = 1 ; i <= tmp ; i++ )
		ans += i*(num/i-num/(i+1));
	
	for(int i = num/(tmp+1) ; i >= 1 ; i-- )
		ans += num/i;

	return ans;

}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
		scanf("%d",&num);
		printf("%lld\n",H(num));
	}

	return 0;
}
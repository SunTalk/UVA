#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

bool isSelf[MAXN+100];

int gen(int k){
	int ans  = k;
	while( k > 0 ){
		ans += k%10;
		k /= 10;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	memset(isSelf, 0, sizeof(isSelf));
	for(int i = 1 ; i <= MAXN ; i++ ){
		isSelf[gen(i)] = true;
		if( !isSelf[i] )
			printf("%d\n", i);
	}

	return 0;
}
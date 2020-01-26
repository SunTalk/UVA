#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int num;
	while( ~scanf("%d",&num) && num ){
		int ans = 0;
		while( num >= 3 ){
			ans += num/3;
			num = num%3 + num/3;
		}
		if( num == 2 ) ans++;
		printf("%d\n",ans);
	}

	return 0;
}
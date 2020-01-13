#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int n,k,m;
	while( ~scanf("%d %d %d",&n,&k,&m) && n ){

		int ans = 0;
		for(int i = 2 ; i < n ; i++ )
			ans = (ans+k)%i;
		ans = (ans+m)%n;
		cout << ans+1 << endl;

	}

	return 0;
}
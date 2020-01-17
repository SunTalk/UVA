#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	int num,tmp;
	while( ~scanf("%d",&num) ){
		int ans = 0;
		for(int i = 0 ; i < 5 ; i++ ){
			scanf("%d",&tmp);
			if( tmp == num )
				ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}
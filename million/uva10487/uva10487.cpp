#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN+10];
int ans[MAXN*MAXN];

int main(int argc, char const *argv[])
{

	int num;
	int kase = 1;
	
	while( ~scanf("%d",&num) && num ){

		printf("Case %d:\n",kase++);

		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		int s = 0;
		memset(ans,0,sizeof(ans));
		for(int i = 0 ; i < num ; i++ )
			for(int j = i+1 ; j < num ; j++ )
				ans[s++] = table[i]+table[j];
		sort(ans,ans+s);

		int f;
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&f);
			int j = lower_bound(ans,ans+s,f)-ans;
			int ANS;
			if( j == s ) ANS = ans[s-1];
			else if( j == 0 ) ANS = ans[0];
			else ANS = (ans[j]-f<f-ans[j-1])?ans[j]:ans[j-1];
			printf("Closest sum to %d is %d.\n",f,ANS);
		}

	}

	return 0;
}
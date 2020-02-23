#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
int table[MAXN+10];

void build(){
	table[0] = 0;
	for(int i = 1 ; i < MAXN+5 ; i++ )
		table[i] = table[i-1]+i;
}

int main(int argc, char const *argv[])
{

	build();

	int kase;
	scanf("%d",&kase);

	int num,ans;
	while( kase-- ){

		scanf("%d",&num);
		num = abs(num);

		int s = lower_bound(&table[0],&table[MAXN+5],num)-&table[0];
		if( s == 0 ) s = 1;
		for(int i = s ; i < MAXN+5 ; i++ ){
			if( num <= table[i] && !((table[i]-num)&1) ){
				ans = i;
				break;
			}
		}

		printf("%d\n",ans);
		if(kase) printf("\n");

	}

	return 0;
}
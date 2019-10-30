#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 200000

#define LowerBit(k) (k&-k)

int table[MAXN+5];
int FT[MAXN+5];

int total(int k){
	int ans = 0;
	for(int i = k ; i > 0 ; i-=LowerBit(i) )
		ans += FT[i];
	return ans;
}

int main(int argc, char const *argv[])
{

	int num,a,b;
	int kase = 1;
	string action;

	while( ~scanf("%d",&num) && num ){

		if( kase > 1 )
			printf("\n");
		printf("Case %d:\n",kase++);

		for(int i = 1 ; i <= num ; i++ )
			scanf("%d",&table[i]);

		memset(FT,0,sizeof(FT));
		for(int i = 1 ; i <= num ; i++ )
			for(int j = i ; j <= num ; j+=LowerBit(j) )
				FT[j] += table[i];

		while( cin >> action && action != "END" ){
			scanf("%d %d",&a,&b);
			if( action == "M" ){
				printf("%d\n",total(b)-total(a-1));
			}
			else{
				for(int i = a ; i <= num ; i+=LowerBit(i) )
					FT[i] += (b-table[a]);
				table[a] = b;
			}
		}

	}

	return 0;
}
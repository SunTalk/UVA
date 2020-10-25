#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100005
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

struct BITree{
	
	long long tree[MAXN+10];

	void init(){
		memset(tree,0,sizeof(tree));
	}

	int lowbit(int k){
		return k&(-k);
	}

	void add(int k, int num){
		while( k < MAXN ){
			tree[k] += num;
			k += lowbit(k);
		}
	}

	long long sum(int k){
		int res = 0;
		while( k > 0 ){
			res += tree[k];
			k -= lowbit(k);
		}
		return res;
	}

}BIT;

long long table[MAXN+10];
long long L[MAXN+10];
long long R[MAXN+10];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	while( kase-- ){
		
		int num;
		scanf("%d",&num);

		BIT.init();
		memset(table,0,sizeof(table));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));

		for(int i = 0 ; i < num ; i++ ){
			scanf("%lld",&table[i]);
			L[i] = BIT.sum(table[i]);
			BIT.add(table[i],1);
		}
		BIT.init();
		for(int i = num-1 ; i >= 0 ; i-- ){
			R[i] = BIT.sum(table[i]);
			BIT.add(table[i],1);
		}

		long long ans = 0;
		for(int i = 0 ; i < num ; i++ )
			ans += L[i]*(num-1-i-R[i]) + (i-L[i])*R[i];

		printf("%lld\n",ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

struct disjoint {
	int p[MAXN+10];

	void init(){
		memset(p,-1,sizeof(p));
	}
	int find(int k){
		return p[k]<0 ? k : (p[k]=find(p[k]));
	}
	void uni(int a, int b){
		a = find(a), b = find(b);
		p[a] += p[b];
		p[b] = a;
	}
	bool isGroup(int a, int b){
		return find(a) == find(b);
	}
	int siz(int k){
		return ( -p[find(k)] );
	}
}D;

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int N,M,a,b;
	while( kase-- ){
		
		scanf("%d %d",&N,&M);
		D.init();
		int ans = 1;
		for(int i = 0 ; i < M ; i++ ){
			scanf("%d %d",&a,&b);
			if( !D.isGroup(a,b) )
				D.uni(a,b);
			ans = max(ans,D.siz(a));
		}
		printf("%d\n",ans);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 2000000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[MAXN],tmp[MAXN];
LL ans;

void merge(int l, int m, int r){
	
	int idxL = l,idxR = m+1;
	int idx = 0, cnt = 0;

	while( idxL <= m && idxR <= r ){
		if( table[idxL] <= table[idxR] ){
			tmp[idx++] = table[idxL++];
			ans += cnt;
		}
		else{
			tmp[idx++] = table[idxR++];
			cnt++;
		}
	}

	while( idxL <= m ){
		tmp[idx++] = table[idxL++];
		ans += cnt;
	}
	while( idxR <= r ){
		tmp[idx++] = table[idxR++];
	}

	for(int i = 0 ; i < idx ; i++ )
		table[l+i] = tmp[i];

}

void mergesort(int l, int r){

	if( l >= r ) return;
	int m = (l+r)>>1;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,r);

}

int main(int argc, char const *argv[])
{

	int num;
	while( ~scanf("%d",&num) && num ){
		
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);
		ans = 0;
		mergesort(0,num-1);
		printf("%lld\n",ans);

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10810"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 500000
int table[MAXN+5];
int tmp[MAXN+5];
long long ans;

void merge_sort(int l,int r){
	if( l == r )
		return;
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);

	int L = l;
	int R = mid+1;
	for(int i = l ; i <= r ; i++ ){
		if( table[L] < table[R] && L != mid+1 ){
			tmp[i] = table[L++];
		}
		else if( R != r+1 ){
			tmp[i] = table[R++];
			if( L != mid+1 )
				ans += mid+1-L;
		}
		else{
			tmp[i] = table[L++];
		}
	}
	for(int i = l ; i <= r ; i++ )
		table[i] = tmp[i];

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	while( ~scanf("%d",&num) && num ){
		for(int i = 0 ; i < num ; i++ )
			scanf("%d",&table[i]);

		ans = 0;
		merge_sort(0,num-1);
		printf("%lld\n",ans );

	}

	return 0;
}
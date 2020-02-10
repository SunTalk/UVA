#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool ans;
int num[5];

void DFS(int k,int now){

	if( ans ) return;
	if( k == 5 ){
		if( now == 23 )
			ans = true;
		return;
	}

	DFS(k+1,now+num[k]);
	DFS(k+1,now-num[k]);
	DFS(k+1,now*num[k]);

}

int main(int argc, char const *argv[])
{

	while( scanf("%d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4]) && (num[0]|num[1]|num[2]|num[3]|num[4]) ){

		ans = false;
		sort(num,num+5);
		do{
			DFS(1,num[0]);
		}while( next_permutation(num,num+5) );
		
		if( ans ) printf("Possible\n");
		else printf("Impossible\n");

	}

	return 0;
}
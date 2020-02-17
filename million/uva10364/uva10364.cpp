#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int table[MAXN],num;
bool is_visit[MAXN];
bool ans;

void dfs(int complete, int sum, int start, int len){

	if( ans ) return;

	if( complete == 3 ){
		ans = true;
		return;
	}

	if( sum == len )
		dfs(complete+1,0,0,len);

	for(int i = start ; i < num ; i++ ){
		if( !is_visit[i] && sum+table[i] <= len ){
			is_visit[i] = true;
			dfs(complete,sum+table[i],i+1,len);
			is_visit[i] = false;
		}
	}

}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	
	while ( kase-- ){

		scanf("%d",&num);
		int sum = 0;
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&table[i]);
			sum += table[i];
		}
		sort(table,table+num,greater<int>());

		if( sum%4 != 0 || table[num-1] > sum/4 ){
			printf("no\n");
			continue;
		}

		ans = false;
		memset(is_visit,0,sizeof(is_visit));

		dfs(0,0,0,sum/4);

		if( ans ) printf("yes\n");
		else printf("no\n");

	}

	return 0;
}
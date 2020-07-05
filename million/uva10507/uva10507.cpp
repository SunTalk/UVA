#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 30
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
vector <int> edge[MAXN];
int isvis[MAXN];


int main(int argc, char const *argv[])
{

	int N,M;
	string str;
	queue <int> Q;
	while( ~scanf("%d",&N) ){

		while( !Q.empty() )
			Q.pop();
		for(int i = 0 ; i < MAXN ; i++ )
			edge[i].clear();
		memset(isvis,0,sizeof(isvis));

		scanf("%d",&M);
		cin >> str;
		for(int i = 0 ; i < str.size() ; i++ ){
			Q.push(str[i]-'A');
			isvis[str[i]-'A'] = -1;
		}

		for(int i = 0 ; i < M ; i++ ){
			cin >> str;
			edge[str[0] - 'A'].push_back(str[1] - 'A');
			edge[str[1] - 'A'].push_back(str[0] - 'A');
		}
		
		int cnt = 3;
		int ans = 0;
		while( cnt != N && !Q.empty() ){

			while( !Q.empty() ){
				int k = Q.front(); 
				Q.pop();
				for(auto i : edge[k] )
					if( isvis[i] >= 0 ) 
						isvis[i]++;
			}

			for(int i = 0 ; i < MAXN ; i++ ){
				if( isvis[i] >= 3 ){
					Q.push(i);
					isvis[i] = -1;
					cnt++;
				}
			}
			ans++;

		}

		if( cnt != N )
			printf("THIS BRAIN NEVER WAKES UP\n");
		else
			printf("WAKE UP IN, %d, YEARS\n",ans);
		
	}

	return 0;
}
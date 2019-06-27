#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11374"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 500

struct PATH{
	int to,len;
	bool operator<( const PATH &rhs ) const{
		return len < rhs.len;
	}
};

vector <PATH> EC[MAXN+5];
vector <PATH> CO[MAXN+5];
priority_queue <PATH> PQ;

int S[MAXN+5];
int E[MAXN+5];
bool is_visit[MAXN+5];

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int city,start,end,economy,commercial;
	int a,b,len;
	PATH tmp;


	while( ~scanf("%d %d %d",&city,&start,&end) ){

		memset(S,63,sizeof(S));//0x3f3f3f3f
		memset(E,63,sizeof(E));

		scanf("%d",&economy);
		for(int i = 0 ; i < economy ; i++ ){
			scanf("%d %d %d",&a,&b,&len);
			EC[a].push_back({b,len});
			EC[b].push_back({a,len});
		}
		scanf("%d",&commercial);
		for(int i = 0 ; i < commercial ; i++ ){
			scanf("%d %d %d",&a,&b,&len);
			CO[a].push_back({b,len});
			CO[b].push_back({a,len});
		}

		memset(is_visit,0,sizeof(is_visit));
		is_visit[start] = true;
		while( !PQ.empty() )
			PQ.pop();

		for(int i : EC[start])

		while( !PQ.empty() ){
			
			tmp = PQ.top();
			PQ.pop();

			if( is_visit[tmp.to] )
				continue;
			is_visit[tmp.to] = true;
			for(int i = 0 ; i < EC[tmp.tp].size() ; i++ )
				PQ.push(EC[tmp.to][i]);



		}


	}

	return 0;
}
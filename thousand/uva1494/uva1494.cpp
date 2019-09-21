#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1494"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000

struct disjoin{

	int group[MAXN+5];
	void init(){
		for(int i = 0 ; i < MAXN+5 ; i++ )
			group[i] = i;
	}

	int find(int k){
		return group[k]==k ? k:(group[k]=find(group[k]));
	}

	void uni(int a,int b){
		group[find(a)] = group[find(b)];
	}

	bool is_group(int a, int b){
		if( find(a) == find(b) )
			return true;
		return false;
	}

};

struct city {
	double x,y;
	int id,people;
}C[MAXN+5];
struct edge {
	int a,b;
	double len;

	bool operator < (const edge &rhs){
		return len < rhs.len;
	}

}E[MAXN*MAXN+5];
vector<edge> MST;

vector <edge> connected[MAXN+5];
double max_dis[MAXN+5][MAXN+5];
bool vis[MAXN+5];

void dfs(int a,int f,double d, double* vec){

	vec[a] = d;

	for(int i = 0 ; i < connected[a].size() ; i++ ){
		int k = connected[a][i].a;
		if( k == a )
			k = connected[a][i].b;
		double td = connected[a][i].len;
		if( k == f )
			continue;
		dfs(k,a,max(d,td),vec);
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int kase;
	scanf("%d",&kase);

	int num;
	disjoin D;
	
	while( kase-- ){
		
		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			C[i].id = i;
			scanf("%lf %lf %d",&C[i].x,&C[i].y,&C[i].people);
		}

		int k = 0;
		for(int i = 0 ; i < num ; i++ ){
			for(int j = i+1 ; j < num ; j++ ){
				E[k].a = C[i].id;
				E[k].b = C[j].id;
				E[k++].len = sqrt((C[i].x-C[j].x)*(C[i].x-C[j].x)+(C[i].y-C[j].y)*(C[i].y-C[j].y));
			}
		}

		sort(&E[0],&E[k]);
		D.init();
		MST.clear();
		for(int i = 0 ; i < k ; i++ ){
			int a = E[i].a, b = E[i].b;
			if( !D.is_group(a,b) ){
				MST.push_back(E[i]);
				D.uni(a,b);
			}
		}

		// printf("-----------------\n");
		// printf("%d\n",MST.size());
		// for(int i = 0; i < MST.size(); i++){
		// 	printf("%d %d %lf\n",MST[i].a,MST[i].b,MST[i].len);
		// }
		// printf("-----------------\n");

		for(int i = 0 ; i < num ; i++)
			connected[i].clear();
		double mst_len = 0;
		for(int i = 0; i < MST.size(); i++){
			connected[MST[i].a].push_back(MST[i]);
			connected[MST[i].b].push_back(MST[i]);
			mst_len += MST[i].len;
		}

		double A,B,ans=0;
		for(int i = 0 ; i < num ; i++)
			dfs(i,-1,0,max_dis[i]);
		for(int i = 0 ; i < num ; i++ ){
			for(int j = i+1 ; j < num ; j++ ){
				memset(vis,0,sizeof(vis));
				A = double(C[i].people+C[j].people);
				B =  mst_len-max_dis[i][j];
				if( A/B > ans )
					ans = A/B;
			}
		}
		printf("%.2lf\n",ans);

	}

	return 0;
}
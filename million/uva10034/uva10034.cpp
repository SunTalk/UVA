#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

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

}D;

struct point {
	double x,y;
}P[MAXN+5];

double get_len(int a, int b){
	return sqrt((P[a].x - P[b].x)*(P[a].x - P[b].x)+(P[a].y - P[b].y)*(P[a].y - P[b].y));
}

struct edge {
	int a,b;
	double len;

	bool operator < (const edge &rhs){
		return len < rhs.len;
	}

}E[MAXN*MAXN+5];

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	int num;

	while( kase-- ){

		scanf("%d",&num);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%lf %lf",&P[i].x,&P[i].y);
		}

		int k = 0;
		for(int i = 0 ; i < num ; i++ ){
			for(int j = i+1 ; j < num ; j++ ){
				E[k].a = i;
				E[k].b = j;
				E[k++].len = get_len(i,j);
			}
		}

		double ans = 0;
		sort(E,E+k);
		D.init();
		for(int i = 0 ; i < k ; i++ ){
			int a = E[i].a, b = E[i].b;
			if( !D.is_group(a,b) ){
				D.uni(a,b);
				ans += E[i].len;
			}
		}

		printf("%.2lf\n",ans);
		if(kase)
			printf("\n");

	}

	return 0;
}
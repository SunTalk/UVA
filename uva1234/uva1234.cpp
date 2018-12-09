#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1234"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 10000

struct edge{
	int one,two,weight;

	bool operator < (const edge &r ) const{
		return weight > r.weight;
	}

};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	int point,num;
	int set[MAXN+5],i;
	vector <edge> graph;
	edge tmp;
	int point_A,point_B;

	while( times-- ){
		scanf("%d %d",&point,&num);

		for( i = 0 ; i <= point ; i++ )
			set[i] = i;
		for( i = 0 ; i < num ; i++ ){
			scanf("%d %d %d", &tmp.one, &tmp.two, &tmp.weight );
			graph.push_back(tmp);
		}
		sort(&graph[0],&graph[num]);

		int ans = 0;
		for( i = 0 ; i < num ; i++ ){
			point_A = graph[i].one;
			point_B = graph[i].two;

			while( set[point_A] != point_A )
				point_A = set[point_A];

			while( set[point_B] != point_B )
				point_B = set[point_B];

			if( point_A == point_B )
				ans = ans + graph[i].weight;
			else
				set[point_B] = point_A;
		}

		printf("%d\n",ans );
		graph.clear();
	}

	return 0;
}
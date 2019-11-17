#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 20000
#define DEVIATION 0.00000005

double table[MAXN][5];
int score[MAXN][10];

void SET(int k){
	int A = round(table[k][0]*100.0);
	int B = round(table[k][1]*100.0);
	int C = round(table[k][2]*100.0);
	score[k][0] = 0;
	score[k][1] = A;
	score[k][2] = B;
	score[k][3] = C;
	score[k][4] = A+B;
	score[k][5] = A+C;
	score[k][6] = B+C;
	score[k][7] = A+B+C;
	sort(score[k],score[k]+8);
}

int main(int argc, char const *argv[])
{

	int num;
	int total,now,pre;

	int kase = 1;
	while( ~scanf("%d",&num) && num ){

		memset(table,0,sizeof(table));
		for(int i = 1 ; i <= num ; i++ ){
			scanf("%lf %lf %lf",&table[i][0],&table[i][1],&table[i][2]);
			SET(i);
		}

		scanf("%d",&now);
		total = score[now][7];
		pre = now;

		for(int i = 1 ; i < num ; i++ ){
			scanf("%d",&now);
			bool flag = true;
			for(int j = 7 ; j >= 0 ; j-- ){
				if( score[now][j] == total && now > pre ){
					flag = false;
					break;
				}
				if( score[now][j] < total ){
					total = score[now][j];
					flag = false;
					break;
				}
			}
			pre = now;
			if( flag ) total = -1;
		}

		printf("Case %d: ",kase++);
		if( total == -1 )
			printf("No solution\n");
		else
			printf("%.2lf\n",total/100.0);

	}

	return 0;
}
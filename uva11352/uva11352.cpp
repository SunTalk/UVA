#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11352"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int Map[105][105];
queue <int> I;
queue <int> J;
int size;
// int End;

void attack(int i,int j){
	if( Map[i-2][j-1] == 0 )
		Map[i-2][j-1] = 3;
	if( Map[i-2][j+1] == 0 )
		Map[i-2][j+1] = 3;
	if( Map[i-1][j-2] == 0 )
		Map[i-1][j-2] = 3;
	if( Map[i-1][j+2] == 0 )
		Map[i-1][j+2] = 3;
	if( Map[i+1][j-2] == 0 )
		Map[i+1][j-2] = 3;
	if( Map[i+1][j+2] == 0 )
		Map[i+1][j+2] = 3;
	if( Map[i+2][j-1] == 0 )
		Map[i+2][j-1] = 3;
	if( Map[i+2][j+1] == 0 )
		Map[i+2][j+1] = 3;
}

void BFS(int i,int j,int lengh){

	// printf("%d %d %d\n",i,j,lengh );
	if( Map[i-1][j-1] == 0 ){
		I.push(i-1);
		J.push(j-1);
		Map[i-1][j-1] = lengh;
	}
	if( Map[i-1][j] == 0 ){
		I.push(i-1);
		J.push(j);
		Map[i-1][j] = lengh;
	}
	if( Map[i-1][j+1] == 0 ){
		I.push(i-1);
		J.push(j+1);
		Map[i-1][j+1] = lengh;
	}
	if( Map[i][j-1] == 0 ){
		I.push(i);
		J.push(j-1);
		Map[i][j-1] = lengh;
	}
	if( Map[i][j+1] == 0 ){
		I.push(i);
		J.push(j+1);
		Map[i][j+1] = lengh;
	}
	if( Map[i+1][j-1] == 0 ){
		I.push(i+1);
		J.push(j-1);
		Map[i+1][j-1] = lengh;
	}
	if( Map[i+1][j] == 0 ){
		I.push(i+1);
		J.push(j);
		Map[i+1][j] = lengh;
	}
	if( Map[i+1][j+1] == 0 ){
		I.push(i+1);
		J.push(j+1);
		Map[i+1][j+1] = lengh;
	}

	if( size == 0 ){
		size = I.size();
		for(int k = 0 ; k < size ; k++ ){
			int tmp_i = I.front();
			I.pop();
			int tmp_j = J.front();
			J.pop();
			if( k == size-1 )
				size = 0;
			BFS(tmp_i,tmp_j,lengh+1);
		}
	}
		
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,i;
	scanf("%d",&times);
	int line,column,j,k;
	int king_i,king_j;
	int ans_i,ans_j;
	int ans;
	char chess;

	for( i = 0 ; i < times ; i++ ){

		scanf("%d %d",&line,&column);
		getchar();

		memset(Map,-1,sizeof(Map));

		for( j = 2 ; j <= line+1 ; j++ ){
			for( k = 2 ; k <= column+1 ; k++ ){
				scanf("%c",&chess);
				if( chess == '.' )
					Map[j][k] = 0;
				if( chess == 'A' ){
					Map[j][k] = 10;
					king_i = j;
					king_j = k;
				}
				if( chess == 'B' ){
					Map[j][k] = 20;
					ans_i = j;
					ans_j = k;
				}
				if( chess == 'Z' )
					Map[j][k] = -1;
			}
			getchar();
		}

		size = 0;

		for( j = 2 ; j <= line+1 ; j++ ){
			for( k = 2 ; k <= column+1 ; k++ ){
				if( Map[j][k] == -1 )
					attack(j,k);
			}
		}

		for( j = 2 ; j <= line+1 ; j++ ){
			for( k = 2 ; k <= column+1 ; k++ ){
				if( Map[j][k] == 3 )
					Map[j][k] = -1;
			}
		}
		
		Map[ans_i][ans_j] = 0;
		BFS(king_i,king_j,1);
		
		ans = Map[ans_i][ans_j];


		if( ans == 0 )
			printf("King Peter, you can't go now!\n");
		else
			printf("Minimal possible length of a trip is %d\n",ans );

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
int table[100][10];
int tmp[10];
int cnt = 0;
bool row[10],Left[20],Right[20];

void Queen(int k){
	if( k == 8 ){
		for(int i = 0 ; i < 8 ; i++ )
			table[cnt][i] = tmp[i];
		cnt++;
		return;
	}
	for(int i = 0 ; i < 8 ; i++ ){
		int R = k+i, L = k-i+7;
		if( !row[i] && !Left[L] && !Right[R] ){
			row[i] = Left[L] = Right[R] = true;
			tmp[k] = i;
			Queen(k+1);
			row[i] = Left[L] = Right[R] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	memset(table, 0, sizeof(table));
	memset(row, 0, sizeof(row));
	memset(Left, 0, sizeof(Left));
	memset(Right, 0, sizeof(Right));
	Queen(0);

	int kase;
	scanf("%d",&kase);
	int x,y;

	while( kase-- ){

		scanf("%d %d",&x,&y);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		cnt = 1;
		for(int i = 0 ; i < 92 ; i++ ){
			if( table[i][y-1]+1 == x ){
				printf("%2d     ",cnt++);
				for(int j = 0 ; j < 8 ; j++ )
					printf(" %d",table[i][j]+1);
				printf("\n");
			}
		}

		if( kase )
			printf("\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
string table[MAXN];
int way[8][2] = {
	{-1,-1}, {-1, 0},{-1, 1},
	{ 1,-1}, { 1, 0},{ 1, 1},
	{ 0,-1}, { 0, 1}
};
int col,row;
int Acol,Arow;
string str;

bool find(int x, int y){

	for(int i = 0 ; i < 8 ; i++ ){
		int k = 0;
		int nx = x,ny = y;
		for(int j = 0 ; j < str.size() ; j++ ){
			
			if( str[j] == table[nx][ny] )
				k++;
			nx+=way[i][0];
			ny+=way[i][1];
			if( nx < 0 || nx >= col ) break;
			if( ny < 0 || ny >= row ) break;
		}

		if( k == str.size() )
			return true;

	}
	return false;

}


int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d", &kase);

	int num;
	
	while( kase-- ){

		scanf("%d %d", &col, &row);
		for(int i = 0 ; i < col ; i++ ){
			cin >> table[i];
			transform(table[i].begin(), table[i].end(), table[i].begin(),::tolower);
		}

		scanf("%d", &num);
		for(int i = 0 ; i < num ; i++ ){
			cin >> str;
			transform(str.begin(), str.end(), str.begin(),::tolower);
			bool check = false;
			for(int i = 0 ; i < col ; i++ ){
				for(int j = 0 ; j < row ; j++ ){
					if( check ) break;
					if( find(i,j) ){
						Acol = i+1;
						Arow = j+1;
						check = true;
						break;
					}
				}
			}
			printf("%d %d\n",Acol,Arow);
		}
		if( kase ) printf("\n");

	}

	return 0;
}
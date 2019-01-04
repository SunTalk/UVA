#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "167"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector <int> table[8];
int column[8],Left[15],Right[15];
int tmp[8];

void Queen(int k){

	if( k == 8 ){
		for(int j = 0 ; j < 8 ; j++){
			table[j].push_back(tmp[j]);
		}
		return;
	}

	for(int i = 0 ; i < 8 ; i++ ){
		int l = k+i;
		int r = k-i+7;
		if( column[i] == 0 && Left[l] == 0 && Right[r] == 0 ){
			column[i] = 1 , Left[l] = 1 , Right[r] = 1;
			tmp[k] = i;
			Queen(k+1);
			column[i] = 0 , Left[l] = 0 , Right[r] = 0;
		}
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	memset(column,0,sizeof(column));
	memset(Left,0,sizeof(Left));
	memset(Right,0,sizeof(Right));

	Queen(0);
	
	int test[8][8];
	int times,i,j;
	scanf("%d",&times);

	while( times-- ){
		
		for( i = 0 ; i < 8 ; i++ ){
			for( j = 0 ; j < 8 ; j++ ){
				scanf("%d",&test[i][j]);
			}
		}

		int tmp = 0,ans = 0;
		for( i = 0 ; i < 92 ; i++ ){
			tmp = 0;
			for( j = 0 ; j < 8 ; j++ ){
				tmp = tmp + test[j][table[j][i]];
			}
			if(tmp > ans)
				ans = tmp;
		}

		printf("%5d\n",ans );

	}
	
	return 0;
}
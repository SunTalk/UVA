#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "541"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int table[MAXN+5][MAXN+5];
	int column,row;
	int ans_c,ans_r;
	int num;

	while( ~scanf("%d",&num) && num ){

		for(int i = 0 ; i < num ; i++ )
			for(int j = 0 ; j < num ; j++ )
				scanf("%d",&table[i][j]);

		column = row = 0;
		for(int i = 0 ; i < num ; i++ ){
			
			int check_c = 0,check_r = 0;
			for(int j = 0 ; j < num ; j++ ){
				if( table[i][j] )
					check_r++;
				if( table[j][i] )
					check_c++;
			}

			if( check_r%2 ){
				row++;
				ans_r = i+1;
			}
			if( check_c%2 ){
				column++;
				ans_c = i+1;
			}

		}

		if( row == 0 && column == 0 )
			printf("OK\n");
		else if( row == 1 && column == 1 )
			printf("Change bit (%d,%d)\n",ans_r,ans_c);
		else
			printf("Corrupt\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

string M[5];
bool win(char k){

	if( M[0][0] == k && M[0][1] == k && M[0][2] == k ) return true;
	if( M[1][0] == k && M[1][1] == k && M[1][2] == k ) return true;
	if( M[2][0] == k && M[2][1] == k && M[2][2] == k ) return true;
	if( M[0][0] == k && M[1][0] == k && M[2][0] == k ) return true;
	if( M[0][1] == k && M[1][1] == k && M[2][1] == k ) return true;
	if( M[0][2] == k && M[1][2] == k && M[2][2] == k ) return true;
	if( M[0][0] == k && M[1][1] == k && M[2][2] == k ) return true;
	if( M[0][2] == k && M[1][1] == k && M[2][0] == k ) return true;
	return false;

}

int main(int argc, char const *argv[])
{
	
	int kase;
	scanf("%d",&kase);

	
	while ( kase-- ){
		
		for(int i = 0 ; i < 3 ; i++ )
			cin >> M[i];

		int nX = 0,nO = 0;
		for(int i = 0 ; i < 3 ; i++ ){
			for(int j = 0 ; j < 3 ; j++ ){
				if( M[i][j] == 'X' ) nX++;
				if( M[i][j] == 'O' ) nO++;
			}
		}

		bool Xw = win('X'),Ow = win('O');
		if( (nX == nO+1 && Xw && !Ow) ||
			(nX == nO && Ow && !Xw) ||
			((nX == nO || nX == nO+1) && !Ow && !Xw) )
			printf("yes\n");
		else printf("no\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3F3F3F3F

int table[MAXN+5][MAXN+5];
string str;

int DP(int i, int j){

	if( !(i<j) )
		return table[i][j] = 0;

	if( table[i][j] != INF )
		return table[i][j];

	if( str[i] == str[j] )
		table[i][j] = min(table[i][j], DP(i+1, j-1));
	
	table[i][j] = min(table[i][j], DP(i+1, j-1)+1);
	table[i][j] = min(table[i][j], DP(  i, j-1)+1);
	table[i][j] = min(table[i][j], DP(i+1,   j)+1);

	return table[i][j];

}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	
	for(int K = 1 ; K <= kase ; K++ ){

		cin >> str;
		memset(table,0x3F,sizeof(table));
		printf("Case %d: %d\n", K, DP(0,str.size()-1));

	}

	return 0;
}
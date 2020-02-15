#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 1000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

LL table[310][MAXN+10];

int main(int argc, char const *argv[])
{

	memset(table, 0, sizeof(table));
	table[0][0] = 1;

	for(int i = 0 ; i < 305 ; i++ )
		for(int j = 0 ; i+j < 305 ; j++ )
			for(int k = 1 ; k < MAXN+5 ; k++ )
				table[i+j][k] += table[j][k-1];

	string str;
	int num[5];

	while( getline(cin, str) ){

		stringstream ss(str);
		int k = 0;
		while( ss >> num[k++] );

		switch(k){
			case 2:
				cout << table[num[0]][MAXN] << endl;
				break;
			case 3:
				cout << table[num[0]][num[1]] << endl;
				break;
			case 4:
				if( num[1] == 0 ) cout << table[num[0]][num[2]] << endl;
				else cout << table[num[0]][num[2]]-table[num[0]][num[1]-1] << endl;
				break;
		}

	}

	return 0;
}
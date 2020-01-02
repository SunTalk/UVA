#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int table[MAXN];
vector <int> ans;

void flip(int total, int idx){
	for(int i = 0 ; i <= idx/2 ; i++ )
		swap(table[i], table[idx-i]);
	ans.push_back(total-idx);
}

int main(int argc, char const *argv[])
{

	string str;
	while( getline(cin,str) ){
		
		cout << str << endl;
		stringstream ss(str);

		int total = 0;
		while( ss >> table[total++] );
		total--;
		ans.clear();

		for(int i = 0 ; i < total ; i++ ){
			
			int idx = 0;
			for(int j = 1 ; j < total-i ; j++ )
				if( table[j] > table[idx] )
					idx = j;

			if( idx == total-i-1 )
				continue;
			if( idx != 0 )
				flip(total,idx);
			flip(total,total-i-1);

		}

		ans.push_back(0);
		for(int i = 0 ; i < ans.size() ; i++ )
			printf("%d%c", ans[i], i==ans.size()-1 ? '\n':' ' );

	}

	return 0;
}
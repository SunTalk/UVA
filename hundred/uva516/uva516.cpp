#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 50000
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

bool table[MAXN+10];
vector <int> prime;

void build(){

	memset(table, 0, sizeof(table));
	for(int i = 2 ; i < MAXN ; i++ ){
		if( !table[i] ){
			for(int j = i+i ; j < MAXN ; j += i )
				table[j] = true;
			prime.push_back(i);
		}
	}

}

int main(int argc, char const *argv[])
{

	build();

	string str;
	int num,a,b;
	while( getline(cin,str) && str != "0" ){

		num = 1;
		stringstream ss(str);
		while( ss >> a >> b )
			num *= pow(a,b);
		num--;

		vector <int> ans;
		for(int i = prime.size()-1 ; i >= 0 ; i-- ){
			if( num%prime[i] == 0 ){
				ans.push_back(prime[i]);
				int tmp = 0;
				while( num%prime[i] == 0 ){
					tmp++;
					num /= prime[i];
				}
				ans.push_back(tmp);
			}
		}

		for(int i = 0 ; i < ans.size() ; i++ )
			printf("%d%c", ans[i], i==ans.size()-1 ? '\n':' ' );

	}

	return 0;
}
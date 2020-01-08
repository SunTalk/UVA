#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 12
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int coin[MAXN];

bool NotIn(string a, string b, char c){
	for(int i = 0 ; i < a.size() ; i++ )
		if( a[i] == c ) return false;
	for(int i = 0 ; i < b.size() ; i++ )
		if( b[i] == c ) return false;
	return true;
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d", &kase);

	string L,R,ans;
	int real = 1;
	int heavy = 2;
	int light = 3;
	while( kase-- ){
		
		memset(coin, 0, sizeof(coin));
		for(int i = 0 ; i < 3 ; i++ ){

			cin >> L >> R >> ans;
			if( ans == "even" ){
				for(auto i : L ) coin[i-'A'] = real;
				for(auto i : R ) coin[i-'A'] = real;
			}
			else if( ans == "up" ){
				for(auto i : L ){
					if( coin[i-'A'] == 0 )
						coin[i-'A'] = heavy;
					else if( coin[i-'A'] == light )
						coin[i-'A'] = real;
				}
				for(auto i : R ){
					if( coin[i-'A'] == 0 )
						coin[i-'A'] = light;
					else if( coin[i-'A'] == heavy )
						coin[i-'A'] = real;
				}

				for(int i = 0 ; i < 12 ; i++ )
					if( NotIn(L,R,'A'+i) )
						coin[i] = real;

			}
			else if( ans == "down" ){
				for(auto i : L ){
					if( coin[i-'A'] == 0 )
						coin[i-'A'] = light;
					else if( coin[i-'A'] == heavy )
						coin[i-'A'] = real;
				}
				for(auto i : R ){
					if( coin[i-'A'] == 0 )
						coin[i-'A'] = heavy;
					else if( coin[i-'A'] == light )
						coin[i-'A'] = real;
				}

				for(int i = 0 ; i < 12 ; i++ )
					if( NotIn(L,R,'A'+i) )
						coin[i] = real;

			}

		}

		for(int i = 0 ; i < 12 ; i++ ){
			if( coin[i] == heavy )
				printf("%c is the counterfeit coin and it is heavy.\n", 'A'+i );
			if( coin[i] == light )
				printf("%c is the counterfeit coin and it is light.\n", 'A'+i );
		}

	}


	return 0;
}
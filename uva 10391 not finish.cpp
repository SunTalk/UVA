#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string tmp,tmp_2;
	char check;
	int recode[27]={0};
	string word[5000];
	string print[5000];

	int size = 0;
	while( cin >> tmp ){
		word[size] = tmp;
		recode[(tmp[0]-96)]++;
		size++;
	}

	int len,ans,i,j,k,m,n;

	for( i = 1 ; i < 27 ; i++ )
		recode[i]=recode[i]+recode[i-1];

	ans = 0;
	for( i = 1 ; i < 27 ; i++ ){
		
		for( j = recode[i-1] ; j < recode[i] ; j++ ){

			tmp = word[j];
			len = tmp.size();

			for( k = recode[i-1] ; k < recode[i] ; k++ ){

				tmp_2 = word[k];

				for( n = 0 ; n < len ; n++ )
					if( tmp[n] != tmp_2[n] ) continue;

				for( m = 0 ; m < size ; m++ ){
					if( (word[j] == word[k] + word[m]) && (word[j] != print[ans]) ){
						ans++;
						print[ans] = word[j];
					}
				}

			}

		}

	}

	for( i = 1 ; i < ans ; i++ ){
		cout << print[i] << endl;
	}

	return 0;
}
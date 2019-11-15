#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define DEVIATION 0.00000005

bool is_alphas(char k){
	if( 'a' <= k && k <= 'z' )
		return true;
	if( 'A' <= k && k <= 'Z' )
		return true;
	return false;
}

bool is_vowel(char k){
	if( k == 'A' || k == 'E' || k == 'I' || k == 'O' || k == 'U' )
		return true;
	if( k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' )
		return true;
	return false;
}

int main(int argc, char const *argv[])
{

	string str,tmp,ans;

	while( getline(cin, str) ){

		ans = tmp = "";
		for(int i = 0 ; i < str.size() ; i++ ){
			
			if( is_alphas(str[i]) ){
				tmp += str[i];
			}
			else{
				if( tmp.size() ){
					if( is_vowel(tmp[0]) ){
						tmp += "ay";
					}
					else{
						tmp = tmp.substr(1,tmp.size()-1)+tmp[0]+"ay";
					}
					ans += tmp;
					tmp = "";
				}
				ans += str[i];
			}
		
		}
		if( tmp.size() ){
			if( is_vowel(tmp[0]) ){
				tmp += "ay";
			}
			else{
				tmp = tmp.substr(1,tmp.size()-1)+tmp[0]+"ay";
			}
			ans += tmp;
			tmp = "";
		}

		cout << ans << endl;

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

string change(string str){
	string ans = "";
	transform(str.begin(), str.end(),str.begin(),::tolower);
	for(int i = 0; i < str.size(); i++)
		if( 'a' <= str[i] && str[i] <= 'z' )
			ans += str[i];
	return ans;
}

bool is_palindrome(string str){
	for(int i = 0,j = str.size()-1 ; i < str.size() ; i++,j-- )
		if( str[i] != str[j] )
			return false;
	return true;
}

int main(int argc, char const *argv[])
{

	string str;
	while( getline(cin,str) && str != "DONE" ){
		if( is_palindrome(change(str)) )
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");
	}

	return 0;
}
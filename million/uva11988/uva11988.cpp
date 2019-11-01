#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int main(int argc, char const *argv[])
{

	string str;
	while( getline(cin,str) ){

		list <char> text;
		auto Iter = text.begin();

		for(int i = 0 ; i < str.size() ; i++ ){
			if( str[i] == '[' )
				Iter = text.begin();
			else if( str[i] == ']' )
				Iter = text.end();
			else
				text.insert(Iter, str[i]);
		}

		for(auto i: text)
			cout << i;
		printf("\n");
		
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int soundex(char k){
	string str[6] = {"BFPV","CGJKQSXZ","DT","L","MN","R"};
	for(int i = 0 ; i < 6 ; i++)
		for(int j = 0 ; j < str[i].size() ; j++ )
			if( k == str[i][j] )
				return i+1;
	return 0;
}

int main(int argc, char const *argv[])
{

	string str;
	int pre,now;

	while( cin >> str ){

		pre = 0;
		for(int i = 0; i < str.size() ; i++ ){
			int tmp = soundex(str[i]);
			if( tmp != pre && tmp != 0 )
				printf("%d",tmp);
			pre = tmp;
		}
		printf("\n");
	}

	return 0;
}
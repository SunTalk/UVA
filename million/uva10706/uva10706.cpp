#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 50000

int main(int argc, char const *argv[])
{

	string str,tmp;
	int table[MAXN+5];
	str = "";
	for(int i = 1 ; i < MAXN ; i++ ){
		str += to_string(i);
		table[i] = str.size();
	}

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){

		scanf("%d",&num);
		for(int i = 1 ; i < MAXN ; i++ ){
			if( num > table[i] )
				num -= table[i];
			else{
				printf("%c\n",str[num-1]);
				break;
			}
		}
		
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1200"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

void solve(string str);

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	string str;
	
	while( times-- ){
		cin >> str;
		solve(str);
	}

	return 0;
}

void solve(string str){

	int num = 0;
	int left = 0;
	int right = 0;
	bool symbol = true;
	bool check = false;

	for(int i = 0 ; i < str.size() ; i++ ){
		

		if( str[i] == '+' || str[i] == '-' || str[i] == '=' ){

			if( num != 0 ){
				if(symbol)
					right = right - num;
				else
					right = right + num;
				num = 0;
			}


			if(str[i] == '='){
				symbol = true;
				check = true;
			}

			if( str[i] == '+' )
				symbol = true;
			if( str[i] == '-' )
				symbol = false;
			
			if(check){
				if(symbol)
					symbol = false;
				else
					symbol = true;
			}

		}
		else if( str[i] == 'x' ){
			if( num == 0 && ( i == 0 || str[i-1] != '0' ))
				num = 1;
			if(symbol)
				left = left + num;
			else
				left = left - num;
			num = 0;
		}
		else{
			num = num * 10;
			num = num + str[i] - '0';
		}

	}

	if( num != 0 ){
		if(symbol)
			right = right - num;
		else
			right = right + num;
		num = 0;
	}

	if( left == 0 && right == 0 )
		printf("IDENTITY\n");
	else if( left == 0 )
		printf("IMPOSSIBLE\n");
	else{
		if( right/left < 0 && right%left != 0)
			printf("%d\n", right/left-1 );
		else
			printf("%d\n", right/left );
	}

}
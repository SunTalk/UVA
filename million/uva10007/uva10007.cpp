#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 300
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
string table[MAXN+10];

string times(string a, int b){

	int carry = 0;
	string ans = "";
	for(int i = a.size()-1 ; i >= 0 ; i-- ){
		carry += (a[i]-'0')*b;
		char c = carry%10 + '0';
		ans = c + ans;
		carry /= 10;
	}

	while( carry ){
		char c = carry%10 + '0';
		ans = c + ans;
		carry /= 10;
	}

	return ans;

}

string division(string a, int b){

	string ans = "";
	int carry = 0;
	for(int i = 0 ; i < a.size() ; i++ ){
		carry = carry*10 + (a[i] - '0');
		if( carry >= b ){
			char c = (carry/b + '0');
			ans = ans + c;
			carry %= b;
		}
		else if( ans != "" ) ans += "0";
	}

	return ans;

}

string next(string a, int b){
	
	int k = 2*b*(2*b-1);
	string ans = times(a,k);
	return division(ans,b+1);

}

int main(int argc, char const *argv[])
{

	table[1] = "1";
	for(int i = 2 ; i < MAXN+5 ; i++ )
		table[i] = next(table[i-1],i);

	int num;
	while( ~scanf("%d",&num) && num )
		cout << table[num] <<endl;

	return 0;
}
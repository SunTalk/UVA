#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int Turn(int k){
	int tmp = k;
	int ans = k;
	while( tmp >= 10 ){
		ans = 0;
		while( tmp>0 ){
			ans+=tmp%10;
			tmp/=10;
		}
		tmp = ans;
	}
	return ans;
}

int main(int argc, char const *argv[])
{

	map <char,int> table;
	for(char k = 'a' ; k <= 'z' ; k++ )
		table[k] = k-'a'+1;
	for(char k = 'A' ; k <= 'Z' ; k++ )
		table[k] = k-'A'+1;

	string one,two;
	int A,B;
	while( getline(cin,one) ){
		getline(cin,two);
		A = B = 0;
		for(int i = 0 ; i < one.size() ; i++ )
			A += table[one[i]];
		for(int i = 0 ; i < two.size() ; i++ )
			B += table[two[i]];

		A = Turn(A);
		B = Turn(B);

		double a = (double)A;
		double b = (double)B;

		if( a > b )
			printf("%.2lf %\n",100*b/a);
		else
			printf("%.2lf %\n",100*a/b);

	}

	return 0;
}
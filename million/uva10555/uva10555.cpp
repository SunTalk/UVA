#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int main(int argc, char const *argv[])
{

	string str;
	int A,B,a,b;

	while( cin >> str && str != "0" ){

		str = str.substr(2,str.size()-5);

		int num = 0;
		for(int i = 0 ; i < str.size() ; i++ ){
			num *= 10;
			num += str[i]-'0';
		}

		A = B = INT_MAX;
		for(int i = 0 ; i < str.size() ; i++ ){
			int tmp = num/pow(10,str.size()-i);
			a = num-tmp;
			b = pow(10,str.size())-pow(10,i);
			int g = __gcd(a,b);
			a /= g;
			b /= g;
			if( b < B ){
				A = a;
				B = b;
			}
		}
		printf("%d/%d\n",A,B);

	}

	return 0;
}
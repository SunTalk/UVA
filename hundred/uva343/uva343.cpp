#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

int ValueChar(char c){
	if( c >= '0' && c <= '9' )
		return c-'0';
	return c-'A'+10;
}

int ValueStr(int base, string str){
	int val = 0;
	for(int i = 0 ; i < str.size() ; i++ ){
		val *= base;
		val += ValueChar(str[i]);
	}
	return val;
}

void printAns(string A, int i, string B, int j){
	cout << A ;
	cout << " (base " << i << ")";
	cout << " = ";
	cout << B ;
	cout << " (base " << j << ")";
	cout << endl;
}

void printNot(string A, string B){
	cout << A ;
	cout << " is not equal to ";
	cout << B ;
	cout << " in any base 2..36";
	cout << endl;
}

int main(int argc, char const *argv[])
{

	string A,B;
	while( cin >> A >> B ){

		int Amax = 1,Bmax = 1;
		for(int i = 0 ; i < A.size() ; i++ )
			Amax = max(Amax,ValueChar(A[i]));
		for(int i = 0 ; i < B.size() ; i++ )
			Bmax = max(Bmax,ValueChar(B[i]));

		bool ans = false;
		for(int i = Amax+1 ; i < 37 ; i++ ){
			for(int j = Bmax+1 ; j < 37 ; j++ ){
				if( !ans && ValueStr(i,A) == ValueStr(j,B) ){
					ans = true;
					printAns(A,i,B,j);
				}
			}
		}
		if( !ans ) printNot(A,B);
	}

	return 0;
}
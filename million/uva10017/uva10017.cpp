#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10017"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> A,B,C;
int m,n;

void print_hanoi(){

	printf("A=>");
	if( !A.empty() ){
		printf("  ");
		for(int i = 0 ; i < A.size() ; i++)
			printf(" %d",A[i] );
	}
	printf("\n");
	printf("B=>");
	if( !B.empty() ){
		printf("  ");
		for(int i = 0 ; i < B.size() ; i++)
			printf(" %d",B[i] );
	}
	printf("\n");
	printf("C=>");
	if( !C.empty() ){
		printf("  ");
		for(int i = 0 ; i < C.size() ; i++)
			printf(" %d",C[i] );
	}
	printf("\n\n");

}

void Hanoi(int k , vector<int>&one, vector<int>&two, vector<int>&three ){
	
	if( n <= 0 )
		return;
	if( k == 1 ){
		three.push_back(one.back());
		one.pop_back();
		print_hanoi();
		n--;
		return;
	}
	Hanoi(k-1,one,three,two);
	if( n <= 0 )
		return;
	three.push_back(one.back());
	one.pop_back();
	print_hanoi();
	n--;
	if( n <= 0 )
		return;
	Hanoi(k-1,two,one,three);
	
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE = 1;
	while( ~scanf("%d %d",&m,&n) ){
		if( m==0 && n==0 )
			break;
		printf( "Problem #%d\n\n", CASE++ );
		A.clear();
		B.clear();
		C.clear();

		for(int i = m ; i >= 1 ; i-- )
			A.push_back(i);

		print_hanoi();
		Hanoi(m,A,B,C);

	}

	return 0;
}
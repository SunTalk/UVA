#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12241"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

void cal(int num, int k[] ){

	int tmp = num;
	int ten = 1;
	while( tmp ){
		for(int i = 0 ; i < tmp%10 ; i++ )
			k[i] += ten;
		for(int i = 0 ; i < 10 ; i++ )
			k[i] += ten*(tmp/10);
		k[0] -= ten;
		k[tmp%10] += (num%ten)+1;
		ten *= 10;
		tmp /= 10;

	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int a,b;
	int A[10],B[10];

	while( ~scanf("%d %d",&a,&b) && b ){

		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		
		cal(a-1,A);
		cal(b,B);

		for(int i = 0 ; i < 10 ; i++ ){
			printf("%d", B[i]-A[i] );
			printf("%c", i==9?'\n':' ' );
		}
	}

	return 0;
}
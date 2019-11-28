#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 50
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005


int main(int argc, char const *argv[])
{

	int num;
	int kase = 1;
	int table[MAXN];
	bitset <50000> B;

	while( ~scanf("%d",&num) ){

		bool isA = true;

		int total = 0;
		printf("Case #%d:",kase++);
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d",&table[i]);
			printf(" %d",table[i]);
			total += table[i];
			if( i && table[i]<table[i-1] ) isA = false;
		}
		printf("\n");

		B.reset();
		for(int i = 0 ; i < num ; i++ ){
			for(int j = total ; j >= 0 ; j-- ){
				if( B[j] ) B[j+table[i]] = 1;
			}
			if( B[table[i]] ) isA = false;
			B[table[i]] = 1;
		}
		
		if( isA ) printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11959"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct dice {
	int num[6];
};

bool the_same(dice A,dice B){

	for(int i = 0 ; i < 6 ; i++ )
		if ( A.num[i] != B.num[i] )
			return false;
	return true;

}

void turn_right(dice *A){
	int tmp = A->num[0];
	A->num[0] = A->num[3];
	A->num[3] = A->num[1];
	A->num[1] = A->num[5];
	A->num[5] = tmp;
}

void turn_front(dice *A){
	int tmp = A->num[0];
	A->num[0] = A->num[4];
	A->num[4] = A->num[1];
	A->num[1] = A->num[2];
	A->num[2] = tmp;
}

void turn_clock(dice *A){
	int tmp = A->num[2];
	A->num[2] = A->num[3];
	A->num[3] = A->num[4];
	A->num[4] = A->num[5];
	A->num[5] = tmp;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int CASE;
	scanf("%d",&CASE);

	string one,two;
	dice dic_a,dic_b;

	while( CASE-- ){

		cin >> one >> two ;
		
		for(int i = 0 ; i < 6 ; i++){
			dic_a.num[i] = one[i]-'0';
			dic_b.num[i] = two[i]-'0';
		}

		bool ans = false;

		for(int i = 0 ; i < 4 ; i++ ){
			for(int j = 0 ; j < 4 ; j++ ){
				for(int k = 0 ; k < 4 ; k++ ){
					if( the_same(dic_a,dic_b) )
						ans = true;
					turn_front(&dic_a);
					// printf("%d %d %d %d %d %d\n", dic_a.num[0],dic_a.num[1],dic_a.num[2],dic_a.num[3],dic_a.num[4],dic_a.num[5] );
				}
				if( the_same(dic_a,dic_b) )
					ans = true;
				turn_clock(&dic_a);
			}
			if( the_same(dic_a,dic_b) )
				ans = true;
			turn_right(&dic_a);
		}

		if( ans )
			printf("Equal\n");
		else
			printf("Not Equal\n");
	
	}

	return 0;
}
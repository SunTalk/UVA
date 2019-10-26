#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int A,B,C;
int now,ans;

void use_A(){
	A -= 1;
	while( A-- )
		printf(" %d", ++now);
}

void use_B(){
	if( B%2 ){
		for(int i = 0 ; i < (B/2)+1 ; i++ ){
			now += 2;
			printf(" %d",now);
		}
		printf(" %d", --now);
		for(int i = 0 ; i < B/2 ; i++ ){
			now -= 2;
			printf(" %d",now);
		}
	}
	else{
		for(int i = 0 ; i < B/2 ; i++ ){
			now += 2;
			printf(" %d",now);
		}
		printf(" %d", ++now);
		for(int i = 0 ; i < B/2 ; i++ ){
			now -= 2;
			printf(" %d",now);
		}
	}
}

void use_C(){

	switch (C%3){

		case 0:
			for(int i = 0 ; i < C/3 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			printf(" %d",++now);
			for(int i = 0 ; i < C/3 ; i++ ){
				now -= 3;
				printf(" %d",now);
			}
			printf(" %d",++now);
			for(int i = 0 ; i < C/3 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			A -= 2;
			break;
		case 1:
			for(int i = 0 ; i < (C/3)+1 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			now -= 2;
			printf(" %d",now);
			for(int i = 0 ; i < C/3 ; i++ ){
				now -= 3;
				printf(" %d",now);
			}
			printf(" %d",++now);
			for(int i = 0 ; i < C/3 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			now += 2;
			printf(" %d",now);
			A -= 1;
			B -= 2;
			break;
		case 2:
			for(int i = 0 ; i < (C/3)+1 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			printf(" %d",--now);
			for(int i = 0 ; i < C/3 ; i++ ){
				now -= 3;
				printf(" %d",now);
			}
			printf(" %d",--now);
			for(int i = 0 ; i < (C/3)+1 ; i++ ){
				now += 3;
				printf(" %d",now);
			}
			A -= 2;
			break;

	}

}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	while( kase-- ){

		scanf("%d %d %d",&A,&B,&C);
		printf("0");
		now = 0;
		use_C();
		use_A();
		use_B();
		printf("\n");

	}

	return 0;
}
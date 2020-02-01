#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

int digit(int k){
	int dig = 1;
	while( k/=10 ) dig++;
	return dig;
}

bool isArm(int num, int dig){
	int ans = 0;
	int check = num;
	while( check ){
		ans += pow(check%10,dig);
		check /= 10;
	}
	if( ans == num ) return true;
	return false;
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);

	int num;
	while( kase-- ){
		scanf("%d",&num);
		if( isArm(num,digit(num)) )
			printf("Armstrong\n");
		else printf("Not Armstrong\n");
	}

	return 0;
}
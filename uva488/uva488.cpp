#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "488"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,i;
	int number,wave,j;

	scanf("%d ", &times);

	for(i=0;i<times;i=i+1){
		scanf("%d %d ", &wave, &number);

		for(j=0;j<number;j=j+1){

			if(i!=0 || j!=0) printf("\n");
			if(wave>=1) printf("1\n");
			if(wave>=2) printf("22\n");
			if(wave>=3) printf("333\n");
			if(wave>=4) printf("4444\n");
			if(wave>=5) printf("55555\n");
			if(wave>=6) printf("666666\n");
			if(wave>=7) printf("7777777\n");
			if(wave>=8) printf("88888888\n");
			if(wave>=9) printf("999999999\n");
			if(wave>8) printf("88888888\n");
			if(wave>7) printf("7777777\n");
			if(wave>6) printf("666666\n");
			if(wave>5) printf("55555\n");
			if(wave>4) printf("4444\n");
			if(wave>3) printf("333\n");
			if(wave>2) printf("22\n");
			if(wave>1) printf("1\n");
		
		}

	}

	return 0;
}
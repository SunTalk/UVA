#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "357"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	long long dollar[30005];
	int value[5]={1,5,10,25,50};
	int i,j,k,tmp;
	int money;

	for(i=0;i<30005;i=i+1){
		dollar[i]=1;
	}

	for(i=1;i<5;i=i+1){
		for(j=1;j<30005;j=j+1){
			if( j>=value[i] ){
				tmp=j-value[i];
				dollar[j]=dollar[j]+dollar[tmp];
			}
		}
	}

	while( scanf("%d",&money) != EOF ){
		if(dollar[money]==1){
			printf("There is only 1 way to produce %d cents change.\n",money);
		}
		else{
			printf("There are %lld ways to produce %d cents change.\n",dollar[money],money );
		}
	}

	return 0;
}
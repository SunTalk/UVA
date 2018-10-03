#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1605"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int country,i,j;
	char mark[50]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x'};

	while( ~scanf("%d",&country) ){
		printf("2 %d %d\n",country,country );

		for(i=0;i<country;i++){
			for(j=0;j<country;j++){
				printf("%c",mark[i]);
			}
			printf("\n");
		}
		printf("\n");
		for(i=0;i<country;i++){
			for(j=0;j<country;j++){
				printf("%c",mark[j]);
			}
			printf("\n");
		}
	}

	return 0;
}
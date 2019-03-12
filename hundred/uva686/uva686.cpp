#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "686"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


int prime[33000];

void Prime(){

	int check,tmp,i,j;
	memset(prime,0,sizeof(prime));

	for(i=2;i<33000;i=i+1){
		check=0;
		tmp=int(sqrt(i));
		for(j=2;j<=tmp;j=j+1){
			if(i%j==0){
				check=1;
				break;
			}
		}
		if(check==0)
			prime[i]=1;
		else
			prime[i]=0;
	}

	prime[2]=1;

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number;
	int tmp,ans,i;
	Prime();
	while(scanf("%d",&number) != EOF ){
		if(number==0)
			break;

		ans=0;
		for(i=2;i<=number/2;i=i+1){
			if(prime[i]==1 && prime[number-i]==1)
				ans=ans+1;
		}

		printf("%d\n",ans );

	}

	return 0;
}
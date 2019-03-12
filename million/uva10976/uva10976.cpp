#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10976"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number;

	while(~scanf("%d",&number)){
		
		int x[number+1],y[number+1];
		x[0]=0;
		y[0]=number;
		int check=1,i,ans=0;

		for(i=1;i<number+1;i=i+1){
			y[i]=y[i-1]+1;
			x[i]=y[i]*number;
			if(x[i]%check==0){
				x[i]=x[i]/check;
				ans++;
			}
			else{
				x[i]=0;
			}

			check++;
		}

		printf("%d\n",ans );
		for(i=0;i<number+1;i=i+1){
			if(x[i]!=0){
				printf("1/%d = 1/%d + 1/%d\n",number,x[i],y[i] );
			}
		}

	}

	return 0;
}
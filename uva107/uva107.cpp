#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "107"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	long long start,end,i;
	long long number,tall;
	long long check,tmp; 

	while(1){
		scanf("%lld %lld",&start,&end);
		if(start==0 && end==0) break;

		number=1;
		check=1;
		tall=start;

		if(end==1){
			tall=(start*2)-1;
			for(i=1;start>1;i=i+1){
				start=start/2;
			}
			number=i-1;
			start=1;	
		}
		
		if(start==end+1){
			number=1;
			tall=start+end;
			start=1;
		}

		for(i=2;i<start;i=i+1){
			if( start%i==0){
				tmp=start;
				while(tmp>1){
					tmp=tmp/i;
					check=check*(i-1);
					tall=tall+tmp*check;
					number=number+check;
				}
			}

			if(check==end){
				number=number-check;
				break;
			}
			else{
				number=1;
				check=1;
				tall=start;
			}
		}

		printf("%lld %lld\n",number,tall );

	}

	return 0;
}
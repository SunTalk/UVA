#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10920"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	long long size,number;
	long long level[50005],i,Tmp;
	long long tmp,line,column;

	for(i=0;i<50005;i=i+1){
		tmp=(i*2)-1;
		level[i]=tmp*tmp;
	}

	while(scanf("%lld %lld",&size,&number) != EOF && size && number){
		
		tmp=(size+1)/2;
		line=column=tmp;
		if(number==1){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		} 

		for(i=2;i<=tmp;i=i+1){
			if(number<=level[i] && number>level[i-1]){//49 36 i=4
				tmp=level[i-1];
				Tmp=(i-1)*2;
				break;
			}
			line=line+1;
			column=column+1;
		}

		tmp=tmp+1;
		line=line+1;
		if(tmp==number){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		}

		for(i=0;i<Tmp-1;i=i+1){
			column=column-1;
			tmp=tmp+1;
			if(tmp==number){
				break;
			}
		}
		if(tmp==number){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		}
		for(i=0;i<Tmp;i=i+1){
			line=line-1;
			tmp=tmp+1;
			if(tmp==number){
				break;
			}
		}
		if(tmp==number){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		}

		for(i=0;i<Tmp;i=i+1){
			column=column+1;
			tmp=tmp+1;
			if(tmp==number){
				break;
			}
		}
		if(tmp==number){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		}

		for(i=0;i<Tmp;i=i+1){
			line=line+1;
			tmp=tmp+1;
			if(tmp==number){
				break;
			}
		}
		if(tmp==number){
			printf("Line = %lld, column = %lld.\n",line,column );
			continue;
		}

	}

	return 0;
}
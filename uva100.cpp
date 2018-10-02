#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "100"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

unsigned int table[1000001];
unsigned int temp,number,i;

void Table(){
	for(i=1;i<1000001;i=i+1){
		number=1;
		temp=i;
		while(temp!=1){
			if(temp%2==1){
				temp=temp*3;
				temp=temp+1;
			}
			else{
				temp=temp/2;
			}
			//
			if(temp<i){
				number=number+table[temp];
				break;
			}
			//
			number=number+1;
		}
		table[i]=number;
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	memset(table,0,sizeof(table));
	Table();
	unsigned int one,two,ans;
//
	while( scanf("%d %d",&one,&two) != EOF){
		ans=1;

		if(one>two){
			for(i=two;i<=one;i=i+1){
				
				if(ans<table[i]){
					ans=table[i];
				}
				
			}
		}
		else{
			for(i=one;i<=two;i=i+1){
				
				if(ans<table[i]){
					ans=table[i];
				}
				
			}
		}
			
		printf("%d %d %d\n",one,two,ans);
	}



	return 0;
}
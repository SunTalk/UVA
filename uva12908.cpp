#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12908"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int data[15005],i;

void setup(){
	memset(data,0,sizeof(data));
	for(i=1;i<15005;i++)
		data[i]=data[i-1]+i;
}

int binary_search(int start,int end,int num){
	int tmp = (start+end)/2;
	if( (end-start) == 1 )
		return end;
	if( num > data[tmp] )
		return binary_search(tmp,end,num);
	else
		return binary_search(start,tmp,num);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	setup();
	int number;
	int seat;
	while( ~scanf("%d",&number) && number ){
		seat = binary_search(1,15005,number);
		if( (data[seat]-number) == 0 ) seat++;
		printf("%d %d\n",data[seat]-number,seat);
	}

	return 0;
}
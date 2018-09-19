#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{

	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	double dif[50005];
	memset(dif,0,sizeof(dif));
	int tmp,i;

	dif[1]=1;
	for(i=2;i<50005;i=i+1){
		tmp=i*2-2;
		dif[i]=dif[i-1]*tmp*(tmp-1);
		dif[i]=dif[i]/(tmp/2);
		dif[i]=dif[i]/(tmp/2);
		dif[i]=dif[i]/4;
	}

	int times,number;
	scanf("%d",&times);

	for(i=0;i<times;i=i+1){
		scanf("%d",&number);
		printf("%.4lf\n", 1-dif[number/2] );
	}


	return 0;
}
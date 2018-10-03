#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "104"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif


	double coin[20][20][20];
	int path[20][20][20];
	int type,i,j,k;
	int step,target,correct;
	double tmp;
	int ans[21];

	while( scanf("%d",&type) != EOF ){
		
		memset(coin,0,sizeof(coin));
		memset(path,0,sizeof(path));
		memset(ans,0,sizeof(ans));

		for(i=0;i<type;i=i+1){
			for(j=0;j<type;j=j+1){
				if(i==j)
					coin[0][i][j]=1;
				else
					scanf("%lf",&coin[0][i][j]);
				path[0][i][j]=i;
			}
		}

		for(step=1;step<type;step=step+1){
			for(k=0;k<type;k=k+1){
				for(i=0;i<type;i=i+1){
					for(j=0;j<type;j=j+1){
						tmp = coin[step-1][i][k] * coin[0][k][j];
						if(tmp > coin[step][i][j] && j!=k){
							coin[step][i][j]=tmp;
							path[step][i][j]=k;
						}
					}
				}
			}
		}

		target=-1;
		for(step=1;step<type;step=step+1){
			for(i=0;i<type;i=i+1){
				if( coin[step][i][i] > 1.01 ){
					target=i;
					break;
				}
			}
			if(target!=-1)
				break;
		}

		if(target==-1)
			printf("no arbitrage sequence exists\n");
		else{
			correct=target;
			ans[0]=target+1;
			for(i=step;i>0;i=i-1){
				correct=path[step][target][correct];
				ans[i]=correct+1;
			}
			for(i=0;i<=step;i=i+1){
				printf("%d ",ans[i] );
			}
			printf("%d\n",ans[0] );
		}

	}

	return 0;
}
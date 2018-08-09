#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int times;
	cin >> times ;
	int NumX,NumY,i,j,k;
	int zero,check;
	char tmp[1000];

	for(i=0;i<times;i=i+1){

		scanf("%d %d\n",&NumX,&NumY);
		int Safe[NumX][NumY]; 
		for(j=0;j<NumX;j=j+1){
			for(k=0;k<NumY;k=k+1){
				Safe[j][k]=999;
			}
		}

		for(j=0;j<NumX;j=j+1){
			for(k=0;k<1000;k=k+1){
				scanf("%c",&tmp[k]);
				if(tmp[k]=='\n') break;
			}
			check=k;

			for(k=1;k<check;k=k+1){
				if(tmp[k]==' ') continue;
				zero=tmp[k]-'0';
				if( tmp[k+1]!=' ' && tmp[k+1]!='\n'){
					zero=zero*10;
					zero=zero+(tmp[k+1]-'0');
					k=k+1;
				}
				Safe[j][zero-1]=0;
			}
		}

		Safe[0][0]=1;

		for(j=0;j<NumX;j=j+1){
			for(k=0;k<NumY;k=k+1){
				if(Safe[j][k]!=0){
					if(j==0 && k==0)continue;
					if(j==0){
						Safe[j][k]=Safe[j][k-1];
					}
					else if(k==0){
						Safe[j][k]=Safe[j-1][k];
					}
					else{
						Safe[j][k]=Safe[j-1][k]+Safe[j][k-1];
					}
				}
			}
		}

		if(i!=0) cout << endl;
		cout << Safe[NumX-1][NumY-1] << endl ; 
	}

	return 0;
}
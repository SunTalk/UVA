#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int size,number;
	int level[50001],i,Tmp;
	int tmp,line,column;

	for(i=0;i<50001;i=i+1){
		tmp=(i*2)-1;
		level[i]=tmp*tmp;
	}

	while(scanf("%d %d",&size,&number) != EOF && size && number){
		
		tmp=(size+1)/2;
		line=column=tmp;
		if(number==1){
			printf("Line = %d, column = %d.\n",line,column );
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
			printf("Line = %d, column = %d.\n",line,column );
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
			printf("Line = %d, column = %d.\n",line,column );
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
			printf("Line = %d, column = %d.\n",line,column );
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
			printf("Line = %d, column = %d.\n",line,column );
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
			printf("Line = %d, column = %d.\n",line,column );
			continue;
		}

	}




	return 0;
}

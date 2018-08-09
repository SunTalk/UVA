#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	string Poker[52];
	string tmp;
	int check,i,j,number;
	int sizeA,sizeB;

	while(1){
		cin >> Poker[0];
		if(Poker[0]=="#")
			break;
		for(i=1;i<52;i=i+1){
			cin >> Poker[i];
		}
		check=1;
		number=52;

		for(i=0;i<number;i=i+1){//Accordian

			if(i>2){
				sizeB=Poker[i].size();
				sizeA=Poker[i-3].size();	

				if( Poker[i][sizeB-1]==Poker[i-3][sizeA-1] || Poker[i][sizeB-2]==Poker[i-3][sizeA-2] ){//left three
					
					Poker[i-3]=Poker[i-3].append(Poker[i],sizeB-2,2);
					tmp="";
					tmp=tmp.append(Poker[i],0,sizeB-2);
					Poker[i]="";
					Poker[i]=Poker[i].append(tmp,0,sizeB-2);
					tmp="";

					if(Poker[i].empty()==1){
						for(j=i;j<number-1;j=j+1){
							Poker[j]=Poker[j+1];
						}
						Poker[number-1]="";
						number=number-1;
					}
					check=1;
				}
			}

			if(check==1){
				i=0;
				check=0;
				continue;
			}

			sizeB=Poker[i].size();
			sizeA=Poker[i-1].size();

			if( Poker[i][sizeB-1]==Poker[i-1][sizeA-1] || Poker[i][sizeB-2]==Poker[i-1][sizeA-2] ){//left
			
				Poker[i-1]=Poker[i-1].append(Poker[i],sizeB-2,2);
				tmp="";
				tmp=tmp.append(Poker[i],0,sizeB-2);
				Poker[i]="";
				Poker[i]=Poker[i].append(tmp,0,sizeB-2);
				tmp="";
				
				if(Poker[i].empty()==1){
					for(j=i;j<number-1;j=j+1){
						Poker[j]=Poker[j+1];
					}
					Poker[number-1]="";
					number=number-1;
				}
				check=1;
			}
			if(check==1){
				i=0;
				check=0;
				continue;
			}
		}
		
		printf("%d pile",number);
		if(number!=1) cout << "s";
		printf(" remaining:");
		for(i=0;i<number;i=i+1){
			printf(" %d",(Poker[i].size())/2);
		}
		printf("\n");
	}

	return 0;
}
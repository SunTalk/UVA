#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int times,limit,point;
	int distance,weight;
	int Road,Dis,Wei,i,j;
	int tmp;
	cin >> times;

	for(i=0;i<times;i=i+1){
		cin >> limit >> point;
		distance=0;
		Dis=0;
		Wei=0;
		tmp=0;
		for(j=0;j<point;j=j+1){
			
			cin >> Road >> weight;
			distance=Road-tmp;
			tmp=Road;
			Dis=Dis+distance;
			Wei=Wei+weight;
			if(Wei>limit){
				Dis=Dis+2*Road;
				Wei=weight;
				if(j==point-1){
					Dis=Dis+Road;
					break;
				}
				else if(weight==limit){
					Dis=Dis+2*Road;
					Wei=0;
				}
			}
			else if(Wei==limit){
				if(j==point-1){
					Dis=Dis+Road;
					break;
				}
				Dis=Dis+2*Road;
				Wei=0;
			}
			else{
				if(j==point-1){
					Dis=Dis+Road;
					break;
				}
			}
		}

		cout << Dis << endl;
	}

	return 0;
}

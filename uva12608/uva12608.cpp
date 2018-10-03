#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12608"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
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
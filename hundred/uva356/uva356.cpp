#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

double len(int a, int b){
	return (double)(a*a+b*b);
}

int main(int argc, char const *argv[])
{

	int num;
	bool flag = false;

	while( ~scanf("%d", &num) ){

		double r = (double)num - 0.5;
		int all = 0,part = 0;
		for(int i = 0 ; i < num ; i++ ){
			for(int j = 0 ; j < num ; j++ ){
				if( len(i+1,j+1) <= r*r )
					all++;
				else if( len(i,j) < r*r )
					part++;
			}
		}

		if(flag) cout << endl;
		flag = true;
		printf("In the case n = %d, %d cells contain segments of the circle.\n",num,4*part);
		printf("There are %d cells completely contained in the circle.\n",4*all);

	}

	return 0;
}
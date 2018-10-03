#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10409"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int tmp,top,down,north,south,west,east;

void Set(){
	top = 1;
	north = 2;
	west = 3;
	down = 6;
	south = 5;
	east = 4;
}

void North(){
	tmp = top;
	top = south;
	south = down;
	down = north;
	north = tmp;
}

void South(){
	tmp = top;
	top = north;
	north = down;
	down = south;
	south = tmp;
}

void West(){
	tmp = top;
	top = east;
	east = down;
	down = west;
	west = tmp;
}

void East(){
	tmp = top;
	top = west;
	west = down;
	down = east;
	east = tmp;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number,i;
	string action;

	while( ~scanf("%d",&number) && number ){
		
		Set();
		for(i=0;i<number;i++){
			cin >> action;

			if(action=="north")
				North();
			else if(action=="south")
				South();
			else if(action=="west")
				West();
			else if(action=="east")
				East();
		}
		
		printf("%d\n",top );

	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "101"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int block[25][25];
int position[25];

void Set(){
	memset(block,-1,sizeof(block));
	for(int i=0;i<25;i++){
		position[i]=i;
		block[0][i]=i;
	}
}

void Put_Back(int a){
	bool start=0;
	int seat,tmp;
	seat = position[a];
	for(int i=0;i<25;i++){
		if(block[i][seat] == -1)
			break;

		if(start == 1 ){
			tmp = block[i][seat];
			block[i][seat] = -1;
			for(int j=0;j<25;j++){
				if(block[j][tmp] == -1){
					block[j][tmp]=tmp;
					break;
				}
			}
			position[tmp]=tmp;
		}	

		if(block[i][seat] == a)
			start = 1;
	}
}

void Put_To(int a,int b){
	int seat_a = position[a];
	int seat_b = position[b];
	int start_a = 0;
	int start_b = 0;
	int tmp;

	for(int i=0;i<25;i++)
		if(block[i][seat_a] == a )
			start_a = i;
	for(int i=0;i<25;i++){
		if(block[i][seat_b] == -1 ){
			start_b = i;
			break;
		}
	}
	for(int i=start_a;i<25;i++){
		if(block[i][seat_a] == -1)
			break;
		block[start_b][seat_b] = block[i][seat_a];
		position[block[start_b][seat_b]]=seat_b;
		start_b++;
		block[i][seat_a] = -1;
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int number;
	int one,two;
	string action_a,action_b;

	while( ~scanf("%d",&number) ){
		Set();
		while( cin >> action_a ){
			if( action_a == "quit" )
				break;
			cin >> one >> action_b >> two;

			if(position[one] == position[two])
				continue;

			if( action_a == "move" ){

				if( action_b == "onto" ){
					Put_Back(one);
					Put_Back(two);
					Put_To(one,two);
				} // end move onto
				else if( action_b == "over" ){
					Put_Back(one);
					Put_To(one,two);
				} // end move over 

			} // end if move
			else if( action_a == "pile" ){

				if( action_b == "onto" ){
					Put_Back(two);
					Put_To(one,two);
				} // end pile onto
				else if( action_b == "over" ){
					Put_To(one,two);
				} // end pile over

			} // end if pile

		} // end while action

		// printf("ans:\n");
		for(int i=0;i<number;i++){
			printf("%d:", i);
			for(int j=0;j<number;j++){
				if( block[j][i] == -1 )
					break;
				printf(" %d",block[j][i] );
			}
			printf("\n");
		}

	}


	return 0;
}
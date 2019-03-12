#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12414"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector <int> Number;
vector <char> Name;

void Add(int n,int k){

	if(k>=0){
		int num;
		num = n + Name[k] - 'A';

		while(num>0){
			Number.push_back(num%10);
			num=num/10;
		}

		Add(n,k-1);
	}

}

int Check(){
	int number;
	if(Number.size()==3){
		number = Number[0] + 10*Number[1] + 100*Number[2];
		return number;
	}
	else{
		for(int i=0;i<Number.size()-1;i++){
			Number[i] = (Number[i] + Number[i+1])%10;
		}
		Number.pop_back();
		return Check();
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	char name;
	while( ~scanf("%c",&name) ){

		Name.push_back(name);
		while( scanf("%c",&name) ){
			if( name == '\n' )
				break;
			Name.push_back(name);
		}

		int size = Name.size();
		bool check = 0;
		for(int i=1;i<10001;i++ ){
			
			Add(i,size-1);
			if( Check() == 100 )
				check = 1;

			if( check == 1 ){
				printf("%d\n",i );
				break;
			}

			Name.clear();
			Number.clear();
		}

		if( check == 0 )
			printf(":(\n");

	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Block{
private:
	vector <int> Area[25];
	int FirstA,FirstB;
	int SecondA,SecondB;
	int record,First,Second;
public:
	
	void Start(int number){
		for(int i=0;i<number;i=i+1){
			Area[i].push_back(i);
		}
		record=number;
	}

	void FindNumberFirst(int a,int b){
		int i,j;
		for(i=0;i<a;i=i+1){
			int size=Area[i].size();
			for(j=0;j<size;j=j+1){
				if(Area[i][j]==b){
					FirstA=i;
					FirstB=j;
				}
			}
		}
		First=b;
	}
	void FindNumberSecond(int a,int b){
		int i,j;
		for(i=0;i<a;i=i+1){
			int size=Area[i].size();
			for(j=0;j<size;j=j+1){
				if(Area[i][j]==b){
					SecondA=i;
					SecondB=j;
				}
			}
		}
		Second=b;
	}

	void ClearFirst(){//clear up on First
		int tmp,i,size;
		size=Area[FirstA].size();
		for(i=FirstB+1;i<size;i=i+1){
			tmp=Area[FirstA][i];
			Area[tmp].push_back(tmp);
		}
		for(i=FirstB+1;i<size;i=i+1){
			Area[FirstA].erase(Area[FirstA].end()-1);
		}
	}
	void ClearSecond(){//clear up on Second
		int tmp,i,size;
		size=Area[SecondA].size();
		for(i=SecondB+1;i<size;i=i+1){
			tmp=Area[SecondA][i];
			Area[tmp].push_back(tmp);
		}
		for(i=SecondB+1;i<size;i=i+1){
			Area[SecondA].erase(Area[SecondA].end()-1);
		}
	}

	void Move(){
		int tmp,i,size;
		size=Area[FirstA].size();
		for(i=FirstB;i<size;i=i+1){
			tmp=Area[FirstA][i];
			Area[SecondA].push_back(tmp);
		}
		for(i=FirstB;i<size;i=i+1){
			Area[FirstA].erase(Area[FirstA].end()-1);
		}
	}

	void Check(){
		FindNumberFirst(record,First);
		FindNumberSecond(record,Second);
	}

	void MoveOnto(){
		ClearFirst();
		Check();
		ClearSecond();
		Check();
		Move();
	}

	void MoveOver(){
		ClearFirst();
		Check();
		Move();
	}

	void PileOnto(){
		ClearSecond();
		Check();
		Move();
	}

	void PileOver(){
		Move();
	}

	void Print(int number){
		int size,i,j;
		for(i=0;i<number;i=i+1){
			cout << i << ":" ;
			size=Area[i].size();
			for(j=0;j<size;j=j+1){
				cout << " " << Area[i][j];
			}
			cout << endl;
		}
	}

	void Quit(){
		for(int i=0;i<25;i=i+1){
			Area[i].clear();
		}
		
	}
};

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	Block fuck;
	int number,A,B;
	string message;

	cin >> number;
	
	fuck.Start(number);
	while(1){
		cin >> message;

		if(message=="quit"){
			fuck.Print(number);
			fuck.Quit();
			break;
		}

		if(message=="move"){
			cin >> A;
			fuck.FindNumberFirst(number,A);
			cin >> message;

			if(message=="onto"){
				cin >> B;
				fuck.FindNumberSecond(number,B);
				fuck.MoveOnto();
			}
			if(message=="over"){
				cin >> B;
				fuck.FindNumberSecond(number,B);
				fuck.MoveOver();
			}
		}

		if(message=="pile"){
			cin >> A;
			fuck.FindNumberFirst(number,A);
			cin >> message;

			if(message=="onto"){
				cin >> B;
				fuck.FindNumberSecond(number,B);
				fuck.PileOnto();
			}
			if(message=="over"){
				cin >> B;
				fuck.FindNumberSecond(number,B);
				fuck.PileOver();
			}
		}
	
	}
	
	return 0;
}
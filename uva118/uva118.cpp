#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Robot{
private:
	vector <int> Danger_X;
	vector <int> Danger_Y;
	vector <char> Danger_Face;
	int start_X,start_Y;
	int X,Y;
	char face;
public:
	void Set(int x,int y){
		start_X=x;
		start_Y=y;
	}
	//
	void Position(int x,int y,char k){
		X=x;
		Y=y;
		face=k;
	}
	//
	void Turn_Right(){
		if(face=='N'){
			face='E';
		}
		else if(face=='E'){
			face='S';
		}
		else if(face=='S'){
			face='W';
		}
		else if(face=='W'){
			face='N';
		}
	}
	//
	void Turn_Left(){
		if(face=='N'){
			face='W';
		}
		else if(face=='E'){
			face='N';
		}
		else if(face=='S'){
			face='E';
		}
		else if(face=='W'){
			face='S';
		}
	}
	//
	int Go(){
		int check;
		if(face=='N'){
			check=Check();
			if(check!=1){
				Y=Y+1;
				if(Y>start_Y){
					Y=Y-1;
					Danger();
					return 1;
				}
			}	
		}
		else if(face=='E'){
			check=Check();
			if(check!=1){
				X=X+1;
				if(X>start_X){
					X=X-1;
					Danger();
					return 1;
				}
				
			}
			
		}
		else if(face=='S'){
			check=Check();
			if(check!=1){
				Y=Y-1;
				if(Y<0){
					Y=Y+1;
					Danger();
					return 1;
				}
			}
			
		}
		else if(face=='W'){
			check=Check();
			if(check!=1){
				X=X-1;
				if(X<0){
					X=X+1;
					Danger();
					return 1;
				}
			}
		}

		return 0;
	}
	//
	void Danger(){
		Danger_X.push_back(X);
		Danger_Y.push_back(Y);
		Danger_Face.push_back(face);
		if(X==0 && Y==0){
			if(face=='W'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('S');
			}
			else if(face=='S'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('W');
			}
		}
		if(X==start_X && Y==0){
			if(face=='E'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('S');
			}
			else if(face=='S'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('E');
			}
		}
		if(X==0 && Y==start_Y){
			if(face=='W'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('N');
			}
			else if(face=='N'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('W');
			}
		}
		if(X==start_X && Y==start_Y){
			if(face=='N'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('E');
			}
			else if(face=='E'){
				Danger_X.push_back(X);
				Danger_Y.push_back(Y);
				Danger_Face.push_back('N');
			}
		}
	}
	//
	int Check(){
		int size,i;
		size=Danger_X.size();
		for(i=0;i<size;i=i+1){
			if(X==Danger_X[i] && Y==Danger_Y[i] && face==Danger_Face[i])
				return 1;
		}
		return 0;
	}
	//
	void Output(int k){
		printf("%d %d %c",X,Y,face);
		if(k==1)
			cout << " LOST";
		cout << endl;
	}

};

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	Robot RB;
	string action;
	int x,y,k;
	int Max_X,Max_Y;
	int size,check,i;
	
	cin >> Max_X >> Max_Y ;
	RB.Set(Max_X,Max_Y);

	while( scanf("%d %d %c",&x,&y,&k) != EOF ){
		check=0;
		RB.Position(x,y,k);
		cin >> action;
		size=action.size();
		for(i=0;i<size;i=i+1){
			if(action[i]=='L'){
				RB.Turn_Left();
			}
			if(action[i]=='R'){
				RB.Turn_Right();
			}
			if(action[i]=='F'){
				check=RB.Go();
				if(check==1)
					break;
			}
		}

		RB.Output(check);
	}

	return 0;
}

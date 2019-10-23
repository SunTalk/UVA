#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

struct cube{
	char color[6];
}A,B;

void clockwise(){
	char tmp = B.color[4];
	B.color[4] = B.color[2];
	B.color[2] = B.color[1];
	B.color[1] = B.color[3];
	B.color[3] = tmp;
}
void forword(){
	char tmp = B.color[5];
	B.color[5] = B.color[4];
	B.color[4] = B.color[0];
	B.color[0] = B.color[1];
	B.color[1] = tmp;
}
void turnRight(){
	char tmp = B.color[3];
	B.color[3] = B.color[0];
	B.color[0] = B.color[2];
	B.color[2] = B.color[5];
	B.color[5] = tmp;
}

bool cmp(){
	for(int i = 0; i < 6 ; i++ )
		if( A.color[i] != B.color[i] )
			return false;
	return true;
}

int main(int argc, char const *argv[])
{

	string str;

	while( cin >> str ){

		for(int i = 0 ; i < 6 ; i++ ){
			A.color[i] = str[i];
			B.color[i] = str[i+6];
		}

		bool ans = false;

		for(int i = 0 ; i < 4 ; i++ ){
			for(int j = 0 ; j < 4 ; j++ ){
				if( cmp() )
					ans = true;
				clockwise();
			}
			forword();
		}

		for(int i = 0 ; i < 4 ; i++ ){
			for(int j = 0 ; j < 4 ; j++ ){
				if( cmp() )
					ans = true;
				clockwise();
			}
			turnRight();
		}

		cout << (ans?"TRUE":"FALSE") << endl;

	}

	return 0;
}
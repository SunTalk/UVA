#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;
bool seat[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1} 
};
string show[5];

void display(int siz, string num){
	
	show[0] = "";
	for(int i = 0 ; i < num.size() ; i++ ){
		show[0] += " ";
		for(int j = 0 ; j < siz ; j++ )
			show[0] += seat[(num[i]-'0')][0] ? "-":" ";
		show[0] += " ";
		show[0] += i==num.size()-1 ? "":" ";
	}
	
	show[1] = "";
	for(int i = 0 ; i < num.size() ; i++ ){
		show[1] += seat[(num[i]-'0')][1] ? "|":" ";
		for(int j = 0 ; j < siz ; j++ )
			show[1] += " ";
		show[1] += seat[(num[i]-'0')][2] ? "|":" ";
		show[1] += i==num.size()-1 ? "":" ";
	}

	show[2] = "";
	for(int i = 0 ; i < num.size() ; i++ ){
		show[2] += " ";
		for(int j = 0 ; j < siz ; j++ )
			show[2] += seat[(num[i]-'0')][3] ? "-":" ";
		show[2] += " ";
		show[2] += i==num.size()-1 ? "":" ";
	}

	show[3] = "";
	for(int i = 0 ; i < num.size() ; i++ ){
		show[3] += seat[(num[i]-'0')][4] ? "|":" ";
		for(int j = 0 ; j < siz ; j++ )
			show[3] += " ";
		show[3] += seat[(num[i]-'0')][5] ? "|":" ";
		show[3] += i==num.size()-1 ? "":" ";
	}

	show[4] = "";
	for(int i = 0 ; i < num.size() ; i++ ){
		show[4] += " ";
		for(int j = 0 ; j < siz ; j++ )
			show[4] += seat[(num[i]-'0')][6] ? "-":" ";
		show[4] += " ";
		show[4] += i==num.size()-1 ? "":" ";
	}

	cout << show[0] << endl;
	for(int i = 0 ; i < siz ; i++ )
		cout << show[1] << endl;
	cout << show[2] << endl;
	for(int i = 0 ; i < siz ; i++ )
		cout << show[3] << endl;
	cout << show[4] << endl;
	cout << endl;
	
}

int main(int argc, char const *argv[])
{

	int siz;
	string num;
	while( cin >> siz >> num && siz )
		display(siz,num);

	return 0;
}
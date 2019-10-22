#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

struct card{
	string name;
	int next;
};

int changeNum(char k){
	if( k == 'A' )
		return 1;
	if( k == 'T' )
		return 10;
	if( k == 'J')
		return 11;
	if( k == 'Q' )
		return 12;
	if( k == 'K')
		return 13;
	else
		return (k-'0');
}

stack <card> CLOCK[20];

int main(int argc, char const *argv[])
{
	string str;
	card C;
	stack <card> pile;

	while( cin >> str && str != "#" ){
		
		for(int i = 0 ; i < 20 ; i++ )
			while( !CLOCK[i].empty() )
				CLOCK[i].pop();
		while( !pile.empty() )
			pile.pop();
		C.name = str;
		C.next = changeNum(str[0]);
		pile.push(C);

		for(int i = 0 ; i < 51 ; i++ ){
			cin >> str;
			C.name = str;
			C.next = changeNum(str[0]);
			pile.push(C);
		}

		for(int i = 0 ; i < 4 ; i++ ){
			for(int j = 1 ; j <= 13 ; j++ ){
				C = pile.top();
				pile.pop();
				CLOCK[j].push(C);
			}
		}

		int ans = 0;
		int now = 13;

		while( !CLOCK[now].empty() ){
			C = CLOCK[now].top();
			CLOCK[now].pop();
			ans++;
			now = C.next;
		}

		printf("%02d,",ans);
		cout << C.name << endl;

	}

	return 0;
}
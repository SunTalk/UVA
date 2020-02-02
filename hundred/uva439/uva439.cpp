#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

typedef long long LL;

const int dir[8][2] = {
	{-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}, 
	{ 2,  1}, { 1,  2}, {-1,  2}, {-2,  1}
};

struct knight{
	int x,y;
	knight() = default;
	knight(int i,int j){
		x = i,y = j;
	};
	
	knight move(int k){
		return knight(x+dir[k][0],y+dir[k][1]);
	}

	bool illegal(){
		if( x < 1 || x > 8 || y < 1 || y > 8 )
			return true;
		return false;
	}

};

int step[10][10];

int BFS(knight start, knight end){

	memset(step,0,sizeof(step));
	queue <knight> Q;
	Q.push(start);

	knight cur,nxt;
	while( !Q.empty() ){
		cur = Q.front();
		Q.pop();

		if( cur.x == end.x && cur.y == end.y )
			break;

		for(int i = 0 ; i < 8 ; i++ ){
			nxt = cur.move(i);
			if( nxt.illegal() )
				continue;
			if( step[nxt.x][nxt.y] == 0 ){
				step[nxt.x][nxt.y] = step[cur.x][cur.y]+1;
				Q.push(nxt);
			}
		}

	}

	return step[end.x][end.y];

}

int main(int argc, char const *argv[])
{

	string A,B;
	while( cin >> A >> B ){
		knight start(A[0]-'a'+1,A[1]-'0');
		knight end(B[0]-'a'+1,B[1]-'0');
		cout << "To get from " << A 
			 << " to " << B 
			 << " takes " << BFS(start,end) 
			 << " knight moves." << endl;
	}

	return 0;
}
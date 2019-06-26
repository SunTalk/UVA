#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "221"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct House{
	int X,Y,W,H,ID;
	bool operator<(const House& rhs ){
		if( X == rhs.X )
			return Y < rhs.Y;
		return X < rhs.X;
	};
};

vector <House> MAP;
vector <House> tmp;
bool visible(House k){
	tmp.clear();
	for(int i = 0 ; i < MAP.size() ; i++ ){
		if( MAP[i].Y >= k.Y )
			continue;
		if( MAP[i].X >= k.X + k.W || MAP[i].X + MAP[i].W <= k.X )
			continue;
		if( MAP[i].H < k.H )
			continue;
		tmp.push_back(MAP[i]);
	}
	if( !tmp.size() )
		return true;
	sort(tmp.begin(), tmp.end());
	int check = k.X;
	for(int i = 0 ; i < tmp.size() ; i++ ){
		if( tmp[i].X > check )
			return true;
		check = max(check, tmp[i].X + tmp[i].W);
	}
	if( check < k.X + k.W )
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int x,y,w,d,h;
	vector <int> ans;
	int Case = 0;

	while( ~scanf("%d",&num) && num ){

		MAP.clear();
		ans.clear();
		for(int i = 0 ; i < num ; i++ ){
			scanf("%d %d %d %d %d",&x,&y,&w,&d,&h);
			MAP.push_back({x,y,w,h,i+1});
		}

		sort(MAP.begin(), MAP.end());

		for(int i = 0 ; i < num ; i++ ){
			if( visible(MAP[i]) )
				ans.push_back(MAP[i].ID);
		}

		if( Case )
			printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++Case );
		for(int i = 0 ; i < ans.size() ; i++ )
			printf("%d%c",ans[i], ( i == ans.size()-1 ? '\n':' ') );

	}

	return 0;
}
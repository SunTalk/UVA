#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100
#define INF 0x3f3f3f3f
#define DEVIATION 0.00000005

struct surface{
	int w,h;
	void init(int a, int b){
		w = min(a,b);
		h = max(a,b);
	};
	bool operator<(surface &rhs){
		if( w == rhs.w ) return h < rhs.h;
		return w < rhs.w;
	};
}S[10];

bool isBox(){
	sort(&S[0],&S[6]);
	if( !(S[0].w == S[1].w && S[0].h == S[1].h && 
			S[2].w == S[3].w && S[2].h == S[3].h &&
			S[4].w == S[5].w && S[4].h == S[5].h))
		return false;
	if( !(S[0].w == S[2].w && 
			S[4].w == min(S[0].h,S[2].h) &&
			S[4].h == max(S[0].h,S[2].h)))
		return false;
	return true;
}

int main(int argc, char const *argv[])
{

	int w,h;
	while( ~scanf("%d %d",&w,&h) ){

		S[0].init(w,h);
		for(int i = 1 ; i < 6 ; i++ ){
			scanf("%d %d",&w,&h);
			S[i].init(w,h);
		}

		if( isBox() ) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");

	}


	return 0;
}
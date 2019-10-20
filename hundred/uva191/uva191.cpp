#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

struct Point{
	double x,y;
};
struct Line {
	double ax,ay,bx,by;
	void init(Point A, Point B){
		ax = A.x,ay = A.y;
		bx = B.x,by = B.y;
	}
};
double cross(Line K, double a, double b) {
	double cross1 = (a - K.ax)*(K.by - K.ay);
	double cross2 = (b - K.ay)*(K.bx - K.ax);
	return (cross1 - cross2);
}
bool intersection(Line A, Line B){
	//快速排斥實驗
	if ( max(A.ax,A.bx) < min(B.ax,B.bx) ||
		 max(A.ay,A.by) < min(B.ay,B.by) ||
		 max(B.ax,B.bx) < min(A.ax,A.bx) ||
		 max(B.ay,B.by) < min(A.ay,A.by) ){
		return false;
	}
	//跨立實驗
	if ( cross(B,A.ax,A.ay)*cross(B,A.bx,A.by) > 0 ||
		 cross(A,B.ax,B.ay)*cross(A,B.bx,B.by) > 0 ){
		return false;
	}
	return true;
}

bool in(Point k, Point a, Point b){
	Point lt,rd;
	lt.x = min(a.x,b.x), lt.y = max(a.y,b.y);
	rd.x = max(a.x,b.x), rd.y = min(a.y,b.y);
	return (lt.x <= k.x)&&(lt.y >= k.y)&&(rd.x >= k.x)&&(rd.y <= k.y);
}

int main(int argc, char const *argv[])
{

	int kase;
	scanf("%d",&kase);
	Line slash;
	Line L,R,T,D;
	Point LT,LD,RT,RD;
	Point SS,SE;

	while( kase-- ){

		scanf("%lf %lf %lf %lf",&SS.x, &SS.y, &SE.x, &SE.y);
		slash.init(SS,SE);
		scanf("%lf %lf %lf %lf",&LT.x, &LT.y, &RD.x, &RD.y);
		LD.x = LT.x, LD.y = RD.y;
		RT.x = RD.x, RT.y = LT.y;
		L.init(LD,LT);
		R.init(RT,RD);
		T.init(LT,RT);
		D.init(LD,RD);

		if( in(SS,LT,RD) || in(SE,LT,RD) )
			printf("T\n");
		else if( intersection(slash,L) ||
				 intersection(slash,R) ||
				 intersection(slash,T) ||
				 intersection(slash,D) ) printf("T\n");
		else
			printf("F\n");

	}

	return 0;
}
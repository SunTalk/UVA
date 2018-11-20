#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "10237"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int number,bis_size,ans;
int bishop[35][35];
int Left[70],Right[70];
void Bishops(int x,int y,int num){

	if( y == bis_size ){
		Bishops(x+1,0,num);
		return;
	}

	if( num == number ){
		ans++;
		return;
	}

	for( int i = x ; i < bis_size ; i++ ){
		for( int j = y ; j < bis_size ; j++ ){
			int left,right;
			left = j - i + bis_size-1;
			right = i + j;
			if( !Left[left] && !Right[right] ){
				Left[left] = Right[right] = 1;
				Bishops(i,j+1,num+1);
				Left[left] = Right[right] = 0;
			}
		}
	}

}


int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	while( ~scanf("%d %d",&bis_size,&number) ){

		if( !bis_size && !number )
			break;

		ans = 0;
		memset(bishop,0,sizeof(bishop));
		memset(Left,0,sizeof(Left));
		memset(Right,0,sizeof(Right));
		Bishops(0,0,0);
		printf("%d\n",ans );
	}

	return 0;
}
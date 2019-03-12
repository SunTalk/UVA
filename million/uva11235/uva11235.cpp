#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "11235"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 100000

int table[MAX*4];
int number[MAX+5];
int Left[MAX+5];
int Right[MAX+5];
int ans;

void build_tree(int Tree[MAX*4],int Need[MAX] ,int L,int R,int seat){//0 n 1
	if( L == R )
		Tree[seat]=Need[L];
	else{
		build_tree( Tree , Need , L , (L+R)/2 , seat*2 );
		build_tree( Tree , Need , (L+R)/2+1 , R , seat*2+1 );

		if( Tree[seat*2] > Tree[seat*2+1] )
			Tree[seat] = Tree[seat*2];
		else
			Tree[seat] = Tree[seat*2+1];
	}
}

void find_tree(int L,int R,int target_L,int target_R,int seat){
	
	if( R < target_L || L > target_R );
	else if( L >= target_L && R <= target_R ){
		ans = max(ans,table[seat]);
	}
	else{
		find_tree( L , (L+R)/2 , target_L ,target_R , seat*2 );
		find_tree( (L+R)/2+1 , R , target_L ,target_R , seat*2+1 );
	}

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int length,times,i;
	int check,tmp,j;
	int one,two;
	while( ~scanf("%d",&length) && length ){
		scanf("%d",&times);
		memset(table,0,sizeof(table));
		memset(number,0,sizeof(number));
		memset(Left,0,sizeof(Left));
		memset(Right,0,sizeof(Right));

		check = 0;
		scanf("%d",&number[0]);
		tmp = 1;
		bool fuck = false;
		for( i = 1 ; i < length ; i++ ){
			scanf("%d",&number[i]);
			if( number[i] == number[i-1] ){
				tmp++;
				fuck = false;
			}
			else{
				for( j = check ; j < i ; j++ ){
					number[j] = tmp;
					Left[j] = check;
					Right[j] = i-1;
				}
				tmp = 1;
				check = i;
				if( i != length-1 )
					fuck = true;
				else
					fuck = false;
			}
		}
		if(fuck==false)
			for( j = check ; j < i ; j++ ){
				number[j] = tmp;
				Left[j] = check;
				Right[j] = i-1;
			}

		build_tree(table,number,0,length-1,1);

		while( times-- ){
			scanf("%d %d",&one,&two);
			ans = 0;
			one--;
			two--;

			if( Left[one] == Left[two] && Right[one] == Right[two] ){
				ans = two - one + 1;
			}
			else{
				if( one > Left[one] ){
					ans = Right[one] - one +1;
					one = Right[one] + 1;
				}
				if( two < Right[two] ){
					ans = max(ans, two - Left[two] + 1 );
					two = Left[two] - 1;
				}
				if( one < two ){
					find_tree(0,length-1,one,two,1);
				}
			}
			printf("%d\n",ans );
		}

	}
	
	return 0;
}
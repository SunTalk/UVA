#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1152"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define Max_size 10000005

int HashNumber(int k){
	return abs(k) % Max_size;
}

struct HashTable{
	HashTable(){
		data = INT_MAX;
		next = NULL;
	}
	int data;
	HashTable *next;
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int A[4005], B[4005], C[4005], D[4005];
	int times, number, i, j;
	int seat,mix;

	scanf("%d",&times);

	while( times-- ){

		HashTable *del, *tmp, *table[Max_size];
		for( i = 0 ; i < Max_size ; i++ )
			table[i] = new HashTable;

		scanf("%d",&number);
		for( i = 0 ; i < number ; i++ )
			scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i] );

		for( i = 0 ; i < number ; i++ ){
			for( j = 0 ; j < number ; j++ ){
				mix = A[i] + B[j];
				seat = HashNumber(mix);
				tmp = table[seat];
				while( tmp->next != NULL )
					tmp = tmp->next;
				tmp->data = mix;
				HashTable *Newnode;
				Newnode = new HashTable;
				tmp->next = Newnode;
			}
		}

		int ans = 0;
		for( i = 0 ; i < number ; i++ ){
			for( j = 0 ; j < number ; j++ ){
				mix = ( C[i] + D[j] ) * (-1);
				seat = HashNumber(mix);
				tmp = table[seat];
				while( tmp->data != INT_MAX ){
					if( tmp->data == mix )
						ans++;
					tmp = tmp->next;
				}
			}
		}

		printf("%d\n",ans );
		if( times != 0 )
			printf("\n");

		for( i = 0 ; i < Max_size ; i++ ){
			tmp = table[i];
			while( tmp->next != NULL ){
				del = tmp;
				tmp = tmp->next;
				delete del;
			}
			delete tmp;
		}

	}



	return 0;
}
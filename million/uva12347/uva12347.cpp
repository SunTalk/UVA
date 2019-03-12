#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "12347"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct node{
	node(){
		data = -1;
		left = right = NULL;
	}
	int data;
	node* left;
	node* right;
};

node *head = new node;

void insert(node* tmp,int num){
	if( tmp->data == -1 ){
		tmp->data = num;
		return;
	}
	
	if( num < tmp->data ){
		if( tmp->left == NULL ){
			node *NewNode = new node;
			tmp->left = NewNode;
			insert(NewNode,num);
		}
		else
			insert(tmp->left,num);
	}
	else{
		if( tmp->right == NULL ){
			node *NewNode = new node;
			tmp->right = NewNode;
			insert(NewNode,num);
		}
		else
			insert(tmp->right,num);
	}

}

void post(node* tmp){

	if( tmp->left != NULL )
		post(tmp->left);
	if( tmp->right != NULL )
		post(tmp->right);
	printf("%d\n",tmp->data );

}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int num;
	while( ~scanf("%d",&num) ){
		insert(head,num);
	}
	post(head);

	return 0;
}
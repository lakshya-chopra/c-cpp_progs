#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
	int val;
	struct node * left;
	struct node * right;
}bTree;

const int sizeOfTree = sizeof(bTree);

bTree * root = NULL;

bTree * createNode(int value){

	bTree * node = (bTree*)(malloc(sizeOfTree));
	node->val = value;

	node->left = NULL;
	node->right = NULL;
	return node;
}

void printTabs(int tabs){
	for(int i =0;i<tabs;i++){
		printf("\t");
	}
}


void printTree(bTree* root,int tabs){
	if(root == NULL){
		printTabs(tabs);
		printf("--empty--!");
		return;
	}
	else{
		printTabs(tabs);

		printf("%d\n ",root->val); //<- : left subtree, ->: right subtree

		printTabs(tabs+1);
		printf("left: \n");
		
		printTree(root->left,tabs+1);
		
		printf("\n");
		printTabs(tabs+1);
		printf("right: \n");
		
		printTree(root->right,tabs+1);


	}
}

int main(){

	bTree *n1 = createNode(1);
	bTree * n2 = createNode(2);
	bTree *n3 = createNode(3);
	bTree *n4 = createNode(4);
	bTree * n5 = createNode(5);
	bTree *n6 = createNode(6);
	bTree *n7 = createNode(7);

	n1->left = n2;
	n1->right = n3;

	n2->left = n4;
	n2->right = n5;

	n3->left = n6;
	n3->right = n7;

	root = n1;

	printf("\n");
	printTree(root,0);


	free(n1);
	free(n2);

	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);



	return 0;
}
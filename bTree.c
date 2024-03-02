#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
	int value;
	struct node * left;
	struct node * right;
}bTree;

/* In a binary tree, operations like insertion, deletion, traversal take O(log(n)) time complexity if the tree is balanced & O(n) if unbalanced. */

const int sizeOfTree = sizeof(bTree);

bTree * root = NULL;

bTree * createNode(int value){

	bTree * node = (bTree*)(malloc(sizeOfTree));
	node->value = value;

	node->left = NULL;
	node->right = NULL;
	return node;
}

void printTabs(int tabs){
	for(int i =0;i<tabs;i++){
		printf("\t");
	}
}

void insertNode(bTree** node,int value) {
    if (*node == NULL) {
        *node = createNode(value);
    } else {
        if (value < (*node)->value) {
            insertNode(&((*node)->left),value);
        } else {
            insertNode(&((*node)->right),value);
        }
    }

    //This is a BST, each node can have only 2 child nodes & left side must have a lower value than the parent, and right : greater.
}

void printTree(bTree* root,int tabs){
	if(root == NULL){
		printTabs(tabs);
		printf("--empty--!");
		return;
	}
	else{
		printTabs(tabs);

		printf("%d\n ",root->value); //<- : left subtree, ->: right subtree

		printTabs(tabs+1);
		printf("left: \n");
		
		printTree(root->left,tabs+1);
		
		printf("\n");
		printTabs(tabs+1);
		printf("right: \n");
		
		printTree(root->right,tabs+1);


	}
}

bTree* deleteNode(int value,bTree * root1){

	if (root1 == NULL){
		return NULL;
	}
	else{

		if (root1->value == value){

			//Now, we have to be careful and see that the deletion of root1 doesn't affect any other element.


			if(root1->left == NULL && root1->right == NULL){
				//here we can safely delete

				free(root1);
				root1 = NULL;
				return NULL;
			}
			else if (root1->left == NULL){

				//here we will store the address of the right node and return it & delete the rest.
				bTree * temp = root1->right;
				free(root1);
				root1 = NULL;
				return temp;

			}
			else if(root1->right == NULL){
				bTree * temp = root1->left;
				free(root1);
				root1 = NULL;
				return temp;

			}
			else{
				//neither are null
				// we will check if the value entered is lesser than the root1 or not, if it is, then apply the delete op to left, else right.

				if (value < root1->value){
					root1->left = deleteNode(value,root1->left); //if root1->left is already NULL, then okay, else if it is equal to the value, then delete it and return NULL, 
				}
				else{
					root1->right = deleteNode(value,root1->right);
				}
			}
		}
		else{
			//again check
				if (value < root1->value){
					root1->left = deleteNode(value,root1->left);
				}
				else{
					root1->right = deleteNode(value,root1->right);
				}
		}
		return root1; //if not found!


	}

}


int main(){

/*	bTree *n1 = createNode(1);
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
*/

	root = createNode(50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);
 
	printTree(root,0);

	// deleteNode(20,root);
	// printTree(root,0);

	return 0;
}
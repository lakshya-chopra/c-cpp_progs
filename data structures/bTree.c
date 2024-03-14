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

    /*
	This is a BST, each node can have only 2 child nodes & left side must have a lower value than the parent, and right : greater.
	The right subtree of an internal node must have greater values, and the left subtree of that node must have smaller values.
	*/
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
		
		printTree(root->left,tabs+1); //same as the amount of indentation given to left.
		
		printf("\n");
		printTabs(tabs+1);
		printf("right: \n");
		
		printTree(root->right,tabs+1);


	}
}

int search(bTree* root, int value){

	if(root == NULL){
		return -1;
	}

	//recursive
	if (root->value == value){
		return 1;
	}
	else{
		if(value < root->value){
			return search(root->left,value);
		}
		else{
			return search(root->right,value);
		}
	}
	//if not found:
	return -1;
	

}

bTree* deleteNode(int value,bTree * root){

	if (root == NULL){
		return NULL;
	}
	else{

		if (root->value == value){

			//Now, we have to be careful and see that the deletion of root doesn't affect any other element.


			if(root->left == NULL && root->right == NULL){ //i.e if it is a leaf node.
				//here we can safely delete

				free(root);
				root = NULL;
				return NULL;
			}
			else if (root->left == NULL){

				//here we will store the address of the right node and return it & delete the rest.
				bTree * temp = root;

				root = root->right;

				free(temp);
				temp = NULL;
				return root;

			}
			else if(root->right == NULL){
				bTree * temp = root;

				root = root->left;

				free(temp);
				temp = NULL;
				return root;

			}
			else{
				//neither are null, find the minimum value from the right subtree and then copy it in place of the root and the delete that node with minimum value, also make sure to assign the right subtree of that node to the root.

				bTree *minRightSub;

				bTree* cur = root->right;
				while(cur->left != NULL){
					cur = cur->left;
				}
				minRightSub = cur;

				root->value = minRightSub->value;

				root->right = deleteNode(minRightSub->value,root->right);

				return root;
			}
		}
		else{
			//again check
				if (value < root->value){
					root->left = deleteNode(value,root->left);
				}
				else{
					root->right = deleteNode(value,root->right);
				}
		}
		return root; //if not found!


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

	deleteNode(20,root);
	printf("\n\nModified Binary Tree:\n");
	printTree(root,0);

	int search_int;
	printf("\nenter a value you want to search for: ");

	scanf("%d",&search_int);

	int res = search(root,search_int);
	printf("\nchecking if %d is in the bTREE:\n",search_int);
	if (res == 1){
		printf("yes, exists!\n");
	}
	else{
		printf("no bruder, it isnt there!\n");
	}

	return 0;
}
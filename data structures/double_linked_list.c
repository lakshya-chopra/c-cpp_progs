
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node* next;
	struct node * prev;

}bTree;

struct node * head = NULL; //head : first node.
const int sizeof_node = sizeof(bTree);

bTree* createNode(int val){
	bTree *node = (bTree *)malloc(sizeof_node);

	node->val = val;

	node->next = NULL;
	node->prev = NULL;

	return node;
}
int insertNodeAtEnd(int val){
	
	bTree *node = createNode(val);

	if (head == NULL){
		head = node;
	}
	else{
		bTree *ptr = head;

		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		bTree *prev = ptr;
		ptr->next = node; //ptr is currently at the last element, it's next points to the NULL, inplace of NULL we set the new element


		node->prev = prev;
	}

}
int getLength(bTree *head1){

    if(head1 == NULL){
        return 0;
    }
    else{
        return 1 + getLength(head1->next); // head1->next becomes the new head1.
    }
}

int printAllNodes(){

	if (head == NULL){
		return -1;
	}
	else{
		bTree * ptr = head; 

		while( ptr->next != NULL){
			printf("%d ",ptr->val);
			ptr = ptr->next;
		}
		printf("%d\n", ptr->val); //printing the last node
	}

}

int deleteNodeAt(int position){

	if (position > getLength(head)){
		printf("what are u doing?");
		return 0;
	}
	int i;
	bTree *prev = NULL;
	bTree *cur = head;
	bTree *next = NULL;

	for(i = 1;i<position;i++){

		next = cur->next;
		prev = cur;

		cur = cur->next;

		//cur now at the node that is to be deleted.

	}
	/*ex: pos = 5;
		first iteration -> cur = 2nd
		second iterat -> cur = 3rd
		third iterat -> cur = 4th
		fourth -> cur = 5th (actual position) & prev = 4th

		nodeToBeDel = 5th pos.
		next node = 6th's prev is set to 4th node 

	*/

	bTree * nodeToBeDel = cur;
	prev->next = cur->next;
	(cur->next)->prev = prev;

	free(nodeToBeDel);
	nodeToBeDel = NULL;
}

int insertAtPos(int pos, int val){
	if(pos > getLength(head)){
		insertNodeAtEnd(val);
	}
	else
	{
		int i;
		bTree *prev = NULL;
		bTree *cur = head;
		bTree *next = NULL;

		for(i=1;i<pos;i++)
		{
			next = cur->next;
			prev = cur;

			cur = cur->next; // at the end we'll reach the position where we want to insert the element

		}
		bTree *newNode = createNode(val);
		prev->next = newNode;
		cur->prev = newNode;

		newNode->next = cur;
		newNode->prev = prev;

	}
}

int main(){

	int i;
	int len = 125;

	for(i = 1;i<=len;i++){
		insertNodeAtEnd(i);
	}

	printAllNodes();
	printf("\nLength of the list:  %d\n",getLength(head));

	deleteNodeAt(10);
	printAllNodes();

	insertAtPos(10,200);
	insertAtPos(10,10);
	
	printf("\n");
	printAllNodes();

	printf("\nLength of the list:  %d\n",getLength(head));



	return 0;
}

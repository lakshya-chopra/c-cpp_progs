#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int val;
	struct node* addr;

}lL;

struct node * head = NULL; //head === first node.
const int sizeof_node = sizeof(lL);

/*VARIABLES*/
/*
1.head
2. node
3. head stores the address of the first node, accessing head gives us access to the first node.
4. ptr is another pointer variable which stores the address at head variable (node) and not the address of head, hence ** not used.
*/


/*functions */

lL* createNode(int val)
{

	lL* node = (lL*)malloc(sizeof_node); /*first obtain the address to a memory block storing values of lL type.*/

	(node)->val = val; //equivalent to *(node).val = val;

	(node)->addr = NULL;
	
	return node;

}
int insertNode(int val){

	/*this function first creates a node and then add it to the last element*/
	
	lL* node = createNode(val);
	if (head == NULL){ //if no element currently
		head = node;
	}
	else{

		lL* ptr = head; //ptr stores the address of the first node.

		while(ptr->addr != NULL){
			ptr = ptr->addr;
		}
		//if the addr == NULL, i.e. we reach the end of the linked list
		ptr->addr = node;
	}


	return 0;

}
int printAllNodes(){

	if (head == NULL){
		return -1;
	}
	else{
		lL* ptr = head; 

		while( ptr->addr != NULL){
			printf("%d ",ptr->val);
			ptr = ptr->addr;
		}
		printf("%d\n", ptr->val); //printing the last node
	}
}

int insertNodeAtStart(int val){

	lL* node = createNode(val);


	if (head == NULL){
		head = node;
	}
	else{
	
		(node)->addr = head; //address of initial first element is now stored in the new first element
		head = node;
	}
}

int main(){

	int i = 0;
	const int length = 25;

	for ( i = 0; i< length;i++){
		insertNode(i);
	}
	printf("Task Complete!\n");
	printAllNodes(length);

	printf("\n");

	insertNodeAtStart(25);
	printAllNodes(length + 1);

	return 0;
}
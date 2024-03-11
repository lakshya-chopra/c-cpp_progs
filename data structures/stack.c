#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdint.h>

typedef struct Stack{

	// we could've also used LinkedList.

	int top;
	uint32_t size;

	int* arr;

}Stack;


Stack* createStack(uint32_t size){

	Stack * stack = (Stack *)(malloc(sizeof(Stack)));

	stack->size = size;
	stack->top = -1;

	stack->arr = (int *)malloc(sizeof(int)*size); //creates a free space of n (i.e. size) integer elements

	return stack;
}

bool isFull(Stack *stack){
	if(stack->size == stack->top + 1){
		return true;
	}
	else{
		return false;
	}
}
	
bool isEmpty(Stack *stack){
	if(stack->top == -1){
		return true;
	}
	else{
		return false;
	}
}

void push(int value,Stack *stack){
		
		if (isFull(stack)){ 
			printf("Stack is full, try popping out some elements!\n");
		}
		else{
		stack->arr[++stack->top] = value;
		}
		return;

}
int pop(Stack *stack){

	if(!isEmpty(stack)){
		int c = stack->arr[stack->top];
		stack->top--;

		return c;
	}
	else{
		printf("%s Empty stack?!?! What do you expect?\n");
	}
}

int peek(Stack *stack){
	if(!isEmpty(stack)){
		return stack->arr[stack->top];
	}
	else{
		printf("%s you joking?\n");
		return -1;
	}
}
void printStack(Stack *stack){

	if(!isEmpty(stack)){
		printf("\n");
		for(int i = 0;i<=stack->top;i++){
			printf("%d index : %d \n",i,stack->arr[i]);

		}
	}
	else{
		printf("%s just stop!");
	}
	return;
}

int main(){
	uint32_t len = 11;
	Stack * stack = createStack(len);

	int k;
	for(k=0;k<=10;k++){
		push(k,stack);
	}

	printStack(stack);

	push(11,stack);

	printf("topmost value: %d \n",peek(stack));
	pop(stack);

	printStack(stack);

	return 0;
}
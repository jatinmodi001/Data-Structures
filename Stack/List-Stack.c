#include<stdio.h>
#include<stdlib.h>

typedef struct stack            // Structure of Stack
{
    int data;
    struct stack* prev;
}Stack;

void push(Stack **h,int d)      // Push elements into the Stack
{
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    temp->data = d;
    temp->prev = *h;
    *h = temp;
}

void pop(Stack **h)          // Pop the top element of Stack
{
    if(*h != NULL)
    {
        Stack *temp = (Stack*)malloc(sizeof(Stack));
        temp->data = (*h)->data;
        temp->prev = (*h);
        *h = (*h)->prev;
        free(temp);
    }
}

int peek(Stack *h)              // Returns top element of Stack
{
    if(h != NULL)
    {
        return (h)->data;
    }
}

int isEmpty(Stack *h)             // Checks if Stack is empty or not
{
	if(h == NULL)
	{
		return 1; 
	}
	return 0;
}

int main()
{
    Stack *st = NULL;           // Declaring an empty Stack

    push(&st,10);               // Inserting elements
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    while(!isEmpty(st))
    {
        printf("%d ",peek(st));              // prints :- 50 40 30 20 10 
        pop(&st);
    }
}

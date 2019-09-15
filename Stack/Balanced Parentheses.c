#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack				// Stack Structure
{
    char data;
    struct stack* prev;
}Stack;	

void push(Stack **h,char d)			// Push element at the top
{
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    temp->data = d;
    temp->prev = *h;
    *h = temp;
}

char pop(Stack **h)					// pop element from the top
{
    if(*h)
    {
        Stack *temp = (Stack*)malloc(sizeof(Stack));
        temp->data = (*h) ->data;
        char x = temp->data;
        temp->prev = (*h);
        *h = (*h)->prev;
        free(temp);
        return x;
    }
}

char peek(Stack **h)			// Returns the top element
{
    if(*h)
    {
        return (*h)->data;
    }
}

int isEmpty(Stack *h)			// Returns 1 if stack is empty, else 0
{
	if(h == NULL)
		return 1;
	return 0;
}

int main()
{
    Stack *top=NULL;			// Defining an empty Stack
    
    char arr[100];
    scanf("%s",arr);			// Scanning string
    
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='{' || arr[i]=='[' || arr[i]=='(')
        {
            push(&top,arr[i]);
        }
        else
        {
            char ch = peek(&top);
            if((ch == '{' && arr[i] == '}') || (ch == '[' && arr[i] == ']') || (ch == '(' && arr[i] == ')') )
            {
                pop(&top);
            }
            else
            {
                printf("Invalid\n");
                return 0;
            }
        }
    }
    
    if(isEmpty(top))					// If stack is empty
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}

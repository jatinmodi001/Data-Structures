#include<stdio.h>
#include<stdlib.h>
typedef struct node												// structure of linked list
{
	int data;
	struct node *next;
}Linklist;

void addElement(Linklist **h,int d)								// Function for adding elements in linked list in the end
{
	Linklist *t = (Linklist*)malloc(sizeof(Linklist));
	t->data = d;
	t->next = NULL;
	if(*h == NULL)												// if list is empty then changing head of list.
	{
		*h = t;
	}
	else
	{
		Linklist * curr = *h;
		while(curr->next)
			curr = curr->next;
		curr->next = t;
	}
}

/* 	Below function will remove all the duplicates
	of element in a sorted link list.
	for e.g :- Input :- 1,1,1,2,2,3,4
			   Ouput :- 1,2,3,4
*/

void RemoveDuplicates(Linklist **h)
{
	Linklist *temp = *h;
	while(temp && temp->next)
	{
		if(temp->data == temp->next->data)
		{
			Linklist *a = temp->next;
			temp->next = temp->next->next;
			free(a);
			continue;
		}
		temp = temp->next;
	}
}

int main()
{
	Linklist *head = NULL;												// Declaring an empty Linked List
	
	int n;
	scanf("%d",&n);														// scanning the size of linked list
	
	for(int i=0;i<n;i++)												
	{
		int a;
		scanf("%d",&a);													// scanning elements of linked list
		addElement(&head,a);
	}
	
	RemoveDuplicates(&head);
	
	for(Linklist *h = head;h!=NULL;h=h->next)							// printing the whole linked list
	{
		printf("%d  ",h->data);
	}
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct node												// structure of linked list
{
	int data;
	struct node *next;
}Linklist;

void addElement(Linklist **h,int d)								// Function for adding elements in linked list in the end.
{
	Linklist *t = (Linklist*)malloc(sizeof(Linklist));
	t->data = d;
	t->next = NULL;
	if(*h == NULL)
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

/*	Below Function will remove all the
	elements which occur more the once
	in a sorted linked list.
	for e.g if Input :- 1,1,1,2,3
		  then Output :- 2,3
*/

void Unique(Linklist **h)
{
	Linklist *dummy = (Linklist *)malloc(sizeof(Linklist));
	dummy->next = *h;
	*h = dummy;
	Linklist *itr1 = *h;
	Linklist *itr2 = *h;
	while(itr2)
	{
		if(itr2->next && (itr1->next->data == itr2->next->data))
		{
			itr2 = itr2->next;
		}
		else if(itr1->next == itr2)
		{
			itr1 = itr1->next;
		}
		else
		{
			itr1->next = itr2->next;
			itr2 = itr2->next;
		}
	}
	
	*h = dummy->next;
}

int main()
{
	Linklist *head = NULL;					// Declaring an empty linked list
	
	int n;
	scanf("%d",&n);							// scanning the size of linked list
	
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);						// scanning elements of linked list
		addElement(&head,a);	
	}
	
	Unique(&head);
	
	for(Linklist *h = head;h!=NULL;h=h->next)				// printing the whole linked list
	{
		printf("%d  ",h->data);
	}
}

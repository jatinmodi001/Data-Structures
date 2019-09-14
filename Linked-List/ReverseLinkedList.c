#include<stdio.h>
#include<stdlib.h>
struct node								// structure of linked list
{
	int data;
	struct node *next;
};
void Reverse(struct node **h)
{
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	while(*h != NULL)
	{
		temp2 = (*h)->next;
		(*h)->next = temp1;
		temp1 = *h;
		*h = temp2;
	}
	*h = temp1;
}
void addElement(struct node**h,int a)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	if(*h == NULL)										// if list is empty then changing the head
	{
		*h = temp;
	}
	else
	{
		struct node *c = *h;
		while(c->next)
		{
			c = c->next;
		}
		c->next = temp;
	}
}
int main()
{
	struct node *head = NULL;						// declaring an empty linked list
	
	int n;
	scanf("%d",&n);									// scanning the size of linked list
	
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		addElement(&head,a);						// adding elements in linked list (in the end)
	}
	
	Reverse(&head);
	
	for(struct node *h = head ; h!=NULL;h=h->next)				// printing the whole linked list
	{
		printf("%d ",h->data);										
	}
		
	return 0;
}

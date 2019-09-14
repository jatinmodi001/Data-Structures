// Include these library files whenever you use this file.
/*

#include<stdio.h>
#include<stdlib.h>
*/

typedef struct node								// structure of linkedlist
{
	int data;
	struct node *next;
}SinglyLinkedList;
/*--------------------------------Inserting Element in the begining of LinkedList--------------------------------------*/

void insertAtBeg(SinglyLinkedList **h,int d)
{
	SinglyLinkedList *temp = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	temp->data = d;
	temp->next = *h;
	*h = temp;
}

/*----------------------------------Inserting Element at the end of LinkedList-----------------------------------------*/

void insertAtEnd(SinglyLinkedList **h,int d)
{
	SinglyLinkedList *temp = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
	temp->data = d;
	temp->next = NULL;
	if(*h == NULL)								// if list is empty
		*h = temp;
	else
	{
		SinglyLinkedList *a = *h;
		while(a->next != NULL)
			a = a->next;
		a->next = temp;
	}
}

/*-----------------------------------Deleting from begining of linked list----------------------------------------------*/

void deleteFromBeg(struct node **h)
{
	if(*h == NULL)						
		return ;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = (*h)->data;
	temp->next = (*h)->next;
	*h = (*h)->next;
	free(temp);
}

/*-----------------------------------Deleting from ending of linked list---------------------------------------------------*/

void deleteFromEnd(struct node **h)
{
	if(*h == NULL)										
		return;
	struct node *dummy = (struct node*)malloc(sizeof(struct node));
	dummy->next = *h;
	*h = dummy;
	struct node *a = *h;
	while(a && a->next && a->next->next)
	{
		a = a->next;
	}
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a->next->data;
	temp->next = a->next->next;
	a->next = NULL;
	free(temp);
	*h = dummy->next;
}
/*--------------------------------Inserting Element at certain position in LinkedList--------------------------------------*/

void insertAtPos(SinglyLinkedList **h,int pos ,int d)
{
	SinglyLinkedList *temp = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	if(pos == 0)
	{
		temp->data = d;
		temp->next = *h;
		*h = temp;
	}
	else
	{
		SinglyLinkedList *a = *h;
		for(int i=0;i<pos-1;i++)
		{
			if(a->next == NULL)
			{
				printf("Invalid Position\n");
				return ;
			}
			a = a->next;
		}
		temp->data = d;
		temp->next = a->next;
		a->next = temp;
	}
}

/*--------------------------------Deleting element from certain position in LinkedList--------------------------------------*/

void deleteFromPos(SinglyLinkedList**h,int pos)
{
	SinglyLinkedList *temp = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	if(pos == 0)
	{
		temp->data = (*h)->data;
		temp->next = (*h)->next;
		*h = (*h)->next;
		free(temp);
	}
	else
	{
		SinglyLinkedList *c = *h;
		for(int i=0;i<pos-1;i++)
		{
			if(!(c->next && c->next->next))
			{
				printf("Invalid Position\n");
				return ;
			}
			c = c->next;
		}
		temp->data = c->next->data;
		temp->next = c->next->next;
		c->next = temp->next;
		free(temp);
	}
}

/*---------------------------------------------Printing of linked list--------------------------------------------*/

void printLinkedList(SinglyLinkedList **head)
{
	printf("[");
	for(SinglyLinkedList *h = *head; h!=NULL ; h = h->next)
	{
		if(h->next)
			printf("%d ,",h->data);
		else
			printf("%d",h->data);
	}
	printf("]");
}


/*----------------------Example code of scanning of linked list-----------------------------

/*
int main()
{
	SinglyLinkedList *head = NULL;
	int n;
	scanf("%d",&n); 					// scanning size;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insertAtEnd(&head,a);
	}
	printLinkedList(&head);						// printing the whole linklist
	return 0;
}
*/

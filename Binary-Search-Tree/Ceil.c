#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}Tree;

Tree* insert_node(Tree* node, int key)		// Inserting node in BST
{
    if(node == NULL)
    {
        Tree *NewNode = (Tree*)malloc(sizeof(Tree));
        NewNode->left = NULL;
        NewNode->right = NULL;
        NewNode->key = key;
        return NewNode;
    }
    if(node->key == key)
    {
        // do nothing
    }
    else if(node->key > key)
        node->left = insert_node(node->left,key);

    else
        node->right = insert_node(node->right,key);

    return node;
}

void insert(Tree **root,int key)
{
    *root = insert_node(*root,key);
}

Tree* CeilBST(Tree *n, int m)		// Returns Ceil of given element
{
	if(n == NULL)
		return NULL;
		
	if(n->key == m)		// if same element found than return it
		return n;
		
	if(n->key < m)		// if less then go right
	{
		return CeilBST(n->right,m);
	}
	
	Tree* temp = CeilBST(n->left,m);		// if large than find if some closer element to m exist
	return temp == NULL ? n : temp;
}

int main()
{
	Tree *bst = NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(&bst,a);
	}
	int f;
	scanf("%d",&f);
	Tree *t = CeilBST(bst,f);
	if(t == NULL)
	{
		printf("Not Exist");
	}
	else
		printf("%d\n",t->key);
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;                    // Value
    struct node *left;
    struct node *right;
    int N;                      // Size of that subtree
}node;

node *newNode(int k)            // creates new node and returns
{
    node *t = (node*)malloc(sizeof(node));
    t->left = NULL;
    t->right = NULL;
    t->key = k;
    t->N = 1;
    return t;
}
int Size(node *n)
{
    return n == NULL ? 0 : n->N;        // Return size of subtree
}
node* Insert(node *n,int k)             // Inserts node in BST and returns root
{
    if(n == NULL)
    {
        return newNode(k);
    }
    else if(n->key > k)
    {
        n->left = Insert(n->left,k);
    }
    else if(n->key < k) 
    {
        n->right = Insert(n->right,k);
    }
    n->N = 1+Size(n->left)+Size(n->right);
    return n;
}

int rank(node *root,int key)
{
    if(root == NULL)                // if not found then return -1
    {
        return -1;
    }
    if(root->key > key)
    {
        return rank(root->left,key);
    }
    if(root->key == key)   
    {
        return Size(root->left);
    }
    int x = rank(root->right,key);      // checks if the node exists of not if not then return -1
    if(x == -1)
        return -1;                
    return (1 + Size(root->left) + x);
}

int main()
{
    int n;
    scanf("%d",&n);
    node *root = NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        root = Insert(root,a);
    }
    int key;
    scanf("%d",&key);
    printf("Rank = %d\n",rank(root,key));
}
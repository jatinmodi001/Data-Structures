#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}Tree;

/*-------------------Inserting Element in Tree---------------*/

Tree* insert_node(Tree* node, int key)
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

/*--------------Searches specific node in Tree---------------*/

int Search_node(Tree *n, int key)
{
    if(n == NULL)
        return 0;

    if(n->key == key)
        return 1;
    
    if(n->key > key)
        return Search_node(n->left,key);

    return Search_node(n->right,key);
}

int Search(Tree *root,int key)
{
    return Search_node(root,key);
}

int getmin(Tree *node)              // Returns minimum value in the Tree.
{
    if(node->left == NULL)
    {
        return node->key;
    }
    return getmin(node->left);
}

int getmax(Tree *node)              // Returns maximum values in the Tree.
{  
    if(node->right == NULL)
        return node->key;

    return getmax(node->right);
}

Tree* del_min(Tree *node)           // Deletes node with minimum value in the Tree.
{
    if(node->left = NULL)
        return node->right;
    
    node->left = del_min(node->left);
    return node;
}

void delmin(Tree **root)            
{
    if(*root == NULL)
        return ;
    
    *root = del_min(*root);
}


Tree *del_max(Tree *node)           // Deletes node with maximum value in the Tree.
{
    if(node->right == NULL)
        return node->left;
    
    node->right = del_max(node->right);
    return node;
}

void delmax(Tree** root)
{
    if(*root == NULL)
        return ;
    
    *root = del_max(*root);
}

Tree* del_Element(Tree* node,int element)       // Deletes node with given value in Tree.
{
    if(node == NULL)
        return node;
    if(node->key == element)
    {
        if(node->left == NULL)
            return node->right;

        else if(node->right == NULL)
            return node->left;

        Tree *itr = node->right;
        while(itr->left->left)
        {
            
            itr = itr->left;
        }
        Tree *temp = itr->left;
        itr->left = NULL;
        return temp;
    }
    else if(node->key > element)
    {
        node->left = del_Element(node->left,element);
    }
    else if(node->key < element)
    {
        node->right = del_Element(node->right,element);
    }
    return node;
}

void delElement(Tree **root,int element)
{
    if(*root == NULL)
        return ;
    
    *root = del_Element(*root,element);
}

int main()
{
    Tree *root = NULL;                  // Declaring

    insert(&root,5);                    // Inserting elements
    insert(&root,3);
    insert(&root,1);
    insert(&root,4);
    insert(&root,6);
    insert(&root,8);
    insert(&root,7);

    printf("%d\n",getmin(root));        // prints 1
    delElement(&root,8);                // deleting 8
    printf("%d\n",getmax(root));        // prints 7
    return 0;

}
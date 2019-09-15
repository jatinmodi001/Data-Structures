#include<stdio.h>
#include<stdlib.h>

int arr[10];            // Globally Declaring a array
int n = 0;              // Declaring size of arrays as 0 because initially array is empty

void swap(int a,int b)
{
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void swim(int i)          // Swims Up
{
    if(i==0)                // if i is 0 than return (Element is at the top of tree)
        return;
    int p = i/2;
    if(arr[p] < arr[i])     // Checking if parent is smaller than its children or not
    {
        swap(p,i);          // swaps parent and children
        swim(p);            // Recursize call for another upper part
    }
}

void sink(int i)
{
    if(i >= n-1)            // if i == last element/size so return 
        return;

    int current = i;
    int left = 2*i;             // Left child of Parent
    int right = 2*i + 1;        // Right child of Parent

    if(left < n && arr[left] > arr[current])        // Checking if the left child is max than parent or not
    {
        current = left;
    }

    if(right < n && arr[right] > arr[current])      // Checking if the right child is max than parent or not
    {
        current = right;
    }

    if(i != current)                // if i changes means the parent is smaller than left or right or from both than swap
    {
        swap(i,current);            // swaping initial i with the changed i
        sink(current);              // Recursive call for another part
    }
}

void insert(int k)          // Inserts items into the tree
{
    arr[n++] = k;
    swim(n-1);        
}

int main()
{
    int size;
    scanf("%d",&size);          // Enter size of Heap Tree

    for(int i=0;i<size;i++)
    {
        int k;
        scanf("%d",&k);
        insert(k);              // Inserting values to Tree
    }
    for(int i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);      // Printing Tree
    }
}
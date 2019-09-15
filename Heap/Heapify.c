#include<stdio.h>

void swap(int a,int b,int arr[])
{
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void sink(int arr[],int i,int n)
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
        swap(i,current,arr);            // swaping initial i with the changed i
        sink(arr,current,n);              // Recursive call for another part
    }
}

void heapify(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)             // Starting loop from the bottom parent of the tree
    {
        sink(arr,i,n);                  // sinking
    }
}

int main()
{
    int n;
    scanf("%d",&n);         // Scanning size of array

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);        // Scanning elements of array
    }

    heapify(arr,n);             // Heapifying array

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);       // Printing array
    }
    
    return 0;
}

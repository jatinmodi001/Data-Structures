# Binary Search Tree
Binary Search Tree, is a node-based binary tree data structure which has the following properties :

* The left subtree of a node contains only nodes with keys lesser than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* The left and right subtree each must also be a binary search tree.
* There must be no duplicate nodes.

![BST image](https://s3-us-west-2.amazonaws.com/tutorials-image/binary+search+tree+traversal.png)

## Working of Binary Search Tree
* The Binary search tree works in a manner where every element that is to be inserted gets sorted then and there itself upon insertion.
* The comparison starts with the root, thereby following the left or right sub-tree depending if the value to be inserted is lesser or greater than root, respectively.
* Thus any value which is to be inserted is compared with the value at the root. Any value less than the root gets inserted in the left child and its children, whereas any value greater than the root gets inserted in the right child and its children.
* Thus all the values get automatically sorted as they’re inserted into the tree.

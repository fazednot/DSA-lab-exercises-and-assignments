Calculate the height of a binary tree with leaf nodes forming a circular doubly linked list
Write an algorithm to compute a binary tree’s height with leaf nodes forming a circular doubly linked list where the leaf node’s left and right pointers will act as a previous and next pointer of the circular doubly linked list, respectively.



We know that the height of a binary tree is the total number of nodes present on the longest path from the root to a leaf node. The idea is to traverse the tree in a postorder fashion and calculate the left and right subtree’s height. The height of a subtree rooted at any node will be one more than the maximum height of its left and right subtree. Recursively apply this property to all tree nodes in a bottom-up manner (postorder fashion) and return the maximum height of the subtree rooted at that node.

For typical binary trees, the left and right children of a leaf node are null pointers. But here, the left and right child of leaf nodes act like the previous and next pointer of the circular doubly linked list. For a node to be a leaf node, check if its left’s right and right’s left are pointing to the node itself.


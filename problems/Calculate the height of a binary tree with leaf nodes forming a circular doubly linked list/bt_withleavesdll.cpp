/*Calculate the height of a binary tree with leaf nodes forming a circular doubly linked list
Write an algorithm to compute a binary tree’s height with leaf nodes forming a circular doubly linked list where the leaf node’s left and right pointers will act as a previous and next pointer of the circular doubly linked list, respectively.*/
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;   // left child or previous leaf in DLL
    TreeNode* right;  // right child or next leaf in DLL
    bool isLeaf;

    TreeNode(int x) : val(x), left(NULL), right(NULL), isLeaf(false) {}
};

int getHeight(TreeNode* node) {
    if (node == nullptr) return 0;

    // If it's a leaf node, don't recurse into left or right
    if (node->isLeaf) return 1;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}
int main() {
    // Constructing the tree manually
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);

    // Set leaf status
    B->isLeaf = true;
    D->isLeaf = true;
    E->isLeaf = true;

    // Build binary tree (internal nodes only)
    A->left = B;
    A->right = C;
    C->left = D;
    C->right = E;

    // Link leaf nodes circularly: B <-> D <-> E <-> B
    B->left = E;  // prev
    B->right = D; // next

    D->left = B;
    D->right = E;

    E->left = D;
    E->right = B;

    cout << "Height of tree: " << getHeight(A) << endl;

    return 0;
}
//Outputs 3

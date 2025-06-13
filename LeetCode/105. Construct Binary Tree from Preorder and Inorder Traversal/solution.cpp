#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> inorderIndexMap(20001);
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i] + 10000] = i;
        }

        int preorderCurrent = 0;
        return constructSubtree(preorder, inorder, 0, inorder.size() - 1, preorderCurrent, inorderIndexMap);
    }

private:
    TreeNode* constructSubtree(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd, int& preorderCurrent, vector<int>& inorderIndexMap) {
        if (inorderStart > inorderEnd) return nullptr;

        int rootValue = preorder[preorderCurrent++];
        TreeNode* root = new TreeNode(rootValue);

        int rootInorderIndex = inorderIndexMap[rootValue + 10000];
        int leftSubtreeSize = rootInorderIndex - inorderStart;

        root->left = constructSubtree(preorder, inorder, inorderStart, rootInorderIndex - 1, preorderCurrent, inorderIndexMap);
        root->right = constructSubtree(preorder, inorder, rootInorderIndex + 1, inorderEnd, preorderCurrent, inorderIndexMap);

        return root;
    }
};
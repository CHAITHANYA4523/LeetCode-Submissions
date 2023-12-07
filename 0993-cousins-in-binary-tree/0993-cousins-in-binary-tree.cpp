/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getDepthAndParent(TreeNode* root, int depth, TreeNode* parent, TreeNode* &finalParent, int &finalDepth, int x){
        if(root == NULL) return;
        if(root->val == x){
            finalDepth = depth;
            finalParent = parent;
            return;
        }
        getDepthAndParent(root->left, depth+1, root, finalParent, finalDepth, x);
        if(finalDepth != -1) return;
        getDepthAndParent(root->right, depth+1, root, finalParent, finalDepth, x);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1;
        int yDepth = -1;
        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;
        TreeNode* temp = NULL;
        getDepthAndParent(root, 0, temp, xParent, xDepth, x);
        getDepthAndParent(root, 0, temp, yParent, yDepth, y);
        return xDepth == yDepth && xParent != yParent;
    }
};

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
    bool symCheck(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL || p->val != q->val) return false;
        return symCheck(p->left, q->right) && symCheck(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return symCheck(root->left, root->right);
    }
};
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
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        while(root != NULL){
            if(root->left != NULL){
                prev = root->left;
                while(prev->right) prev = prev->right; // move to extreme right node in left subtree
                prev->right = root->right; // connect last node in left subtree to root right(to reserve preorder traversal)
                root->right = root->left;
                root->left = NULL; // all left pointers should be pointing to NULL
            }
            root = root->right; // if root left subtree is absent move right
        }
    }
};
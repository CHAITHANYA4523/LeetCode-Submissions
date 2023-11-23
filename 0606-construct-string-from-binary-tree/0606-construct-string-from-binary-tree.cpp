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
    void subtree(TreeNode* &root, string &subString){
        if(root == NULL){
            return;
        }
        subString += "(" + to_string(root->val);
        if(root->left == NULL && root->right != NULL) subString += "()";
        subtree(root->left, subString);
        subtree(root->right, subString);
        subString += ")";
    }
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string res = to_string(root->val);
        string leftString = "", rightString = "";
        if(root->left == NULL && root->right != NULL) res += "()";
        subtree(root->left, leftString); //for left sub tree 
        subtree(root->right, rightString); // for right sub tree
        res += leftString+rightString;
        return res;
    }
};
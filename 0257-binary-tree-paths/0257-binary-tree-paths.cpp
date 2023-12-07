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
    void paths(TreeNode* &root, string path, vector<string> &ans){
        if(root == NULL) return;
        path += to_string(root->val); 
        // Check if the current node is a leaf  to store the string
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }
        // If not a leaf, continue with "->" and explore both subtrees
        path += "->";
        paths(root->left, path, ans); 
        paths(root->right, path, ans); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        paths(root, s, ans);
        return ans;
    }
};
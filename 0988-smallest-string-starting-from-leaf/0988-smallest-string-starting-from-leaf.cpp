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
    void dfs(TreeNode* root, string &ans, string tempString){
        if(root == NULL) return;
        tempString = static_cast<char>('a' + root->val) + tempString;
        if(root->left == NULL && root->right == NULL){
            if (tempString < ans || ans.empty()) {
                ans = tempString;
            }
        }
        dfs(root->left, ans, tempString);
        dfs(root->right, ans, tempString);
    }
    string smallestFromLeaf(TreeNode* root) {
        int mini = INT_MAX;
        string ans = "", tempString = "";
        dfs(root, ans, tempString);
        return ans;
    }
};
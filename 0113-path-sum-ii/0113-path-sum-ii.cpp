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
    void paths(TreeNode* root, int targetSum, vector<vector<int>> &ans,vector<int> &v){
        if(root == NULL) return;
        v.push_back(root->val);
        //here targetSum - root value becomes zero
        if(targetSum == root->val && root->left == NULL && root->right == NULL){
            ans.push_back(v);
        }
        else{
            paths(root->left, targetSum-root->val, ans, v);
            paths(root->right, targetSum-root->val, ans, v);
        }
        // Backtrack: remove the last element after exploring left and right
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        paths(root, targetSum, ans, v);
        return ans;
    }
};
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
    pair<TreeNode*, int> dfs(TreeNode* root){
        //Base case
        if(root == NULL){
            pair<TreeNode*, int> p = {NULL, 0};
            return p;
        }

        pair<TreeNode*, int> ans;
        ans.first = root;
        ans.second = 1;
        if(!root->left && !root->right) return ans;

        //recursive calls
        pair<TreeNode*, int> leftAns = dfs(root->left);
        pair<TreeNode*, int> rightAns = dfs(root->right);
        
        if(leftAns.second == rightAns.second){
            ans.second += leftAns.second;
            ans.first = root;
            return ans;
        }
        else if(leftAns.second > rightAns.second){
            ans.second += leftAns.second;
            ans.first = leftAns.first;
            return ans;
        }
        else{
            ans.second += rightAns.second;
            ans.first = rightAns.first;
            return ans;
        }

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;    
    }
};
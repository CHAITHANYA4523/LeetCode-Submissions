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
    
    void totalPaths(TreeNode* root, int &ans, unordered_map<int,int> &mp){
        if(root == NULL) return;
        mp[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int count = 0;
            for(auto &x:mp){
                if(x.second == 1) count++;
                if(x.second != 1 && x.second%2 == 1) count++;
            }
            if(count <= 1) ans++;
        }
        totalPaths(root->left, ans, mp);
        totalPaths(root->right, ans, mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        unordered_map<int, int> mp;
        totalPaths(root,  ans, mp);
        return ans;
    }
};
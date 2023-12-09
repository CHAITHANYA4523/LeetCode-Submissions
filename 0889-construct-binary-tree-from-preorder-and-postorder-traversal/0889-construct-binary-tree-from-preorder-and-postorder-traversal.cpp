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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& pre, vector<int>& post, int &preIndex, int postStart, int postEnd){
        if(preIndex >= pre.size() || postStart > postEnd){
            return NULL;
        }
        int element = pre[preIndex++];
        TreeNode* root = new TreeNode(element);
        if(preIndex < pre.size()){
            int position = mp[pre[preIndex]];
            if(position < postEnd){
                root->left = solve(pre, post, preIndex, postStart, position);
                root->right = solve(pre, post, preIndex, position+1, postEnd-1);
            }
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preIndex = 0; 
        for(int i=0; i<postorder.size(); i++) mp[postorder[i]] = i;
        return solve(preorder, postorder, preIndex, 0, n-1);
    }
};
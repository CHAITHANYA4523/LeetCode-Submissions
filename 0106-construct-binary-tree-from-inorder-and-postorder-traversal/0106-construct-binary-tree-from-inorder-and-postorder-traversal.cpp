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
    TreeNode* solve(vector<int>& in, vector<int>& post, int &index, int inorderStart, int inorderEnd){
        //Base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        //recursive calls
        root->right = solve(in, post, index, position+1, inorderEnd);
        root->left = solve(in, post, index, inorderStart, position-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* ans = solve(inorder, postorder, postorderIndex, 0, n-1);
        return ans;
    }
};
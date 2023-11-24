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
    string preorder(TreeNode* &root, unordered_map<string, int> &mp, vector<TreeNode*> &res){
        if(root == NULL) return "null";
        string left = preorder(root->left, mp, res);
        string right = preorder(root->right, mp, res);
        string s = left + "," + right + "," + to_string(root->val);
        // we are first checking before updating count of serialised string to avoid multiple insertions of a root into the resultant vector 
        if(mp[s] == 1) res.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        preorder(root, mp, res);
        return res;
    }
};
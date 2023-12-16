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
    priority_queue<int> maxHeap;
    void inorderTraversal(TreeNode* root, int k){
        if(!root) return;
        inorderTraversal(root->left, k); 
        maxHeap.push(root->val);
        if(maxHeap.size() > k) maxHeap.pop();
        inorderTraversal(root->right, k); 
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return maxHeap.top();
    }
};
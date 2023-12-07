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
    void summation(TreeNode* &root, long long sum, long long &finalSum){
        if(root == NULL) return;
        sum = sum*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            finalSum += sum;
        }
        summation(root->left, sum, finalSum);
        summation(root->right, sum, finalSum);
    }
    int sumNumbers(TreeNode* root) {
        long long finalSum = 0;
        summation(root, 0, finalSum);
        return finalSum;
    }
};
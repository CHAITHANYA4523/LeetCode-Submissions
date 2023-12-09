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
    //after every call it is creating new sub vectors with reccursion to solve for every sub tree
    int findPosition(int x, vector<int> inorder, int n){
        for(int i=0; i<n; i++){
            if(x == inorder[i]) return i;
        }
        return -1;
    }
    // pass index by reference to keep it's updated value
    TreeNode* solve(vector<int> pre, vector<int> in, int &index, int inOrderStart, int inOrderLast, int n){
        //Base case
        if(index >= n || inOrderStart > inOrderLast){
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(element, in, n);

        //recursive  calls 
        root->left = solve(pre, in, index, inOrderStart, position-1, n);
        root->right = solve(pre, in, index, position+1, inOrderLast, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        // n-1 is the last index of inorder vector and 0 is the inorder first index
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};
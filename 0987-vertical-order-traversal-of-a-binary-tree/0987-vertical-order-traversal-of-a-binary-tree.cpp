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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // {vertical , {level , node->val}}
        map<int, map<int,multiset<int>>> mp; // using multiset to store equal values in the same vertical line
        // {node , {vertical , level}}
        queue<pair<TreeNode* , pair<int , int >>> q;
        q.push({root , {0 , 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            mp[vertical][level].insert(node->val);
            if(node->left) q.push({node->left, {vertical-1, level+1}});
            if(node->right) q.push({node->right, {vertical+1, level+1}});
        }
        vector<vector<int>> ans;
         for(auto oneVertical:mp){
        // vec is a vector of int to store one complete vertical .
            vector<int>vec;
            for(auto levelAndSet:oneVertical.second){
                for(auto setElement:levelAndSet.second){
                    vec.push_back(setElement);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
#include <bits/stdc++.h>
class Solution {
public:
    void uniqueSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int index){
            ans.push_back(ds);
        for(int i=index; i<nums.size(); i++){
            //skip when we get two consecutive elements same when we perform the iteration  for inserting 1st element, or 2nd element etc for the same level of recursion
            if(i != index && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            uniqueSubsets(nums, ans, ds, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        uniqueSubsets(nums, ans, ds, 0);
        return ans;
    }
};
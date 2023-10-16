class Solution {
public:
    void totalPermutations(vector<vector<int>>& ans, vector<int>& nums, vector<int> ds, int index){
        //base case
        if(index == nums.size()){ //permutation ds size is equal to nums
            for(int i=0; i<nums.size(); i++) ds.push_back(nums[i]);
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            totalPermutations(ans, nums, ds, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        totalPermutations(ans, nums, ds, 0);
        return ans;
    }
};
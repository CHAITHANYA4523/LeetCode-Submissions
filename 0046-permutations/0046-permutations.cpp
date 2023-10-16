class Solution {
public:
    void totalPermutations(vector<vector<int>>& ans, vector<int>& nums, int freq[], vector<int>ds){
        //base case
        if(ds.size() == nums.size()){ //permutation ds size is equal to nums
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                totalPermutations(ans, nums, freq, ds);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        totalPermutations(ans, nums, freq, ds);
        return ans;
    }
};
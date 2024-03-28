class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        int ans = INT_MIN;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]] <= k){
                ans = max(ans, j-i+1);
            }
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
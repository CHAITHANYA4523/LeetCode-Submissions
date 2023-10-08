class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){ 
            if(mp.find(target-nums[i]) != mp.end()){
                ans.push_back(mp[target-nums[i]]); // stores the index of target-nums[i]
                ans.push_back(i);
            }
            //we store the number only if it's compliment is not found in map
            mp[nums[i]] = i;
        }
        return ans;
    }
};
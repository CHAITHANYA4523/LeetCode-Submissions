class Solution {
private:
    int subarrrayWithAtmostKDistinct(vector<int>& nums, int k){
        int i=0, j = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        int count1 = 0, count2 = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size() > k){
                while(mp.size() > k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
            }
            ans = ans + j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int finalAns = subarrrayWithAtmostKDistinct(nums, k) - subarrrayWithAtmostKDistinct(nums, k-1);
        return finalAns;
    }
};
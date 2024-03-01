class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int count = 0, ans = INT_MIN;
        for(auto it:mp){
            int element = it.first;
            //if no element smaller than current is found consider 
            //current element as the starting element of sequence.
            if(mp.find(element-1) == mp.end()){
                count = 1;
            }
            else{
                count++;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
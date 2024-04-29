class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorNum = 0;
        for(int i=0; i<nums.size(); i++){
            xorNum = xorNum ^ nums[i];
        }
        xorNum = xorNum ^ k;
        int count = 0;
        while(xorNum){
            if(xorNum & 1) count++;
            xorNum = xorNum>>1;
        }
        return count;
    }
};
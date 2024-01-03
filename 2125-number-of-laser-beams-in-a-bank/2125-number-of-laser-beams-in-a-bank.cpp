class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount = 0, ans = 0, currCount = 0;
        for(int i=0; i<bank.size(); i++){
            int currCount = count(bank[i].begin(), bank[i].end(), '1');
            if(currCount == 0) continue;
            ans += currCount*prevCount;
            prevCount = currCount;
        }
        return ans;
    }
};
typedef pair<int, int> pii;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        priority_queue<pii> maxHeap;
        map<int,int> mp;
        vector<int> ans;
        for(auto x:nums) mp[x]++;
        for(auto it:mp){
            maxHeap.push(make_pair(-it.second, it.first));
        }
        while(!maxHeap.empty()){
            int n = maxHeap.top().first;
            for(int i=0; i<abs(n); i++)
                ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

/*we use negative frequency in max-heap instead of using min-heap to handle cases with same frequency. ex - [2,3,1,3,2]
In min-heap, if first is equal then element will come out according to second and we are using min-heap therefore smaller second will come out which is not the requirement. output :- [1,2,2,3,3]
In max-heap, if first is equal then element will come out according to second and we are using max-heap therefore greater second will come out. output :- [1,3,3,2,2] */
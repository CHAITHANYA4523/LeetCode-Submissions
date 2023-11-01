class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> v;
        for(int i=0; i<arr.size(); i++){
            maxHeap.push(make_pair(abs(arr[i]-x), arr[i]));
            if(maxHeap.size() > k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};
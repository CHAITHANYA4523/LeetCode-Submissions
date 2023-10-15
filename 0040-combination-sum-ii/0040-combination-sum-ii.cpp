class Solution {
public:
    void uniqueCombinations(vector<vector<int>>& ans, vector<int> ds, vector<int>& arr, int target, int index){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<arr.size(); i++){
            //i > index to check if we are picking the element for the first time in next iteration (our goal is to not pick the same element in one iteration)
            if(i > index && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            uniqueCombinations(ans, ds, arr, target-arr[i], i+1);
            ds.pop_back(); //remove the top element when we backtrack
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        uniqueCombinations(ans, ds, candidates, target, 0);
        return ans;
    }
};


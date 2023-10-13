class Solution {
public:
    void uniqueCombinations(vector<vector<int>>& ans, vector<int> ds, vector<int>& candidates, int target, int index){
        if(index == candidates.size()){
            if(target == 0)ans.push_back(ds);
            return ;
        }
        //pick an element
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            uniqueCombinations(ans, ds, candidates, target-candidates[index], index);
            ds.pop_back(); // remove element from data structure
        }
        //not pick condition so target remains same
        uniqueCombinations(ans, ds, candidates, target, index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        uniqueCombinations(ans, ds, candidates, target, 0);
        return ans;
    }
};
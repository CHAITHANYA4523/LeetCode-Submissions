class Solution {
private:
    int finalAns = INT_MIN;
public:
    void finalMaxScore(string s, int left, int right){
        int maxi = 0;
        if(right == s.length()) return;
        int iterator1 = left, iterator2 = right;
        while(iterator1 < right){
            if(s[iterator1] == '0'){
                maxi++;
            }
            iterator1++;
        }
        while(iterator2 < s.length()){
            if(s[iterator2] == '1') maxi++;
            iterator2++;
        }
        finalAns = max(finalAns, maxi);
        finalMaxScore(s, 0, right+1);
    }
    int maxScore(string s) {
        if(s.length() == 1) return 1;
        finalMaxScore(s, 0, 1);
        return finalAns;
    }
};
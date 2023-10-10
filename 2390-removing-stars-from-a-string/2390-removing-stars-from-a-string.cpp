class Solution {
public:
    string reverse(string &ans){
        for(int i=0, j=ans.length()-1; i<=j; i++, j--){
            swap(ans[i], ans[j]);
        }
        return ans;
    }
    string removeStars(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*' && !st.empty()) st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return reverse(ans);    
    }
};
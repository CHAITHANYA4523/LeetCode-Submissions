class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans;
        
        for (int i = n - 1; i >= 0; i--) {
            int count = 0; // Initialize count  
            if (st.empty()) {
                ans.push_back(0);
            } 
            else if (temperatures[i] >= temperatures[st.top()]) {
                while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                    st.pop();
                }
                if (!st.empty()) {
                    count = st.top() - i;
                }
                ans.push_back(count);
            } 
            else {
                count = st.top() - i;
                ans.push_back(count);
            }
            
            st.push(i);
        }
        // Reverse the result vector
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

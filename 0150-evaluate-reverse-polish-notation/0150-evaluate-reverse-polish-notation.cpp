class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto ch : tokens) {
            if (ch == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if (ch == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (ch == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if (ch == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                int x = stoi(ch);
                st.push(x);
            }
        }
        return st.top();
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto x : operations) {
            if (x == "D") {
                int n = 2 * st.top();
                st.push(n);
            } else if (x == "C") {
                st.pop();
            } else if (x == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            } else {
                int val = stoi(x); // Convert the string to an integer
                st.push(val);
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

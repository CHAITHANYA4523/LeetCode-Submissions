class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // Create a stack       
        int j = 0; // Intialise one pointer pointing on popped array  
        for(auto val : pushed){
            st.push(val); // insert the values in stack
            while(!st.empty() && st.top() == popped[j]){ // if st.peek() values equal to popped[j];
                st.pop(); // then pop out
                j++; // increment j
            }
        }
        return st.empty(); // check if stack is empty return true else false
    }
};
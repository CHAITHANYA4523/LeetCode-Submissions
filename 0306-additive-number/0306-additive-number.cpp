class Solution {
private:
    bool helper(long long n1, long long n2, string str, bool found){
        //if the conditions are satisfied till the end
        //that means found will be true and no string will be left 
        //to compare for the last number
        if(str.length() == 0 && found){
            return true;
        }
        string n3 = to_string(n1+n2);
        int idx = min(str.length(), n3.length());
        if(str.substr(0, idx) == n3){
            //update the numbers and take new string from index and mark 
            //found as true
            return helper(n2, stol(n3), str.substr(idx), true);
        }
        return false;
    }
public:
    bool isAdditiveNumber(string s) {
        int n = s.length();
        if(n <= 2) return false;
        for(int i=1; i<n-1; i++){
            //it gives a number in the substring starting at index 0 and
            //take upto i characters 
            long long n1 = stol(s.substr(0, i));
            //to check numbers starting with 0s ex: 023
            //here we compare 23 == 023 which is wrong
            if(to_string(n1) != s.substr(0, i)) break;
            for(int j=i+1; j<n; j++){
                long long n2 = stol(s.substr(i, j-i));
                if(to_string(n2) != s.substr(i, j-i)) break;
                //s.substr(j) starts at j and goes till the last character
                bool found = helper(n1, n2, s.substr(j), false);
                if(found == true) return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int minOperations(string s) {
        int zeroAtEven = 0, oneAtEven = 0;
        for(int i=0; i<s.length(); i++){
            if((s[i] == '0' && i%2 == 0) || (s[i] == '1' && i%2 != 0)){
                oneAtEven++;
            }
            if((s[i] == '1' && i%2 == 0) || (s[i] == '0' && i%2 != 0)){
                zeroAtEven++;
            }    
        }
        if(zeroAtEven < oneAtEven) return zeroAtEven;
        return oneAtEven;
    }
};
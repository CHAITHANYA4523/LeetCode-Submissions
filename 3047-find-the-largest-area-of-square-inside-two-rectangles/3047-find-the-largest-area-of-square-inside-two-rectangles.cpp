class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long length = 0, breadth = 0;
        long long ans = 0;
        for(int i=0; i<n; i++){
           for(int j=i+1; j<n; j++){
               int minX = max(bottomLeft[i][0], bottomLeft[j][0]);
               int minY = max(bottomLeft[i][1], bottomLeft[j][1]);
               int maxX = min(topRight[i][0], topRight[j][0]);
               int maxY = min(topRight[i][1], topRight[j][1]);
               length = maxY-minY;
               breadth = maxX-minX;
               if(length*breadth > 0) ans = max(ans, min(length, breadth)); 
           } 
        }
        return ans*ans;
    }
};
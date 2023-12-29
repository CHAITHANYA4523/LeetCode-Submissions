class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int initialColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        //up, right, down, left
        int adjrow[] = {-1, 0, 1, 0};
        int adjcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = curr.first + adjrow[i];
                int ncol = curr.second + adjcol[i];
                if(nrow >=0 && nrow < image.size() && ncol < image[0].size() && ncol >=0){
                    if(image[nrow][ncol] == initialColor){
                        q.push({nrow, ncol});
                        image[nrow][ncol] = newColor;
                    }
                }
            }
        }
        return image;
    }
};

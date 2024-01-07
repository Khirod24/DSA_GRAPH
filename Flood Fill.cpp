void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image,int newColor, int deltaRow[], int deltaCol[],int initialColor){
        ans[row][col]=newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++){
            int newRow= row+ deltaRow[i];
            int newCol= col+ deltaCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==initialColor && ans[newRow][newCol]!=newColor){
                dfs(newRow,newCol,ans,image,newColor,deltaRow,deltaCol,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor= image[sr][sc];
        vector<vector<int>>ans= image;
        int deltaRow[]= {-1,0,+1,0};
        int deltaCol[]= {0,+1,0,-1};
        dfs(sr,sc,ans,image,color,deltaRow,deltaCol,initialColor);
        return ans;
    }

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor=image[sr][sc];

        if (originalColor == color)
        return image;

        dfs(image,sr,sc,originalColor,color);

        return image;
        
    }

    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int color){

        if(r>=0 && r<image.size() && c>=0 && c<image[0].size()){
            if(image[r][c]==originalColor){
                image[r][c]=color;

                dfs(image,r+1,c,originalColor,color);
                dfs(image,r,c+1,originalColor,color);
                dfs(image,r-1,c,originalColor,color);
                dfs(image,r,c-1,originalColor,color);
                
            }

        }

        return;

    }
};
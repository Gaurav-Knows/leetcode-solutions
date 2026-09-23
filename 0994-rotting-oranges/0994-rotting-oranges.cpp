class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>>q;
        int min=0;

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }

            
        }

        

        while(!(q.empty())){
            bool rotted = false;

            int size = q.size();

            for(int i=0;i<size;i++){

                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                if (r > 0 && grid[r-1][c] == 1) {
                   grid[r-1][c] = 2;
                   q.push({r-1, c});
                   rotted=true;
                }

                if (r < grid.size()-1 && grid[r+1][c] == 1) {
                   grid[r+1][c] = 2;
                   q.push({r+1, c});
                   rotted=true;
                }

                if (c > 0 && grid[r][c-1] == 1) {
                   grid[r][c-1] = 2;
                   q.push({r, c-1});
                   rotted=true;
                }

                if (c < grid[0].size()-1 && grid[r][c+1] == 1) {
                   grid[r][c+1] = 2;
                   q.push({r, c+1});
                   rotted=true;
                }

            }

            if(rotted){
                min++;
            }
        }

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    return -1;
                }
            }

            
        }

        return min;



        
        
    }

    
};
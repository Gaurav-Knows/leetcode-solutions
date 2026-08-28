class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
    for(int row = 0; row < board.size(); row++){
    for(int col = 0; col < board[0].size(); col++){
        if(backtrack(row, col, 0, word, board)){
            return true;
        }
    }
    }

    return false;
    }

    bool backtrack(int row,int col,int index,string &word,vector<vector<char>>& board){

        if(index==word.size()){
            return true;
        }

        

        
        
        

        if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size()){

            return false;

        }

        if(board[row][col]!=word[index]){
            return false;
        }

        board[row][col]='#';

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            int rownew=row +dr[i];
            int colnew=col +dc[i];

            
            
            


            if(backtrack(rownew,colnew,index+1,word,board)){
                return true;
            }

            

           

        }
        board[row][col] = word[index];
        return false;
    }


};
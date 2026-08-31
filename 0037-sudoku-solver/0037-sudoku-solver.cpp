class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 

        backtrack(board);


        
          
    }

    bool backtrack(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++){
          for(int col = 0; col < 9; col++){
               if(board[row][col] == '.'){
             
                
                for(char num='1';num<='9';num++){
                    if(isValid(board,row,col,num)){
                        board[row][col]=num;
                        if(backtrack(board)){
                        return true;
                        }
                        board[row][col]='.';
                    }
                }

                return false;
               }
            }
        
        }
        return true;
    
}

    bool isValid(vector<vector<char>> &board,int row,int col,char num){
        for(int i=0;i<board.size();i++){
            if(board[row][i]==num){
                return false;
            }
        }

        for(int i=0;i<board.size();i++){
            if(board[i][col]==num){
                return false;
            }
        }

        int startNewr=row/3*3;
        int startNewc=col/3*3;

        for(int i=startNewr;i<startNewr+3;i++){
            for(int j=startNewc;j<startNewc+3;j++){
                if(board[i][j]==num){
                    return false;
                }
            }
        }

        return true;

        


    }


};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(ans, board, cols, diag1, diag2, 0);

        return ans;
    }

    void backtrack(vector<vector<string>>& ans,
                    vector<string>& board,
                    vector<bool>& cols,
                    vector<bool>& diag1,
                    vector<bool>& diag2,
                    int row) {

        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {

            if (cols[col])
                continue;

            if (diag1[row - col + board.size() - 1])
                continue;

            if (diag2[row + col])
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row - col + board.size() - 1] = true;
            diag2[row + col] = true;

            // Explore next row
            backtrack(ans, board, cols, diag1, diag2, row + 1);

            // Undo
            board[row][col] = '.';
            cols[col] = false;
            diag1[row - col + board.size() - 1] = false;
            diag2[row + col] = false;
        }
    }
};
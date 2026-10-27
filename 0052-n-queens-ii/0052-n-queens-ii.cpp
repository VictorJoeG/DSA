class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }
        for (int i = 1; i <= min(row, col); i++) {
            if (board[row - i][col - i] == 'Q') return false;
        }
        for (int i = 1; i <= min(n - 1 - row, col); i++) {
            if (board[row + i][col - i] == 'Q') return false;
        }
        return true;
    }
    void backtrack(vector<string>& board, int col, int &count) {
        if (col == board.size()) {
            count++;
            return;
        }
        for(int row=0; row<board.size(); row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                backtrack(board,col+1,count);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        int count=0;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, count);
        return count;
    }
};
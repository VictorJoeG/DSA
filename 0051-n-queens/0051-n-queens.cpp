class Solution {
public:
    void backtrack(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow,
    vector<int> &lowerdiagnol, vector<int> &upperdiagnol, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiagnol[row+col]==0 && upperdiagnol[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagnol[row+col]=1;
                upperdiagnol[n-1+col-row]=1;
                backtrack(col+1,board,ans,leftrow,lowerdiagnol,upperdiagnol,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagnol[row+col]=0;
                upperdiagnol[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int> leftrow(n,0), lowerdiagnol(2*n-1,0), upperdiagnol(2*n-1,0); 
        backtrack(0,board,ans,leftrow,lowerdiagnol,upperdiagnol,n);
        return ans;
    }
};
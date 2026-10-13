class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string &word, int i, int j, int ind){
        int m = board.size();
        int n = board[0].size();
        if(ind==word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n)return false;
        if(board[i][j] != word[ind] || board[i][j] == '$') return false;

        char temp = board[i][j];
        board[i][j] ='$';

        if(backtrack(board,word,i+1,j,ind+1) || backtrack(board,word,i-1,j,ind+1) ||
           backtrack(board,word,i,j+1,ind+1) || backtrack(board,word,i,j-1,ind+1)){
            return true;
           }
        
        board[i][j]=temp;
        return false;      

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(backtrack(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
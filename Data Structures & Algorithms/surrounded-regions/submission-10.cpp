class Solution {
public:
    void answer(vector<vector<char>>& board,int r,int c)
    {
         if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return;

        if(board[r][c]!='O')
         return;

         board[r][c]='t';
         answer(board,r+1,c);
         answer(board,r-1,c);
         answer(board,r,c+1);
         answer(board,r,c-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        if(board.empty())
            return;

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            answer(board,i,0);

            if(board[i][m-1]=='O')
            answer(board,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            answer(board,0,j);

            if(board[n-1][j]=='O')
            answer(board,n-1,j);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='t')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};

class Solution {
public:
    bool answer(vector<vector<char>>& board,string word,int r,int c,int i)
    {
        if(i==word.size())
        {
            return true;
        }

        if(r<0||c<0||r>=board.size()||c>=board[0].size())
        return false;

        if(board[r][c] != word[i])
         return false;

        char temp=board[r][c];
        board[r][c]='#';
        
        bool ans=
        
            answer(board,word,r+1,c,i+1)||
            answer(board,word,r,c+1,i+1)||
            answer(board,word,r-1,c,i+1)||
            answer(board,word,r,c-1,i+1);

          board[r][c]=temp;
          return ans;

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r=0;r<board.size();r++)
        {
            for(int c=0;c<board[0].size();c++)
            {
                if(board[r][c]==word[0])
               { 
                    if(answer(board,word,r,c,0)==1) 
                    return true;
                }
            }
        }
         
            return false;
    }
};

class Solution {
public:
    bool vis[6][6];
    vector<vector<char>> board;
    string word;
    bool ans=0;
    int s=0;
    bool exist(vector<vector<char>>& board_, string word_) {
        board=board_;
        word=word_;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                if(ans) break;
                if(board[i][j]==word[0])
                    func(i,j);
            }
        return ans;
    }
    void func(int x,int y)
    {
        if(ans) return;
        if(s==word.length()-1) 
        {
            ans=1;
            return;
        }
        vis[x][y]=1;
        s++;
        if(x>0&&board[x-1][y]==word[s]&&vis[x-1][y]==0)
            func(x-1,y);
        if(x<board.size()-1&&board[x+1][y]==word[s]&&vis[x+1][y]==0)
            func(x+1,y);
        if(y>0&&board[x][y-1]==word[s]&&vis[x][y-1]==0)
            func(x,y-1);
        if(y<board[0].size()-1&&board[x][y+1]==word[s]&&vis[x][y+1]==0)
            func(x,y+1);
        s--;
        vis[x][y]=0;
    }
};

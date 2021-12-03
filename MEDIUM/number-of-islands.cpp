class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                    ans+=dfs(i,j,grid);
            }
        return ans;
    }
    int dfs(int x,int y,vector<vector<char>>& grid)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(x,y));
        grid[x][y]='0';
        while(!que.empty())
        {
            int frontx=que.front().first;
            int fronty=que.front().second;
            for(int i=0;i<4;i++)
            {
                int expandx=frontx+dx[i];
                int expandy=fronty+dy[i];
                if(expandx<0||expandx>=grid.size()) continue;
                else if(expandy<0||expandy>=grid[0].size()) continue;
                else if(grid[expandx][expandy]=='0') continue;
                que.push(make_pair(expandx,expandy));
                grid[expandx][expandy]='0';
            }
            que.pop();
        }
        return 1;
    }
};

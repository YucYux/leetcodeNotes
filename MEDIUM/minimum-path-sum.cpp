class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int temp=0;
        int m=grid.size();
        int n=grid[0].size();
        int** len=new int*[m];
        for(int i=0;i<m;i++)
            len[i]=new int[n];
        for(int i=0;i<m;i++)
        {
            temp+=grid[i][0];
            len[i][0]=temp;
        }
        temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=grid[0][i];
            len[0][i]=temp;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                len[i][j]=Min(len[i][j-1],len[i-1][j])+grid[i][j];
        return len[m-1][n-1];
    }
    inline int Min(int a,int b)
    {
        if(a<b) return a;
        return b;
    }
};

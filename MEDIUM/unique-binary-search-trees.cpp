class Solution {
public:
    int numTrees(int n) {
        int** dp=new int*[n];
        for(int i=0;i<n;i++)
            dp[i]=new int[n];
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=1;i<n;i++)
            dp[i-1][i]=2;
        for(int i=n-3;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                int temp=0;
                temp+=dp[i+1][j];
                temp+=dp[i][j-1];
                for(int k=0;k<=j-i-2;k++)
                    temp+=(dp[i][i+k]*dp[i+k+2][j]);
                dp[i][j]=temp;
            }
        }
        return dp[0][n-1];
    }
};

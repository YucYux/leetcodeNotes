class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int** dp=new int*[m+1];
        for(int i=0;i<m+1;i++)
            dp[i]=new int[n+1];
        for(int i=0;i<m+1;i++)
            dp[i][0]=i;
        for(int i=0;i<n+1;i++)
            dp[0][i]=i;
        for(int i=1;i<m+1;i++)
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=Min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=Min(dp[i][j],dp[i-1][j-1]);
            }
        return dp[m][n];
    }
    inline int Min(int a,int b,int c)
    {
        if(a<=b&&a<=c) return a;
        else if(b<=a&&b<=c) return b;
        return c;
    }
    inline int Min(int a,int b)
    {
        if(a<b) return a;
        return b;
    }
};

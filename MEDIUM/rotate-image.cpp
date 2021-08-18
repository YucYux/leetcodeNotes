class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp=0;
        for(int i=0;i<matrix.size()/2;i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                temp=matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i]=matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
        if(matrix.size()%2!=0)
        {
            for(int i=0;i<matrix.size()/2;i++)
            {
                temp=matrix[matrix.size()/2][i];
                matrix[matrix.size()/2][i]=matrix[matrix.size()-1-i][matrix.size()/2];
                matrix[matrix.size()-1-i][matrix.size()/2]=matrix[matrix.size()/2][matrix.size()-1-i];
                matrix[matrix.size()/2][matrix.size()-1-i]=matrix[i][matrix.size()/2];
                matrix[i][matrix.size()/2]=temp;
            }
        }
    }
};

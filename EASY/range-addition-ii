class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m*n;
        int minx = 40001;
        int miny = 40001;
        for(int i = 0; i < ops.size(); i++)
        {
            minx = getMin(minx, ops[i][0]);
            miny = getMin(miny, ops[i][1]);
        }
        return minx*miny;
    }
    inline int getMin(int a, int b)
    {
        if(a > b) return b;
        else return a;
    }
};

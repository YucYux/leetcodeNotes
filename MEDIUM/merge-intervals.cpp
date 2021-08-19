class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        vector<int> res({0,0});
        res[0]=intervals[0][0];
        res[1]=intervals[0][1];
        bool finish=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(res[1]>=intervals[i][0])
            {
                res[1]=max(res[1],intervals[i][1]);
            }
            else
            {
                ans.emplace_back(res);
                res[0]=intervals[i][0];
                res[1]=intervals[i][1];
            }
        }
        ans.emplace_back(res);
        return ans;
    }
    static bool comp(const vector<int> & a,const vector<int> & b)
    {
        return a[0]<b[0];
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int target;
    vector<int> candidates;
    int sum;
    vector<vector<int>> combinationSum(vector<int>& candidates_, int target_) {
        target=target_;
        candidates=candidates_;
        sum=0;
        func(0);
        return ans;
    }
    void func(int backIndex)
    {
        if(sum==target)
        {
            ans.push_back(res);
            return;
        }
        for(int i=backIndex;i<candidates.size();i++)
        {
            if(sum+candidates[i]<=target)
            {
                res.push_back(candidates[i]);
                sum+=candidates[i];
                func(i);
                res.pop_back();
                sum-=candidates[i];
            }
        }
    }
};

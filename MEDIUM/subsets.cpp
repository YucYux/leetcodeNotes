class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    bool vis[11];
    vector<int> raw;
    vector<vector<int>> subsets(vector<int>& nums) {
        raw=nums;
        for(int i=0;i<11;i++) vis[i]=0;
        func();
        return ans;
    }
    void func()
    {
        ans.push_back(res);
        int start=-1;
        for(int i=0;i<raw.size();i++)
            if(vis[i]==1) start=i;
        if(start<(int)(raw.size()-1))
            start++;
        else return;
        for(int i=start;i<raw.size();i++)
        {
            vis[i]=1;
            res.push_back(raw[i]);
            func();
            res.pop_back();
            vis[i]=0;
        }
    }
};

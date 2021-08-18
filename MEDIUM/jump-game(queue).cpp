class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return 1;
        queue<int> que;
        que.push(0);
        bool* vis=new bool[nums.size()];
        memset(vis,0,nums.size());
        while(!que.empty())
        {
            int temp=nums[que.front()];
            if(temp>=nums.size()-que.front()) return 1;
            for(int i=temp;i>=1;i--)
            {
                if(!vis[que.front()+i])
                {
                    vis[que.front()+i]=1;
                    if(que.front()+i==nums.size()-1) return 1;
                    que.push(que.front()+i);
                }
            }
            que.pop();
        }
        delete[] vis;
        return 0;
    }
};

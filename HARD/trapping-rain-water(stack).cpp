class Solution {
public:
    int trap(vector<int>& height) {
        int p=0;
        stack<int> sta;
        int ans=0;
        while(p<height.size())
        {
            if(!sta.empty()&&sta.top()==p)
            {
                p++;
                continue;
            }
            while(sta.empty()!=1&&height[p]>height[sta.top()])
            {
                int h=height[sta.top()];
                sta.pop();
                if(sta.empty()) break;
                ans+=(min(height[sta.top()],height[p])-h)*(p-sta.top()-1);
            }
            sta.push(p);
            p++;
        }
        return ans;
    }
};

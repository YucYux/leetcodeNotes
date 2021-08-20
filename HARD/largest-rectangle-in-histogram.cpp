class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int* leftFirstLower=new int[heights.size()];
        leftFirstLower[0]=-1;
        stack<int> sta;
        sta.push(0);
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]>heights[sta.top()])
            {
                leftFirstLower[i]=i-1;
                sta.push(i);
            }
            else
            {
                while(!sta.empty())
                {
                    if(heights[sta.top()]>=heights[i])
                        sta.pop();
                    else break;
                }
                if(sta.empty())
                    leftFirstLower[i]=-1;
                else
                    leftFirstLower[i]=sta.top();
                sta.push(i);
            }
        }
        int* rightFirstLower=new int[heights.size()];
        rightFirstLower[heights.size()-1]=heights.size();
        stack<int>().swap(sta);
        sta.push(heights.size()-1);
        for(int i=heights.size()-2;i>=0;i--)
        {
            if(heights[i]>heights[sta.top()])
            {
                rightFirstLower[i]=i+1;
                sta.push(i);
            }
            else
            {
                while(!sta.empty())
                {
                    if(heights[sta.top()]>=heights[i])
                        sta.pop();
                    else break;
                }
                if(sta.empty())
                    rightFirstLower[i]=heights.size();
                else
                    rightFirstLower[i]=sta.top();
                sta.push(i);
            }
        }
        int ans=0;
        int temp=0;
        for(int i=0;i<heights.size();i++)
        {
            temp=heights[i]*(rightFirstLower[i]-leftFirstLower[i]-1);
            ans=max(ans,temp);
        }
        return ans;
    }
};

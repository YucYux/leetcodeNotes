class Solution {
public:
    int trap(vector<int>& height) {
        int* leftHighest = new int[height.size()];
        int* rightHighest= new int[height.size()];
        leftHighest[0] = 0;
        rightHighest[height.size()-1] = 0;
        for(int i=1;i<height.size();i++)
            leftHighest[i]=max(height[i-1],leftHighest[i-1]);
        for(int i=height.size()-2;i>=0;i--)
            rightHighest[i]=max(height[i+1],rightHighest[i+1]);
        int ans=0;
        for(int i=1;i<height.size()-1;i++)
        {
            if(height[i]<leftHighest[i]&&height[i]<rightHighest[i])
                ans+=Min(leftHighest[i],rightHighest[i])-height[i];
        }
        return ans;
    }
    int Min(int a,int b)
    {
        if(a<b) return a;
        else return b;
    }
};

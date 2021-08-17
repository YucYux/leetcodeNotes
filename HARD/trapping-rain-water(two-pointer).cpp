class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int left=1;
        int right=height.size()-2;
        int leftHighest=height[0];
        int rightHighest=height[height.size()-1];
        int ans=0;
        while(left<=right)
        {
            if(leftHighest<=rightHighest)
            {
                if(height[left]<leftHighest)
                    ans+=leftHighest-height[left];
                else
                    leftHighest=height[left];
                left++;
            }
            else
            {
                if(height[right]<rightHighest)
                    ans+=rightHighest-height[right];
                else
                    rightHighest=height[right];
                right--;
            }
        }
        return ans;
    }
};

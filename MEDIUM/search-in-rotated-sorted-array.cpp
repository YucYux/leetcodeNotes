class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target) return 0;
            else return -1;
        }
        if(nums.size()==2)
        {
            if(nums[0]==target) return 0;
            else if(nums[1]==target) return 1;
            return -1;
        }
        int l=0;
        int r=nums.size()-1;
        int m=0;
        while(l<=r)
        {
            m=(l+r)/2;
            if(m>0&&nums[m-1]>nums[m]) break;
            if(nums[m]<=nums[r])
                r=m-1;
            else if(nums[m]>=nums[l])
                l=m+1;
        }
        if(l>r)
        {
            l=0;
            r=nums.size()-1;
        }
        else
        {
            if(target>=nums[0])
            {
                l=0;
                r=m-1;
            }
            else
            {
                l=m;
                r=nums.size()-1;
            }
        }
        m=(l+r)/2;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]==target) return m;
            if(target>nums[m])
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};

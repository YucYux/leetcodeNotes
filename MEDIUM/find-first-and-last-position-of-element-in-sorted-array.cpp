class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=0;
        int last=0;
        int l=0;
        int m=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]==target&&(m==0||nums[m]>nums[m-1]))
            {
                first=m;
                break;
            }
            if(nums[m]>target||(nums[m]==target&&m>0&&nums[m]==nums[m-1])) //target is on the left
                r=m-1;
            else 
                l=m+1;
        }
        if(l>r)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        l=0;
        r=nums.size()-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]==target&&(m==nums.size()-1||nums[m]<nums[m+1]))
            {
                last=m;
                break;
            }
            if(nums[m]<target||(nums[m]==target&&m<nums.size()-1&&nums[m]==nums[m+1])) //target is on the right
                l=m+1;
            else 
                r=m-1;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return getMax(nums[0],nums[1]);
        else if(nums.size()==3)
            return getMax((nums[0]+nums[2]),nums[1]);
        int * dp=new int[nums.size()];
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=getMax(nums[nums.size()-1],nums[nums.size()-2]);
        for(int i=nums.size()-3;i>=0;i--)
            dp[i]=getMax(nums[i]+dp[i+2],dp[i+1]);
        return dp[0];
    }
    int getMax(int a,int b)
    {
        if(a>b) return a;
        return b;
    }
};

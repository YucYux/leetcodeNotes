class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return maxRangeSubArray(0,nums.size()-1,nums);
    }
    int maxRangeSubArray(int s,int e,vector<int> & nums)
    {
        if(s==e) return nums[s];
        int m=(s+e)/2;
        int middleMax=0;
        int sum=0;
        int tempMax=0x80000000;
        for(int i=m+1;i<=e;i++)
        {
            sum+=nums[i];
            tempMax=max(tempMax,sum);
        }
        middleMax+=tempMax;
        sum=0;
        tempMax=0x80000000;
        for(int i=m;i>=s;i--)
        {
            sum+=nums[i];
            tempMax=max(tempMax,sum);
        }
        middleMax+=tempMax;
        return max(middleMax,max(maxRangeSubArray(s,m,nums),maxRangeSubArray(m+1,e,nums)));
    }
};

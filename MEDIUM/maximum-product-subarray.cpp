class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int imax = 1;
        int imin = 1;
        int res = 0x80000000;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = getMax(nums[i], imax*nums[i]);
            imin = getMin(nums[i], imin*nums[i]);
            res = getMax(imax, res);
        }
        return res;
    }
    int getMax(int a, int b)
    {
        if(a > b) return a;
        return b;
    }
    int getMin(int a, int b)
    {
        if(a < b) return a;
        return b;
    }
};

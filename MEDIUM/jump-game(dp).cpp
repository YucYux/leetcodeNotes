class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int tempMax=0;
        int i=0;
        while(i<=tempMax)
        {
            tempMax=max(tempMax,i+nums[i]);
            if(tempMax>=nums.size()-1) return 1;
            i++;
        }
        return 0;
    }
};

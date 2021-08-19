class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int p1=nums.size()-2;
        int temp=0;
        while(p1>=0)
        {
            if(nums[p1]<nums[p1+1]) break;
            p1--;
        }
        if(p1<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>p1;i--)
        {
            if(nums[i]>nums[p1])
            {
                temp=nums[i];
                nums[i]=nums[p1];
                nums[p1]=temp;
                break;
            }
        }
        for(int i=0;i<(nums.size()-1-p1)/2;i++)
        {
            temp=nums[nums.size()-1-i];
            nums[nums.size()-1-i]=nums[p1+1+i];
            nums[p1+1+i]=temp;
        }
    }
};

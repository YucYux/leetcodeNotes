class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tot=1;
        int top=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(tot==0)
            {
                tot=1;
                top=nums[i];
            }
            else if(top!=nums[i])
                tot-=1;
            else
                tot+=1;
        }
        return top;
    }
};

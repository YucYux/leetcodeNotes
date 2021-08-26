class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=1;
        unordered_set<int> nums_set;
        for(int i=0;i<nums.size();i++)
            nums_set.insert(nums[i]);
        for(const int & num : nums_set)
        {
            if(nums_set.find(num-1)!=nums_set.end()) continue;
            int temp=1;
            while(nums_set.find(num+temp)!=nums_set.end())
            {
                temp++;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};

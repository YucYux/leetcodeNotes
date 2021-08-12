class Solution {
public:
    int threeSumClosest(vector<int>& raw, int target) {
        int ans=0x7fffffff;
        int dis=0x7fffffff;
        vector<int> nums=raw;
        sort(nums.begin(),nums.end());
        int tempSum=0;
        int lastP0=0x7fffffff;
        int lastP1=0x7fffffff;
        int lastP2=0x7fffffff;
        int p1=0;
        int p2=0;
        int end=(int)nums.size()-2;
        for(int i=0;i<end;i++)
        {
            if(nums[i]==lastP0) //repeat check
                continue;
            else
                lastP0=nums[i];
            p1=i+1;
            p2=nums.size()-1;
            lastP1=0x7fffffff;
            lastP2=0x7fffffff;
            while(p1<p2)
            {
                if(nums[p1]==lastP1)    //repeat check
                {
                    p1++;
                    continue;
                }
                if(nums[p2]==lastP2)
                {
                    p2--;
                    continue;
                }
                tempSum=nums[i]+nums[p1]+nums[p2];
                if(tempSum==target)
                {
                    return target;
                }
                else if(tempSum<target)
                {
                    if(target-tempSum<dis)
                    {
                        dis=target-tempSum;
                        ans=tempSum;
                    }
                    lastP1=nums[p1];
                    p1++;
                }
                else   
                {
                    if(tempSum-target<dis)
                    {
                        dis=tempSum-target;
                        ans=tempSum;
                    }
                    lastP2=nums[p2];
                    p2--;
                }
            }
        }
        return ans;
    }
    int Min(int a,int b)
    {
        return a<b ? a : b;
    }
};

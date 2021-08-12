class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& raw) {
        vector<vector<int>> ans;
        vector<int> nums=raw;
        vector<int> oneOfAns;
        oneOfAns.push_back(0);
        oneOfAns.push_back(0);
        oneOfAns.push_back(0);
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
                if(tempSum==0)
                {
                    oneOfAns[0]=(nums[i]);
                    oneOfAns[1]=(nums[p1]);
                    oneOfAns[2]=(nums[p2]);
                    ans.push_back(oneOfAns);
                    lastP1=nums[p1];
                    p1++;
                    lastP2=nums[p2];
                    p2--;
                }
                else if(tempSum<0)
                {
                    lastP1=nums[p1];
                    p1++;
                }
                else   
                {
                    lastP2=nums[p2];
                    p2--;
                }
            }
        }
        return ans;
    }
};

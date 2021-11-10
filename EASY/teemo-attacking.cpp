class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0) return 0;
        else if(timeSeries.size()==1) return duration;
        int ans=0;
        for(int i=0;i<timeSeries.size();i++)
        {
            if(i==timeSeries.size()-1)
                ans+=duration;
            else
            {
                if(timeSeries[i+1]-timeSeries[i]<duration)
                    ans+=(timeSeries[i+1]-timeSeries[i]);
                else
                    ans+=duration;
            }
        }
        return ans;
    }
};

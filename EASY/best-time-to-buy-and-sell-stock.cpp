class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int* rightMax=new int[prices.size()];
        rightMax[prices.size()-1]=prices[prices.size()-1];    //[->
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(prices[i]>=rightMax[i+1])
                rightMax[i]=prices[i];
            else
            {
                rightMax[i]=rightMax[i+1];
                if(rightMax[i]-prices[i]>max)
                    max=rightMax[i]-prices[i];
            }
        }
        return max;
    }
};

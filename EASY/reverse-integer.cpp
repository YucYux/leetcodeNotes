class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        if(x==(1<<31)) return 0;
        int MAX_INT=0x7fffffff;
        bool minus=0;
        if(x<0)
        {
            minus=1;
            x=-x;
        }
        int digit=0;
        int x_=x;
        while(x_>0)
        {
            x_/=10;
            digit++;
        }
        int ans=0;
        for(int i=0;i<digit-1;i++)
        {
            ans=ans*10+x%10;
            x/=10;
        }
        if(ans>MAX_INT/10) return 0;
        ans=ans*10+x%10;
        if(minus) return -ans;
        return ans;
    }
};

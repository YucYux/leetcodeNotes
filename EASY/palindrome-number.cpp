class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        else if(x<10) return 1;
        int x_=x;
        int y=0;
        int MAX_INT=0x7fffffff;
        MAX_INT/=10;
        while(x_>0)
        {
            if(y>MAX_INT) 
                return 0;
            else
                y=y*10+x_%10;
            x_/=10;
        }
        if(x==y) return 1;
        else return 0;
    }
};

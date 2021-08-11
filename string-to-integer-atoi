class Solution {
public:
    int myAtoi(string s) {
        int start=s.length();
        int MAX_INT=0x7fffffff;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ') 
            {
                start=i;
                break;
            }
        }
        if(start==s.length()) return 0;
        bool minus=0;
        if(s[start]=='-') 
        {
            minus=1;
            start++;
        }
        else if(s[start]=='+') 
            start++;
        int ans=0;
        for(int i=start;i<s.length();i++)
        {
            if(s[i]>'9'||s[i]<'0')
                break;
            if(ans>MAX_INT/10)
                return minus ? (1<<31):0x7fffffff;
            else if(ans==MAX_INT/10)
            {
                if((s[i]-'0')<=7)
                        ans=ans*10+(s[i]-'0');
                else
                    return minus ? (1<<31):0x7fffffff;
            }
            else
                ans=ans*10+(s[i]-'0');
        }
        if(minus) return -ans;
        return ans;
    }
};

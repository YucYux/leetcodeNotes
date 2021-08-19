class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<bool,int>> a;
        if(s[0]=='(') 
            a.push(make_pair(0,0));
        else a.push(make_pair(1,0));
        for(int i=1;i<s.length();i++)
            if((!a.empty())&&a.top().first==0&&s[i]==')')
                a.pop();
            else
            {
                if(s[i]=='(')
                {
                    a.push(make_pair(0,i));
                }
                else a.push(make_pair(1,i));
            }
        
        if(a.empty()) return s.length();
        int maxi=s.length()-1-a.top().second;
        while(1)
        {
            int temp=a.top().second;
            a.pop();
            if(a.empty())
            {
                maxi=max(maxi,temp-0);
                break;
            }
            else
                maxi=max(maxi,temp-a.top().second-1);
        }
        return maxi;
    }
};

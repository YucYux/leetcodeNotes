class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.length();i++)
        {
            if(sta.empty())
                sta.push(s[i]);
            else if(sta.top()=='('&&s[i]==')')
                sta.pop();
            else if(sta.top()=='['&&s[i]==']')
                sta.pop();
            else if(sta.top()=='{'&&s[i]=='}')
                sta.pop();
            else
                sta.push(s[i]);
        }
        if(sta.empty()) return 1;
        else return 0;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int * dic = new int[52];
        memset(dic,0,52*4);
        string ans="";
        bool firstAns=0;
        for(int i=0;i<t.length();i++)
            if(t[i]>='a')
                dic[t[i]-'a'+26]--;
            else
                dic[t[i]-'A']--;
        int st=0;
        int e=0;
        if(s[0]>='a')
            dic[s[0]-'a'+26]++;
        else
            dic[s[0]-'A']++;
        while(e<s.length())
        {
            bool enough=1;
            for(int i=0;i<52;i++)
                if(dic[i]<0)
                {
                    enough=0;
                    break;
                }
            if(!enough)
            {
                if(e==s.length()-1) break;
                e++;
                if(s[e]>='a')
                    dic[s[e]-'a'+26]++;
                else
                    dic[s[e]-'A']++;
                continue;
            }
            else
            {
                if(firstAns==0||e-st+1<ans.length())
                {
                    firstAns=1;
                    ans=s.substr(st,e-st+1);
                }
                if(s[st]>='a')
                    dic[s[st]-'a'+26]--;
                else
                    dic[s[st]-'A']--;
                st++;
            }
        }
        return ans;
    }
};

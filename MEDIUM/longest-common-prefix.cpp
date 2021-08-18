class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength=0x7fffffff;
        for(int i=0;i<strs.size();i++)
            if(minLength>strs[i].length())
                minLength=strs[i].length();
        int ans=0;
        for(ans=0;ans<minLength;ans++)
        {
            bool allSame=1;
            for(int i=1;i<strs.size();i++)
                if(strs[i][ans]!=strs[i-1][ans])
                    allSame=0;
            if(!allSame)
                break;
        }
        return strs[0].substr(0,ans);
    }
};

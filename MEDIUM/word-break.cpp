class Solution {
public:
    int size=0;
    string * words;
    string target;
    bool* vis;
    bool* val;
    bool wordBreak(string s, vector<string>& wordDict) {
        words=&wordDict[0];
        target=s;
        size=wordDict.size();
        vis=new bool[target.length()+1];
        memset(vis,0,target.length()+1);
        val=new bool[target.length()+1];
        memset(val,0,target.length()+1);
        return check(0);
    }
    bool check(int st)
    {
        if(vis[st]) return val[st];
        vis[st]=1;
        if(st==target.length())
        {
            val[st]=1;
            return 1;
        }
        for(int i=0;i<size;i++)
        {
            if(target.length()-st>=words[i].length()&&target.substr(st,words[i].length()).compare(words[i])==0)
            {
                if(check(st+words[i].length()))
                {
                    val[st]=1;
                    return 1;
                    break;
                }
            }
        }
        val[st]=0;
        return 0;
    }
};

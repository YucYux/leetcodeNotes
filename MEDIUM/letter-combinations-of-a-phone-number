class Solution {
public:
    vector<string> ans;
    int length;
    string raw;
    string board[10]=
        {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
    vector<string> letterCombinations(string digits) {
        length=digits.length();
        if(length==0) return ans;
        raw=digits;
        find("");
        return ans;
    }
    void find(string tempAns)
    {
        if(tempAns.length()==length)
        {
            ans.push_back(tempAns);
            return;
        } 
        for(int i=0;i<board[raw[tempAns.length()]-'0'].length();i++)
        {
            find(tempAns+board[raw[tempAns.length()]-'0'][i]);
        } 
    }
};

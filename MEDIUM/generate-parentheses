class Solution {
public:
    vector<string> ans;
    string temp;
    int n;
    vector<string> generateParenthesis(int n_) {
        n=n_;
        temp="";
        func(0,0);
        return ans;
    }
    void func(int left,int right)
    {
        if(right==n) 
        {
            ans.push_back(temp);
            return;
        }
        if(left>right)
        {   
            temp+=")";
            func(left,right+1);
            temp.erase(left+right,1);
        }
        if(left<n)
        {
            temp+="(";
            func(left+1,right);
            temp.erase(left+right,1);
        }
    }
};

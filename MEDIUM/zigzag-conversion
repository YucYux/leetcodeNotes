class Solution {
public:
    string convert(string s, int numRows) {
        int length=s.length();
        if(numRows==1) return s;
        int topPoint=(length-1)/(2*numRows-2)+1;
        string ans="";
        for(int i=0;i<topPoint;i++)
            ans+=s[i*(2*numRows-2)];
        int row=1;
        while(row<numRows-1)
        {
            if(length>row)
                ans+=s[row];
            for(int i=1;i<=topPoint;i++)
            {
                if(i*(2*numRows-2)-row<length)
                    ans+=s[i*(2*numRows-2)-row];
                if(i*(2*numRows-2)+row<length)
                    ans+=s[i*(2*numRows-2)+row];
            }
            row++;
        }
        for(int i=0;i<topPoint;i++)
            if(i*(2*numRows-2)+numRows-1<length)
                ans+=s[i*(2*numRows-2)+numRows-1];
        return ans;
    }
};

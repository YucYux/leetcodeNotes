class Solution {
public:
    string getHint(string secret, string guess) {
        int Bulls = 0;
        int Cows = 0;
        int numbersS[10];
        int numbersG[10];
        memset(numbersS, 0, 40);
        memset(numbersG, 0, 40);
        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
                Bulls++;
            numbersS[secret[i] - '0']++;
            numbersG[guess[i] - '0']++;
        }
        for(int i = 0; i < 10; i++)
        {
            Cows += getmin(numbersG[i], numbersS[i]); 
        }
        return to_string(Bulls)+"A"+to_string(Cows-Bulls)+"B";
    }
    int getmin(int a, int b)
    {
        if(a < b) return a;
        return b;
    }
};

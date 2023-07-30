class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        string ans = "";
        int i = 0;
        for(; i < s.size()-1; i++)
        {
            if(s[i] != s[i+1])
            {
                ans.push_back(s[i]);
            }
        }
        ans.push_back(s[i]);
        return ans;
        
    }
};

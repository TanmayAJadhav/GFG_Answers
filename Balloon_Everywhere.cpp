int maxInstance(string s){
        string b = "balon";
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); ++i)
        {
            mp[s[i]]++;
        }
        int ans = INT_MAX;
        for(int i = 0; i < b.size(); ++i)
        {
            if(b[i] =='l' || b[i]=='o' )
            {
                ans = min(ans,mp[b[i]]/2);
            }
            else
            {
                ans = min(ans,mp[b[i]]);
            }
        }
        return ans;
    }
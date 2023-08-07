class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t=="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ")
        {
            return t;
        }
        map<char,long long>mp1;
        map<char,long long>mp2;
        for(auto c:t)
        {
            mp2[c]++;
        }    
        string ans = "";
        int i = -1, j = -1; 
        int matchcnt = 0, reqmtch = t.size();
        while(true)
        {
            bool f1 = false;
            bool f2 = false;

            while((i < (int)s.size()) && (matchcnt < reqmtch))
            {
                i++;
                mp1[s[i]]++;
                if(mp1[s[i]] <= mp2[s[i]])
                {
                    matchcnt++;
                }
                f1 = true;
            }


            while(j < i && matchcnt == reqmtch)
            {
                string temp = s.substr(j+1,i-j);
                j++;
                if(ans.size()==0 || ans.size() > temp.size())
                {
                    ans = temp;
                }
                if(mp1[s[j]] == 1)
                {
                    mp1.erase(s[j]);
                }
                else
                {
                    mp1[s[j]]--;
                }

                if(mp1[s[j]] < mp2[s[j]])
                {
                    matchcnt--;
                }
                f2 = true;
            }

            if(f1 == false && f2 == false)
            {
                break;
            }
        }

        return ans;
    }
};
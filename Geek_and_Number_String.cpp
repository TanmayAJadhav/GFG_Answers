int minLength(string s, int n) {
        unordered_map<int,int>m;
        for(int i = 1; i <= 8; i += 2)
        {
            m[i] = i+1;
            m[i+1] = i;
        }
        m[9] = 0;
        m[0] = 9;
        
        stack<int>st;
        for(char ch : s)
        {
            if(!st.empty() && m[st.top()] == ch -'0')
            {
                st.pop();
            }
            else
            {
                st.push(ch-'0');
            }
        }
        return st.size();
    }
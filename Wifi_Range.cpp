class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            if(S[i] == '1')
            {
                cnt = X;
            }
            else
            {
                cnt--;
            }
            if(cnt < (-(X)))
            {
                return false;
            }
        }
        if(cnt < 0)
        {
            return 0;
        }
        return 1;
    }
};
int buyMaximumProducts(int n, int k, int price[]){
        
        vector<pair<int,int>>vp(n);
        
        for(int i = 0; i < n; ++i)
        {
            vp[i] = {price[i],i+1};
        }
        
        sort(vp.begin(),vp.end());
        
        int total = 0, ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if((total + vp[i].first*vp[i].second) > k)
            {
                ans += (k-total)/vp[i].first;
                break;
                
            }
            else
            {
                total += vp[i].first*vp[i].second;
                ans += vp[i].second;
            }
        }
        return ans;
    }
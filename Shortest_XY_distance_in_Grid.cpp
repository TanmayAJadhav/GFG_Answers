class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(N,vector<bool>(M,false));
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j] == 'X')
                {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
            
        int ans = 0;
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;
            
            if(grid[x][y] == 'Y')
            {
                ans = dist;
                break;
            }
            
            for(int i = 0; i < 4; i++)
            {
                int n = x+row[i];
                int m = y+col[i];
                
                if(m>=0 && n>=0 && m < M && n < N && !vis[n][m])
                {
                    q.push({{n,m},dist+1});
                    vis[n][m] = true;
                }
            }
        }
        return ans;
    }
};
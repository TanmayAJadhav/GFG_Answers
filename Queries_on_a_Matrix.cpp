vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < Queries.size(); ++i)
    {
        int leftrow = Queries[i][0], leftcol = Queries[i][1], botrow = Queries[i][2], botcol = Queries[i][3];

        for (int j = leftrow; j <= botrow; ++j)
        {
            for (int k = leftcol; k <= botcol; ++k)
            {
                ans[j][k]++;
            }
        }
    }

    return ans;
}
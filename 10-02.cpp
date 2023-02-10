class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 0));
        // queue<pair<int,int>>q;
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = -1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int ans = -1;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int step = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 and nc >= 0 and nr < n and nc < n and grid[nr][nc] == 0)
                {
                    grid[nr][nc] = -1;
                    q.push({{nr, nc}, step + 1});
                }
            }
            if (step > 0)
                ans = max(ans, step);
        }
        return ans;
    }
};
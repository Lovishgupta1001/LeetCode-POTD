// Q-980 https://leetcode.com/problems/unique-paths-iii/
class Solution
{
public:
    int f(int r, int c, vector<vector<int>> &grid)
    {
        int rs = grid.size();
        int cs = grid[0].size();

        if (r < 0 || r >= rs || c < 0 or c >= cs or grid[r][c] == -1)
            return 0;

        if (grid[r][c] == 2)
        {
            for (int i = 0; i < rs; i++)
            {
                for (int j = 0; j < cs; j++)
                {
                    if (grid[i][j] == 0)
                        return 0;
                }
            }
            return 1;
        }
        grid[r][c] = -1;

        int lt = f(r, c - 1, grid);
        int rt = f(r, c + 1, grid);
        int tp = f(r - 1, c, grid);
        int bt = f(r + 1, c, grid);

        grid[r][c] = 0;

        return lt + rt + tp + bt;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int rs = grid.size();
        int cs = grid[0].size();
        int r = 0, c = 0;
        for (int i = 0; i < rs; i++)
        {
            for (int j = 0; j < cs; j++)
            {
                if (grid[i][j] == 1)
                    r = i, c = j;
            }
        }
        return f(r, c, grid);
    }
};
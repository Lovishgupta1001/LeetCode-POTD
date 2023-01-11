// Q-1443 https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
class Solution
{
public:
    vector<vector<int>> adjls;
    int dfs(vector<bool> &hasApple, int curr, int d, int prev)
    {

        int res = 0, temp;
        for (auto &it : adjls[curr])
        {
            if (it != prev)
            {
                temp = dfs(hasApple, it, d + 1, curr);
                if (temp)
                    res += temp - d;
            }
        }
        return res || hasApple[curr] ? res + d : 0;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        adjls.resize(n);
        for (auto &it : edges)
        {
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        return dfs(hasApple, 0, 0, -1) * 2;
    }
};
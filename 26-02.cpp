class Solution
{
public:
    int ans(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        int m = s.size(), n = t.size();
        if (j == n)
            return m - i;
        if (i == m)
            return n - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        int val;
        if (s[i] == t[j])
        {
            val = ans(s, t, i + 1, j + 1, dp);
        }
        else
        {
            val = 1 + min({ans(s, t, i + 1, j, dp), ans(s, t, i, j + 1, dp), ans(s, t, i + 1, j + 1, dp)});
        }
        return dp[i][j] = val;
    }

    int minDistance(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return ans(s, t, 0, 0, dp);
    }
};
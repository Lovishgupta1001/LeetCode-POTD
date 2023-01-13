// Q-2246 https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
class Solution
{
    // to store the ans.
    int ans = 1;
    vector<vector<int>> adjlist;

    int dfs(int node, int parent, string &s)
    {
        int maxpath = 1;

        for (auto x : adjlist[node])
        {
            if (x != parent)
            {
                int temp = dfs(x, node, s);

                if (s[node] != s[x])
                {

                    ans = max(ans, maxpath + temp);
                    maxpath = max(maxpath, 1 + temp);
                }
            }
        }
        return maxpath;
    }

public:
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        adjlist.resize(n);

        for (int i = 1; i < n; i++)
        {
            adjlist[parent[i]].push_back(i);
            adjlist[i].push_back(parent[i]);
        }
        dfs(0, -1, s);
        return ans;
    }
};
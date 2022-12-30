// Q-797 https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> v;

    void dfs(int i, vector<vector<int>> &graph)
    {
        v.push_back(i);
        if (i == graph.size() - 1)
        {
            ans.push_back(v);
        }
        else
        {
            for (int it : graph[i])
            {
                dfs(it, graph);
            }
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(0, graph);
        return ans;
    }
};
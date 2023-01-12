// Q-1519 https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
class Solution
{
public:
    vector<vector<int>> adjls;
    vector<int> ans;

    vector<int> dfs(string &labels, int curr, int parent)
    {
        vector<int> count(26, 0);
        for (auto it : adjls[curr])
        {
            if (it != parent)
            {
                auto temp = dfs(labels, it, curr);

                for (int i = 0; i < 26; i++)
                    count[i] += temp[i];
            }
        }
        int ch = labels[curr] - 'a';
        count[ch]++;
        ans[curr] = count[ch];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        adjls.resize(n);
        ans.resize(n, 0);
        for (auto it : edges)
        {
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        dfs(labels, 0, -1);
        return ans;
    }
};
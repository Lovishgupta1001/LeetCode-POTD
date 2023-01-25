// Q-2359 https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
class Solution
{
public:
    void dfs(int n, vector<int> &d, int c, vector<int> &edges)
    {
        if (d[n] != -1)
            return;
        d[n] = c;
        int adj = edges[n];
        if (adj == -1)
            return;
        dfs(adj, d, c + 1, edges);
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dis1(n, -1), dis2(n, -1);
        int c1 = 0, c2 = 0;
        dfs(node1, dis1, c1, edges);
        dfs(node2, dis2, c2, edges);
        int len = 1e9, ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (dis1[i] != -1 and dis2[i] != -1)
            {
                int d = max(dis1[i], dis2[i]);
                if (d < len)
                {
                    len = d;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
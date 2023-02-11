class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red, vector<vector<int>> &blue)
    {
        vector<vector<pair<int, int>>> a(n);
        // 0->red edge and 1->blue edge
        for (auto x : red)
            a[x[0]].push_back({x[1], 0});
        for (auto y : blue)
            a[y[0]].push_back({y[1], 1});

        queue<vector<int>> q;
        q.push({0, 0, -1}); // node,dist,edge_color

        vector<int> ans(n, -1);

        while (!q.empty())
        {

            auto it = q.front();
            int node = it[0];
            int dist = it[1];
            int color = it[2];
            q.pop();

            if (ans[node] == -1)
                ans[node] = dist;
            for (auto &x : a[node])
            {
                if (x.first != -1 and color != x.second)
                {
                    q.push({x.first, dist + 1, x.second});
                    x.first = -1;
                }
            }
        }
        return ans;
    }
};
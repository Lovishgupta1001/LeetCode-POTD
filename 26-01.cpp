// Q-787 https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        if (src == dst)
            return 0;

        vector<pair<int, int>> adj[n];
        for (auto i : flights)
        {
            int s = i[0], e = i[1], d = i[2];
            adj[s].push_back({e, d});
        }

        int dist = INT_MAX;

        queue<vector<int>> q;
        q.push({0, src, -1});

        vector<int> weight(n, INT_MAX);
        weight[src] = {0};

        while (!q.empty())
        {
            vector<int> top = q.front();
            q.pop();

            int s = top[1], d = top[0], stop = top[2];
            if (s == dst)
            {
                dist = min(dist, d);
            }

            for (auto i : adj[s])
            {
                int e = i.first, w1 = i.second;
                if (stop + 1 <= k && weight[e] > d + w1)
                {
                    weight[e] = d + w1;
                    q.push({d + w1, e, stop + 1});
                }
            }
        }
        if (dist == INT_MAX)
            return -1;
        return dist;
    }
};
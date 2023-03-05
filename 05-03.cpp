class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> vis(n, 0);
        vis[0] = 1;

        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int indx = it.first;
            int step = it.second;

            if (indx == n - 1)
                return step;

            if (indx + 1 < n and vis[indx + 1] == 0)
            {
                vis[indx + 1] = 1;
                q.push({indx + 1, step + 1});
            }
            if (indx - 1 >= 0 and vis[indx - 1] == 0)
            {
                vis[indx - 1] = 1;
                q.push({indx - 1, step + 1});
            }
            for (auto i : mp[arr[indx]])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push({i, step + 1});
                }
            }
            mp.erase(arr[indx]);
        }
        return -1;
    }
};
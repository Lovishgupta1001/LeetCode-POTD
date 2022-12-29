// Q-1834 https://leetcode.com/problems/single-threaded-cpu/
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        long long t = tasks[0][0];

        vector<int> ans;
        while (!pq.empty() || i < n)
        {
            while (i < n && t >= tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if (pq.empty())
            {
                t = tasks[i][0];
            }

            else
            {
                auto topp = pq.top();
                pq.pop();
                ans.push_back(topp.second);
                t += topp.first;
            }
        }

        return ans;
    }
};
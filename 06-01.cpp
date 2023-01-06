// Q-1833 https://leetcode.com/problems/maximum-ice-cream-bars/
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int c = 0;
        int n = costs.size();
        for (int i = 0; i < n; i++)
        {
            if (coins >= costs[i])
            {
                coins -= costs[i];
                c++;
            }
        }
        return c;
    }
};
// Q-2279 https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
class Solution
{
public:
    int maximumBags(vector<int> &cap, vector<int> &roc, int ar)
    {
        vector<int> v;
        int n = cap.size();
        for (auto i = 0; i < n; i++)
        {
            v.push_back(cap[i] - roc[i]);
        }
        sort(v.begin(), v.end());
        int c = 0;
        for (auto it : v)
        {
            if (ar >= it)
            {
                ar -= it;
                c++;
            }
        }
        return c;
    }
};
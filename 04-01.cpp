// Q-2244 https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> mp;
        for (auto it : tasks)
        {
            mp[it]++;
        }
        int count = 0;
        for (auto it : mp)
        {
            if (it.second == 1)
                return -1;
            if (it.second % 3 == 2 or it.second % 3 == 1)
            {
                count += it.second / 3;
                count += 1;
            }
            if (it.second % 3 == 0)
            {
                count += it.second / 3;
            }
        }
        return count;
    }
};
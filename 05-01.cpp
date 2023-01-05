// Q-452 https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int arrow = 1;
        int last = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (last < points[i][0])
            {
                arrow++;
                last = points[i][1];
            }
        }
        return arrow;
    }
};
// Q-944 https://leetcode.com/problems/delete-columns-to-make-sorted/
class Solution
{
public:
    int minDeletionSize(vector<string> &nums)
    {
        int n = nums.size();
        int c = 0;
        int flag = 1;
        for (int j = 0; j < nums[0].size(); j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (nums[i][j] < nums[i - 1][j])
                    flag = 0;
            }
            if (flag == 0)
            {
                c++;
                flag = 1;
            }
        }
        return c;
    }
};
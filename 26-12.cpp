// Q-55 https://leetcode.com/problems/jump-game/
class Solution
{
public:
    int dp[10005];
    bool f(int i, vector<int> &nums)
    {
        if (i >= size(nums))
            return false;
        if (i == size(nums) - 1)
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool ans = false;
        for (int k = 1; k <= nums[i]; k++)
        {
            bool temp = f(i + k, nums);
            if (temp == true)
                return true;
        }
        return dp[i] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return f(0, nums);
    }
};
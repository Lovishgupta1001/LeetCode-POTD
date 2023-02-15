class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &nums, int k)
    {
        int n = nums.size();
        int c = 0;
        int i = n - 1;

        vector<int> ans;

        while (i >= 0 || k != 0 || c > 0)
        {
            if (k != 0)
            {
                c += k % 10;
                k /= 10;
            }
            if (i >= 0)
            {
                c += nums[i];
                i--;
            }
            ans.push_back(c % 10);
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
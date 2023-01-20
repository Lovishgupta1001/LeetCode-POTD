// Q-491 n-decreasing-subsequences/
class Solution
{
public:
    map<vector<int>, int> mpp;
    void f(int ind, int n, vector<int> &nums, vector<int> &v, vector<vector<int>> &ans)
    {
        if (v.size() >= 2)
        {
            mpp[v]++;
            if (mpp[v] > 1)
                return;
            ans.push_back(v);
        }
        if (ind > nums.size())
            return;

        for (int i = ind; i < n; i++)
        {
            if (v.size() >= 1)
            {
                if (nums[i] < v[v.size() - 1])
                    continue;
            }
            v.push_back(nums[i]);
            f(i + 1, n, nums, v, ans);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> v;
        f(0, n, nums, v, ans);
        return ans;
    }
};
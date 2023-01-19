// Q-974 https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size(), c = 0, sum = 0, val = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            val = sum % k;
            if (val < 0)
                val += k;
            if (mp.find(val) != mp.end())
                c += mp[val];
            mp[val]++;
        }
        return c;
    }
};
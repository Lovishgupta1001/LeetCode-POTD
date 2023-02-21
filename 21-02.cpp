class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // int ans=0;
        // for(auto it:nums)
        //     ans=ans^it;
        // return ans;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int i = 0, j = n - 1, mid, ans;
        while (i < j)
        {
            mid = i + (j - i) / 2;
            ans = (mid % 2 == 0) ? mid + 1 : mid - 1;
            if (nums[mid] == nums[ans])
                i = mid + 1;
            else
                j = mid;
        }
        return nums[i];
    }
};
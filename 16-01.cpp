// Q-57 https://leetcode.com/problems/insert-interval/
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &iv, vector<int> &niv)
    {

        iv.push_back(niv);

        sort(iv.begin(), iv.end());
        int n = iv.size();

        vector<vector<int>> ans;

        ans.push_back(iv[0]);
        int j = 0;

        for (int i = 1; i < n; i++)
        {

            int st = ans[j][0];
            int end = ans[j][1];

            if (iv[i][0] <= end)
                ans[j][1] = max(end, iv[i][1]);
            else
            {
                ans.push_back({iv[i][0], iv[i][1]});
                j++;
            }
        }
        return ans;
    }
};

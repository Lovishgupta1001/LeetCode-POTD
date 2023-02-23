class Solution
{
public:
    bool check(vector<int> &w, int mid, int d)
    {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < w.size(); i++)
        {
            if (sum + w[i] <= mid)
                sum += w[i];
            else
            {
                count += 1;
                sum = w[i];
            }
        }
        count++;
        if (count <= d)
            return true;
        return false;
    }
    int shipWithinDays(vector<int> &w, int d)
    {
        int sum = 0;
        int s = 0;
        for (auto it : w)
        {
            sum += it;
            s = max(s, it);
        }
        int n = w.size();
        int e = sum;
        int ans = sum;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (check(w, mid, d))
            {
                e = mid - 1;
                ans = mid;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
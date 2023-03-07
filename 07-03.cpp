#define ll long long
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        ll left = 0, right = totalTrips * (ll)time[0], ans = right;
        while (left < right)
        {
            ll mid = (left + right) / 2;
            ll count = 0;
            for (int i = 0; i < time.size(); i++)
            {
                count += mid / time[i];
            }
            if (count >= totalTrips)
            {
                ans = min(ans, mid);
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
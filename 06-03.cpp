class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        int num = 1;
        int i = 0;
        int ans = 0;
        while (k != 0)
        {
            if (i >= arr.size())
            {
                k--;
                ans = num;
            }
            else if (arr[i] == num and i < arr.size())
            {
                i++;
            }
            else if (arr[i] != num)
            {
                k--;
                ans = num;
            }
            num++;
        }
        return ans;
    }
};
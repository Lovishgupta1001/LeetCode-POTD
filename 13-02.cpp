class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;
        if (low % 2 == 0)
            low++;
        for (int i = low; i <= high; i += 2)
        {
            count++;
        }
        return count;
    }
};